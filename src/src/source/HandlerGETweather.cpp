#include <iostream>
#include <restbed>
#include <string>
#include "API.h"
#include "json.hpp"
#include "HandlerGETweather.h"


using namespace std;
using namespace restbed;
using json = nlohmann::json;

//initialize it to avoid any linker's  errors
HandlerGETweather* HandlerGETweather::This = nullptr;


HandlerGETweather::HandlerGETweather(API* _api){
        This = this;
        api = _api;
}

template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}


void HandlerGETweather::handleGETweather(const shared_ptr<Session> &session){

        string body = This->api->HTTPrequest("http://api.openweathermap.org/data/2.5/weather?q=Hamburg&lang=de&appid=4e513534d75f33ff1c95d236cc3e6419");

        json data = json::parse(body);

        int id = data["weather"][0]["id"];
        float kelvin = data ["main"]["temp"];

        float celsius = kelvin - 273.15;

        string temperature = to_string_with_precision(celsius,1);


        string result = "{ \"id\":\""+to_string(id)+"\", \"temp\":\""+temperature+"\" }";
        This->api->closeSession(result,session);
}