#include <string>
#include <stdio.h>
#include <iostream>
#include <SimpleIni.h>
#include "LoginManager.h"

using namespace std;


LoginManager::LoginManager(){

}

int LoginManager::recogniseLogin(const string& password){

    CSimpleIniA ini;
    ini.SetUnicode();

    SI_Error rc = ini.LoadFile("users.ini");
    if (rc < 0) {
        cout << "INI Load File Error.";
        exit(1);
    };

    const char* uc = ini.GetValue("general", "usercount", "0");

    int userCount = stoi(string(uc));

    for (int i = 1; i <= userCount; i++){
        const char* s = string("user" + to_string(i)).c_str();
        const char* up = ini.GetValue(s, "password", "0");
        if (password == up) return i;
    }

    return -1;
}