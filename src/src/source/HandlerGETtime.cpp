#include <iostream>
#include <restbed>
#include "API.h"
#include "json.hpp"
#include "HandlerGETtime.h"


using namespace std;
using namespace restbed;
using json = nlohmann::json;

//initialize it to avoid any linker's  errors
HandlerGETtime* HandlerGETtime::This = nullptr;


HandlerGETtime::HandlerGETtime(API* _api){
        This = this;
        api = _api;
}


void HandlerGETtime::handleGETtime(const shared_ptr<Session> &session){

        string body = This->api->HTTPrequest("http://worldtimeapi.org/api/timezone/Europe/Berlin");



        json data = json::parse(body);

        This->extractTime(data["datetime"]);
        This->extractDay(data["day_of_week"]);


        string result = "{ \"Time\":\"" + to_string(This->hour) + ":" + to_string(This->minute) + "\","
                          "\"Date\":\"" + to_string(This->day) + "." + to_string(This->month) + "." + to_string(This->year) + "\","
                          "\"Day\":\"" + This->dayname + "\" }";

        This->api->closeSession(result,session);
}


void HandlerGETtime::extractTime(const string& s){
    string time = s.substr(s.find("T")+1,s.find(".")-s.find("T"));

    hour = stoi(time.substr(0,2));
    minute = stoi(time.substr(3,2));

    year = stoi(s.substr(0,4));
    month = stoi(s.substr(6,2));
    day = stoi(s.substr(8,2));
//  cout << hour << ":" << minute << "-" << day << "-" << month << "-" << year << endl;
}


void HandlerGETtime::extractDay(int value){

    switch (value){
        case 1 : dayname = "Montag"; break;
        case 2 : dayname = "Dienstag"; break;
        case 3 : dayname = "Mittwoch"; break;
        case 4 : dayname = "Donnerstag"; break;
        case 5 : dayname = "Freitag"; break;
        case 6 : dayname = "Samstag"; break;
        case 7 : dayname = "Sonntag"; break;
        default: dayname = "Nirvana";
    }

//  cout << dayname << endl;
}