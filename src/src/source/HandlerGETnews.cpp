#include <iostream>
#include <restbed>
#include <string>
#include <fstream>
#include "API.h"
#include "json.hpp"
#include "HandlerGETnews.h"


using namespace std;
using namespace restbed;
using json = nlohmann::json;

//initialize it to avoid any linker's  errors
HandlerGETnews* HandlerGETnews::This = nullptr;


HandlerGETnews::HandlerGETnews(API* _api) {
        This = this;
        api = _api;
}

string getDataFromFile(const string& filename) {
    fstream newfile;
    string s = "";

    newfile.open(filename,ios::in);
    if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            s += tp + "\n";
        }
        newfile.close();
    } else {
        cout << "cant open " << filename << endl;
    }

    s.resize(s.length()-1);  // remove the last "\n"

    return s;
}


void HandlerGETnews::handleGETnews(const shared_ptr<Session> &session) {

    string news[3];

    news[0] = getDataFromFile("news1.txt");
    news[1] = getDataFromFile("news2.txt");
    news[2] = getDataFromFile("news3.txt");
    string result = "{ \"news1\":\"" + news[0] + "\", \"news2\":\"" + news[1] + "\", \"news3\":\"" + news[2] + "\" }";
    This->api->closeSession(result,session);
}