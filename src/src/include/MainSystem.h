#pragma once
#include <iostream>
#include "API.h"
#include "HandlerGETtime.h"
#include "HandlerGETweather.h"
#include "HandlerGETnews.h"
#include "HandlerPOSTaddnews.h"
#include "HandlerPOSTlogin.h"


using namespace std;


class MainSystem{
public:
	API* theAPI;

	HandlerGETtime* _HandlerTime;
    HandlerGETweather* _HandlerWeather;
    HandlerPOSTaddnews* _HandlerPOSTaddnews;
    HandlerGETnews* _HandlerGETnews;
    HandlerPOSTlogin* _HandlerPOSTlogin;

	explicit MainSystem(API* _theAPI);
	MainSystem();

	bool initSystem();

	void run() const;
	static void service_ready_handler(Service&);

};