#pragma once
#include <cstdlib>
#include <string>

using namespace std;

class Logic {
public:

	bool verifyParameter(const string& par) {
		if (par == "Kirill") return true;
		return false;
	}

	bool printHello() {
		printf(string("Hello\n").c_str());
		return true;
	}

};
