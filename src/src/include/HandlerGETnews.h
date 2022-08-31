#pragma once
#include <iostream>
#include <restbed>
#include "API.h"


using namespace std;
using namespace restbed;

class HandlerGETnews {
public:

    static HandlerGETnews* This;
    API* api;
    HandlerGETnews(API* _api);

    string tempString;

	static void handleGETnews(const shared_ptr<Session> &session);

};