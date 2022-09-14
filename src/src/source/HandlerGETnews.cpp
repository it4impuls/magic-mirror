#include <iostream>
#include <restbed>
#include <string>
#include <fstream>
#include "API.h"
#include "json.hpp"
#include "shared.h"
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



void HandlerGETnews::handleGETnews(const shared_ptr<Session> &session) {

    string s;

    s = getDataFromFile("news1.txt");

    string result = "{ \"news\":\"" + s + "\" }";
    This->api->closeSession(result,session);
}