
#include <thread>
#include <memory>
#include <chrono>
#include <cstdlib>
#include <restbed>

using namespace std;
using namespace restbed;

void get_method_handler1(const shared_ptr< Session > session)
{
    const auto& request = session->get_request();

    const string body = "Hello, " + request->get_query_parameter("name");
    session->close(OK, body, { { "Content-Length", ::to_string(body.size()) } });
}

void get_method_handler2(const shared_ptr< Session > session)
{
    session->close(OK, "Hello from Method2", { { "Content-Length", "18" }, { "Connection", "close" } });
}


void service_ready_handler(Service&)
{
    fprintf(stderr, "Hey! The service is up and running.");
}

int main(const int, const char**)
{
    auto resource1 = make_shared< Resource >();
    resource1->set_path("/hello1/{name: .*}");
    resource1->set_method_handler("GET", get_method_handler1);

    auto resource2 = make_shared< Resource >();
    resource2->set_path("/hello2");
    resource2->set_method_handler("GET", get_method_handler2);


    auto settings = make_shared< Settings >();
    settings->set_port(1984);

    auto service = make_shared< Service >();
    service->publish(resource1);
    service->publish(resource2);
    service->set_ready_handler(service_ready_handler);
    service->start(settings);

    return EXIT_SUCCESS;
}









/*
#include <string>
#include <memory>
#include <cstdlib>
#include <restbed>

using namespace std;
using namespace restbed;

void get_method_handler(const shared_ptr< Session > session)
{
    const auto& request = session->get_request();

    const string body = "Hello, " + request->get_path_parameter("name");
    session->close(OK, body, { { "Content-Length", ::to_string(body.size()) } });
}

int main(const int, const char**)
{
    auto resource = make_shared< Resource >();
    resource->set_path("/resource/{name: .*}");
    resource->set_method_handler("GET", get_method_handler);

    auto settings = make_shared< Settings >();
    settings->set_port(1984);
    settings->set_default_header("Connection", "close");

    Service service;
    service.publish(resource);
    service.start(settings);

    return EXIT_SUCCESS;
}
*/


