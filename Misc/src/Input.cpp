#include <string>
#include <iostream>
#include <limits>
#include "Input.h"
using namespace std;

bool Input::CheckEmailDomain(const string &str) {
    if (str.length() <= 10)
        return false;
    return str.substr(str.length() - 10) == "@gmail.com";
}

float Input::ReadFloatNumber() {
    float num = 0;
    cin >> num;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> num;
    }
    return num;
}

string Input::ReadString() {
    string str = "";
    getline(cin >> ws, str);
    return str;
}

int Input::ReadNumberBetween(int from, int to) {
    int num = 0;
    cin >> num;
    while (cin.fail() || num < from || num > to) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> num;
    }
    return num;
}

int Input::ReadNumber() {
    int num = 0;
    cin >> num;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> num;
    }
    return num;
}

string Input::ReadEmail() {
    string str = "";
    getline(cin >> ws, str);
    while (!CheckEmailDomain(str)) {
        str = "";
        getline(cin >> ws, str);
    }
    return str;
}

string Input::ReadPhoneNumber() {
    string str = ReadString();
    while (str.length() != 11) {
        str = ReadString();
    }
    return str;
} 