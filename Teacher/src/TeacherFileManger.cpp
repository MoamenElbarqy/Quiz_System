#include <vector>
#include <fstream>
#include "Teacher.h"
#include "Global.h"
#include "TeacherFormatter.h"
#include "TeacherFileManger.h"
#include "Util.h"

using namespace std;

vector<Teacher> TeacherFileManager::LoadDataFromFile(string filename) {
    vector<Teacher> allData;
    fstream myFile(filename, ios::in);

    if (!myFile.is_open())
        throw runtime_error("Can't open " + filename);

    string line;
    while (getline(myFile, line)) {
        if (line.empty()) continue;

        vector<string> data = Util::SplitRecord(line);
        if (data.size() < 6)
            throw runtime_error("Wrong Data In " + filename + " file");

        allData.push_back(Teacher(
            data[0], data[1], data[2], data[3], data[4], data[5]
        ));
    }

    myFile.close();
    return allData;
}

void TeacherFileManager::SaveDataToFile(vector<Teacher> &allData) {
    fstream myFile(TEACHERS_FILE, ios::out);

    if (!myFile.is_open())
        throw runtime_error("Can't open " + TEACHERS_FILE);

    for (const Teacher &teacher: allData) {
        string record = TeacherFormatter::ConvertObjectToLine(teacher);
        myFile << record << "\n";
    }

    myFile.close();
}

void TeacherFileManager::SaveNewToFile(vector<string> teacherInfo) {
    ofstream file(TEACHERS_FILE, ios::app);
    if (file.is_open()) {
        file << teacherInfo[0] << DELIMITER;
        file << teacherInfo[1] << DELIMITER;
        file << teacherInfo[2] << DELIMITER;
        file << teacherInfo[3] << DELIMITER;
        file << teacherInfo[4] << DELIMITER;
        file << teacherInfo[5] << endl;
        file.close();
    }
}

Teacher *TeacherFileManager::Find(string phoneNumber, string password) {
    fstream myFile;
    myFile.open(TEACHERS_FILE, ios::in);

    if (!myFile.is_open())
        throw runtime_error("Error: Could not open " + TEACHERS_FILE);

    string line;
    while (getline(myFile, line)) {
        if (line.empty())
            continue;

        vector<string> info = Util::SplitRecord(line);
        if (info.size() < 6)
            throw runtime_error("Wrong Data In " + TEACHERS_FILE + " file");

        if (info[2] == phoneNumber && info[4] == password) {
            myFile.close();
            return new Teacher(info[0], info[1], info[2], info[3],
                               info[4], info[5]);
        }
    }

    myFile.close();
    return nullptr;
}
