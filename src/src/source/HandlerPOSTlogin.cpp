#include <iostream>
#include <restbed>
#include <string>
#include "API.h"
#include "json.hpp"
#include "HandlerPOSTlogin.h"
#include "LoginManager.h"


using namespace std;
using namespace restbed;
using json = nlohmann::json;

//initialize it to avoid any linker's  errors
HandlerPOSTlogin* HandlerPOSTlogin::This = nullptr;


HandlerPOSTlogin::HandlerPOSTlogin(API* _api) {
    This = this;
    api = _api;
}

void HandlerPOSTlogin::handlePOSTlogin(const shared_ptr<Session> &session) {

    size_t content_length = 0;
    const auto& request = session->get_request();

    content_length = request->get_header("Content-Length", 0);

    session->fetch(content_length, [request](const shared_ptr<Session> session, const Bytes& body)
    {
        string str = string(reinterpret_cast<const char*>(body.data()));
        str.resize(body.size());
        This->tempString = str;
    } );

    string s = This->tempString.substr(This->tempString.find("=") + 1, This->tempString.length());
     int result = LoginManager::recogniseLogin(s);

    This->api->closeSession(to_string(result),session);
}