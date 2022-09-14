#include <iostream>
#include <restbed>
#include <string>
#include <fstream>
#include "API.h"
#include "json.hpp"
#include "HandlerPOSTaddnews.h"


using namespace std;
using namespace restbed;
using json = nlohmann::json;

//initialize it to avoid any linker's  errors
HandlerPOSTaddnews* HandlerPOSTaddnews::This = nullptr;


HandlerPOSTaddnews::HandlerPOSTaddnews(API* _api) {
        This = this;
        api = _api;
}

string replacePlus2Space(const string& data) {
    string s = data;
    for (int i = 0; i < s.length()-1; i++) {
        if (s[i] == '+') s[i] = ' ';
    }
    return s;
}

void write2file(const string& filename, const string& data) {
    cout << data << endl;
    ofstream theFile(filename);
    theFile << data;
    theFile.close();
}

void HandlerPOSTaddnews::write2files(const string& data) {
    string news[4];


    string s = data;
    string delimiter = "=";
    int i = 0;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        token = token.substr(0,s.find("&"));
        news[i] = replacePlus2Space(token);
        s.erase(0, pos + delimiter.length());
        i++;
    }
    news[i] = replacePlus2Space(s);


    write2file("news1.txt",news[1]);
    write2file("news2.txt",news[2]);
    write2file("news3.txt",news[3]);
}

void HandlerPOSTaddnews::handlePOSTaddnews(const shared_ptr<Session> &session) {

    size_t content_length = 0;
    const auto& request = session->get_request();

    content_length = request->get_header("Content-Length", 0);

    session->fetch(content_length, [request](const shared_ptr<Session> session, const Bytes & body)
    {
        string str = string(reinterpret_cast<const char*>(body.data()));
        str.resize(body.size());
        This->tempString = str;
    });

    This->write2files(This->tempString);

    string result = This->tempString;
    This->api->closeSession(result,session);
}