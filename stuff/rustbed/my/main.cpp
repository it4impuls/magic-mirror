
#include <thread>
#include <memory>
#include <chrono>
#include <cstdlib>
#include <restbed>
#include "mySession.h"


using namespace std;
using namespace restbed;


int main(const int, const char**){
   
    mySession* theSession = new mySession();

    theSession->setup();
    theSession->service->start(theSession->settings);

    return EXIT_SUCCESS;
}