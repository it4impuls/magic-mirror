#pragma once
#include <iostream>
#include <restbed>
#include "API.h"


using namespace std;
using namespace restbed;

class HandlerGETtime {
public:

    int hour;
    int minute;
    int day;
    int month;
    int year;
    string dayname;

    static HandlerGETtime* This;
    API* api;
    HandlerGETtime(API* _api);

	static void handleGETtime(const shared_ptr<Session> &session);

    void extractTime(const string& s);
    void extractDay(int value);
};