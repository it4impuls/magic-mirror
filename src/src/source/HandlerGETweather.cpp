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


string getWaterString(int id) {
    switch (id) {
        case 200 : return "Gewitter mit leichtem Regen";
        case 201 : return "Gewitter mit Regen";
        case 202 : return "Gewitter mit Starkregen";
        case 210 : return "leichtes Gewitter";
        case 211 : return "Gewitter";
        case 212 : return "schweres Gewitter";
        case 221 : return "zackiges Gewitter";
        case 230 : return "Gewitter mit leichtem Nieselregen";
        case 231 : return "Gewitter mit Nieselregen";
        case 232 : return "Gewitter mit starkem Nieselregen";
        case 300 : return "Nieselregen mit leichter Intensität";
        case 301 : return "Nieselregen";
        case 302 : return "starker Nieselregen";
        case 310 : return "leichter Nieselregen";
        case 311 : return "Nieselregen";
        case 312 : return "starker Nieselregen";
        case 313 : return "Regenschauer und Nieselregen";
        case 314 : return "heftiger Regenschauer und Nieselregen";
        case 321 : return "Schauer";
        case 500 : return "leichter Regen";
        case 501 : return "mäßiger Regen";
        case 502 : return "starker Regen";
        case 503 : return "Sehr schwerer Regen";
        case 504 : return "extremer Regen";
        case 511 : return "gefrierender Regen";
        case 520 : return "leichter Schauerregen";
        case 521 : return "Regenschauer";
        case 522 : return "starker Schauerregen";
        case 531 : return "ragged shower rain";
        case 600 : return "leichter Schnee";
        case 601 : return "Schnee";
        case 602 : return "Starker Schneefall";
        case 611 : return "Schneeregen";
        case 612 : return "leichter Schneeregen";
        case 613 : return "Schneeregen";
        case 615 : return "Leichter Regen und Schnee";
        case 616 : return "Regen und Schnee";
        case 620 : return "Leichter Schneeschauer";
        case 621 : return "Schneeregen";
        case 622 : return "Starker Schauerschnee";
        case 701 : return "Nebel";
        case 711 : return "Rauch";
        case 721 : return "Dunst";
        case 731 : return "Sand-/Staubwirbel";
        case 741 : return "Nebel";
        case 751 : return "Sand";
        case 761 : return "Staub";
        case 762 : return "Vulkanasche";
        case 771 : return "Sturmböen";
        case 781 : return "Tornado";
        case 800 : return "klarer Himmel";
        case 801 : return "vereinzelte Wolken: 11-25%";
        case 802 : return "vereinzelte Wolken: 25-50%";
        case 803 : return "aufgelockert bewölkt: 51-84%";
        case 804 : return "bedeckte Wolken: 85-100%";
        default : return "nirvana";
    };
}



void HandlerGETweather::handleGETweather(const shared_ptr<Session> &session){

        string body = This->api->HTTPrequest("http://api.openweathermap.org/data/2.5/weather?q=Hamburg&lang=de&appid=4e513534d75f33ff1c95d236cc3e6419");

        json data = json::parse(body);

        int id = data["weather"][0]["id"];
        float kelvin = data ["main"]["temp"];

        float celsius = kelvin - 273.15;

        string temperature = to_string_with_precision(celsius,1);


        string result = "{ \"id\":\""+to_string(id)+"\", \"temp\":\""+temperature+"\", \"weather\":\""+getWaterString(id)+"\" }";
        This->api->closeSession(result,session);
}