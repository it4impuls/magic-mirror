#pragma once
#include <iostream>
#include <restbed>
#include "API.h"


using namespace std;
using namespace restbed;

class HandlerPOSTaddnews {
public:

    static HandlerPOSTaddnews* This;
    API* api;
    HandlerPOSTaddnews(API* _api);

    string tempString;

	static void handlePOSTaddnews(const shared_ptr<Session> &session);

    void write2files(const string& data);

};