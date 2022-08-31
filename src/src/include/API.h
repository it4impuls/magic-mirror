#pragma once
#include <iostream>
#include <restbed>


using namespace std;
using namespace restbed;


class APIInterface {
public:
	virtual void setupSettings(int port) = 0;
	virtual void setupService(const std::function< void(Service&) >& callback) = 0;
	virtual void startService() = 0;

	virtual void publishResource(string operation, string path, const std::function< void(const std::shared_ptr<Session>) >& callback) = 0;

    virtual void closeSession(const string& data, const shared_ptr<Session>& session) = 0;

    virtual string HTTPrequest(const string& uri) = 0;
};


class API: public APIInterface {
public:

	shared_ptr<Settings> settings;
	shared_ptr<Service> service;
    shared_ptr<Request> request;
    shared_ptr<Response> response;

	void setupSettings(int port) override;

	void setupService(const std::function<void(Service&)>& callback) override;

	void startService() override;

    string HTTPrequest(const string& uri) override;

    void closeSession(const string& data, const shared_ptr<Session>& session) override;

	void publishResource(string operation, string path, const std::function< void(const std::shared_ptr<Session>) >& callback) override;
};