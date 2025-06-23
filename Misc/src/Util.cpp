#include <iostream>
#include <string>
#include <vector>
#include "Util.h"

using namespace std;

bool Util::ContinueOperation(string msg) {
    char status = 'n';
    cout << msg;
    cin >> status;
    while (status != 'n' && status != 'N' && status != 'y' && status != 'Y') {
        cout << "Invalid Character, You Have Only Two Options [ Yes = Y , y ] &  [ No = N , n ] : ";
        cin >> status;
    }
    return status == 'y' || status == 'Y';
}

string Util::ConvertVectorDataToLine(vector<string> myData, string delimiter) {
    string line;
    for (string str : myData) {
        line += str + delimiter;
    }
    return line.substr(0, line.length() - delimiter.length());
}

vector<string> Util::SplitRecord(string str, string delimiter) {
    vector<string> result;
    size_t start = 0;
    size_t end = str.find(delimiter);
    while (end != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    result.push_back(str.substr(start));
    return result;
} 