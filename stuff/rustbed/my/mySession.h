#pragma once
#include <string>
#include <restbed>
#include "BossVerification.h"


using namespace std;
using namespace restbed;



class mySession
{
public:

    
    static void logic(string name){

        
        bool isBoss = BossVerification::verifyParameter(name);
        BossVerification::printHello(isBoss);


    }


    static void get_method_handler1(const shared_ptr< Session > session) {
        
        const auto& request = session->get_request();

//        fprintf(stdout, string(request->get_path_parameter("name")).c_str());
        logic(request->get_query_parameter("name"));

        session->close(OK, "OK", { { "Content-Length", "2" } });

        

        return;
    }
    
    static void get_method_handler2(const shared_ptr< Session > session) {
        session->close(OK, "Hello from Method2", { { "Content-Length", "18" }, { "Connection", "close" } });

        return;
    }


    static void service_ready_handler(Service&) {
        fprintf(stdout, "Hey! The service is up and running.\n");
    }
    
    void setup() {
        auto resource1 = make_shared< Resource >();
        resource1->set_path("/hello/{name: .*}");
        //resource1->set_path("/hello");
        resource1->set_method_handler("GET", get_method_handler1);

        /*
        resource1->set_method_handler("GET", [](const shared_ptr< Session > session) {
            session->close(OK, "LAMBDA", { { "Content-Length", "6" } });
            });
        */
    
        auto resource2 = make_shared< Resource >();
        resource2->set_path("/hello2");
        resource2->set_method_handler("GET", get_method_handler2);
    

        settings = make_shared< Settings >();
        settings->set_port(1984);

        service = make_shared< Service >();
        service->publish(resource1);
        service->publish(resource2);
        service->set_ready_handler(service_ready_handler);

        return;
    }

    shared_ptr<Service> service;
    shared_ptr<Settings> settings;


private:

};
