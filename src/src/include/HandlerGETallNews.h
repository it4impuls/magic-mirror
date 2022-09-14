#pragma once
#include <iostream>
#include <restbed>
#include "API.h"


using namespace std;
using namespace restbed;

class HandlerGETallNews {
public:

    static HandlerGETallNews* This;
    API* api;
    HandlerGETallNews(API* _api);

    string tempString;

	static void handleGETallNews(const shared_ptr<Session> &session);

};