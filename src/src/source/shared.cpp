#include <iostream>
#include <string>
#include <fstream>
#include "shared.h"

using namespace std;

string getDataFromFile(const string& filename) {
    fstream newfile;
    string s = "";

    newfile.open(filename,ios::in);
    if (newfile.is_open()){
        string tp;
        while(getline(newfile, tp)){
            s += tp + "\n";
        }
        newfile.close();
    } else {
        cout << "cant open " << filename << endl;
    }

    s.resize(s.length()-1);  // remove the last "\n"

    return s;
}
