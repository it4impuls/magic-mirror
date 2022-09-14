#include <iostream>
#include <restbed>
#include <string>
#include <fstream>
#include "API.h"
#include "json.hpp"
#include "shared.h"
#include "HandlerGETallNews.h"


using namespace std;
using namespace restbed;
using json = nlohmann::json;

//initialize it to avoid any linker's  errors
HandlerGETallNews* HandlerGETallNews::This = nullptr;


HandlerGETallNews::HandlerGETallNews(API* _api) {
        This = this;
        api = _api;
}



void HandlerGETallNews::handleGETallNews(const shared_ptr<Session> &session) {

    string news[3];

    news[0] = getDataFromFile("news1.txt");
    news[1] = getDataFromFile("news2.txt");
    news[2] = getDataFromFile("news3.txt");
    string result = "{ \"news1\":\"" + news[0] + "\", \"news2\":\"" + news[1] + "\", \"news3\":\"" + news[2] + "\" }";
    This->api->closeSession(result,session);
}