#pragma once
#include <iostream>
#include "API.h"
#include "HandlerGETtime.h"
#include "HandlerGETweather.h"
#include "HandlerGETallNews.h"
#include "HandlerGETnews.h"
#include "HandlerPOSTaddnews.h"
#include "HandlerPOSTlogin.h"
#include "LoginManager.h"


using namespace std;


class MainSystem{
public:
	API* theAPI;

	HandlerGETtime* _HandlerTime;
    HandlerGETweather* _HandlerWeather;
    HandlerPOSTaddnews* _HandlerPOSTaddnews;
    HandlerGETallNews* _HandlerGETallNews;
    HandlerPOSTlogin* _HandlerPOSTlogin;
    HandlerGETnews* _HandlerGETnews;
    LoginManager* _LoginManager;

	explicit MainSystem(API* _theAPI);
	MainSystem();

	bool initSystem();

	void run() const;
	static void service_ready_handler(Service&);
};