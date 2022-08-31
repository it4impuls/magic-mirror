#include <iostream>
#include <restbed>
#include <string>
#include "API.h"

using namespace std;
using namespace restbed;

void API::setupSettings(int const port) {
    cout << "Settings Setup..." << endl;

    settings = make_shared<Settings>();
    settings->set_port(port);
}

void API::setupService(const std::function< void(Service&) >& callback) {
    cout << "Service Setup..." << endl;

    service = make_shared<Service>();
    service->set_ready_handler(callback);
}

void API::startService() {
    cout << "Service Start..." << endl;
    service->start(settings);
}


string API::HTTPrequest(const string& uri) {
    request = make_shared<Request>(Uri(uri));
    request->set_header("Accept", "*/*");
    request->set_header("Host", "www.google.com");

    response = Http::sync(request);

    auto length = response->get_header("Content-Length", 0);

    Http::fetch(length, response);

    string s = reinterpret_cast<char*>(response->get_body().data());
    s.resize (length,'\0');
    return s;
}




void API::publishResource(string operation, string path, const std::function< void(const std::shared_ptr< Session >) >& callback) {
    cout << "publishing Resource by " << operation << " at " << path << endl;

    auto resource = make_shared<Resource>();
    resource->set_path(path);
    resource->set_method_handler(operation, callback);
    service->publish(resource);
}

void API::closeSession(const string& data, const shared_ptr<Session>& session) {
    session->close(OK, data, { { "Content-Length", to_string(data.length()) }, { "Connection", "close" } });
}
