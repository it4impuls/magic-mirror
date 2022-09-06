#include <iostream>
#include "MainSystem.h"
#include "API.h"
#include "HandlerGETtime.h"
#include "HandlerGETweather.h"
#include "HandlerGETnews.h"
#include "HandlerPOSTaddnews.h"
#include "HandlerPOSTlogin.h"


using namespace std;

MainSystem::MainSystem(API* _theAPI) : theAPI(_theAPI) {}
MainSystem::MainSystem() {
    theAPI = new API();
}

bool MainSystem::initSystem() {
    theAPI->setupSettings(1984);
    theAPI->setupService(service_ready_handler);

    _HandlerTime = new HandlerGETtime(theAPI);
    _HandlerWeather = new HandlerGETweather(theAPI);
    _HandlerGETnews = new HandlerGETnews(theAPI);
    _HandlerPOSTaddnews = new HandlerPOSTaddnews(theAPI);
    _HandlerPOSTlogin = new HandlerPOSTlogin(theAPI);

    theAPI->publishResource("GET", "/time", HandlerGETtime::handleGETtime);
    theAPI->publishResource("GET", "/weather", HandlerGETweather::handleGETweather);
    theAPI->publishResource("GET", "/news", HandlerGETnews::handleGETnews);
    theAPI->publishResource("POST", "/addnews", HandlerPOSTaddnews::handlePOSTaddnews);
    theAPI->publishResource("POST", "/login", HandlerPOSTlogin::handlePOSTlogin);

    return true;
}



void MainSystem::run() const {
    theAPI->startService();
}

void MainSystem::service_ready_handler(Service&)
{
    cout << "Hey! The service is up and running." << endl;
}