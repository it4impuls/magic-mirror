#include <thread>
#include <memory>
#include <chrono>
#include <cstdlib>
#include <restbed>
#include "mainSystem.h"


using namespace std;
using namespace restbed;


int main(const int, const char**){

    MainSystem* theSystem = new MainSystem();

    bool isSystemUp = theSystem->initSystem();
    theSystem->run();

    delete theSystem;
    return 0;
}