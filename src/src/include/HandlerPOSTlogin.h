#pragma once
#include <iostream>
#include <restbed>
#include "API.h"


using namespace std;
using namespace restbed;

class HandlerPOSTlogin {
public:

    static HandlerPOSTlogin* This;
    API* api;
    HandlerPOSTlogin(API* _api);

    string tempString;

    static void handlePOSTlogin(const shared_ptr<Session> &session);

};