#include <fstream>
#include <vector>
#include <string>
#include "StudentFileManger.h"
#include "Util.h"
#include "Global.h"
#include "StudentFormatter.h"

using namespace std;
vector<Student> StudentFileManger::LoadDataFromFile(string filename) {
    vector<Student> allData;
    fstream myFile;
    myFile.open(filename, ios::in);
    if (!myFile.is_open())
        throw runtime_error("Can't open " + filename);
    string line;
    while (getline(myFile, line)) {
        if (line.empty())
            continue;
        vector<string> data = Util::SplitRecord(line);
        if (data.size() < 6)
            throw runtime_error("Wrong Data In " + filename + " file");
        allData.push_back(Student(data[0], data[1], data[2], data[3], data[4], data[5]));
    }
    myFile.close();
    return allData;
}
void StudentFileManger::SaveDataToFile(vector<Student> &allData) {
    fstream myFile;
    myFile.open(STUDENTS_FILE, ios::out);
    if (!myFile.is_open())
        throw runtime_error("Can't open " + STUDENTS_FILE);
    for (const Student& student: allData) {
        string record = StudentFormatter::ConvertObjectToLine(student);
        myFile << record << "\n";
    }
    myFile.close();
}
void StudentFileManger::SaveNewToFile(vector<string> newInfo) {
    fstream myFile;
    myFile.open(STUDENTS_FILE, ios::app);
    if (!myFile.is_open())
        throw runtime_error("Can't Open " + STUDENTS_FILE + " File");
    string newRecord = Util::ConvertVectorDataToLine(newInfo);
    myFile << newRecord << "\n";
    myFile.close();
}
Student* StudentFileManger::Find(string phoneNumber, string password) {
    fstream myFile;
    myFile.open(STUDENTS_FILE, ios::in);
    if (!myFile.is_open())
        throw runtime_error("Error: Could not open " + STUDENTS_FILE);
    string line;
    while (getline(myFile, line)) {
        if (line.empty())
            continue;
        vector<string> info = Util::SplitRecord(line);
        if (info[2] == phoneNumber && info[4] == password) {
            myFile.close();
            return new Student(info[0], info[1], info[2], info[3], info[4], info[5]);
        }
    }
    myFile.close();
    return nullptr;
} 