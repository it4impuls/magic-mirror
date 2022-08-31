#pragma once
#include <iostream>
#include <restbed>
#include "API.h"


using namespace std;
using namespace restbed;

class HandlerGETweather {
public:

    static HandlerGETweather* This;
    API* api;
    HandlerGETweather(API* _api);

	static void handleGETweather(const shared_ptr<Session> &session);

};