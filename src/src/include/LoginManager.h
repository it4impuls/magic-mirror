#pragma once
#include <string>

using namespace std;


class LoginManager {
public:
        LoginManager();

        static int recogniseLogin(const string& password);
};