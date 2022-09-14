#include <iostream>
#include <restbed>
#include <string>
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

    const auto& request = session->get_request();

    const string num = request->get_path_parameter("num");

    string s;

    s = getDataFromFile("news" + num + ".txt");

    string result = "{ \"news\":\"" + s + "\" }";
    This->api->closeSession(result,session);
}