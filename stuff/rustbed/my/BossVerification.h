#pragma once
#include <cstdlib>
#include <string>

using namespace std;

class BossVerification {
public:


    static bool verifyParameter(const string& par) {
        if (par == "Kirill") return true;
        return false;
    }

    static void printHello(bool isBoss) {
        if (isBoss) 
            doPrint("Hi Boss");
        else 
            doPrint("Hi");
    }

    static void doPrint(const string& s)
    {
        fprintf(stdout, string(s + "\n").c_str());
    }

};