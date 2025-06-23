#pragma once
#include <vector>
#include "Teacher.h"


class TeacherFileManager {
public:
    static vector<Teacher> LoadDataFromFile(string filename);

    static void SaveDataToFile(vector<Teacher> &allData);

    static void SaveNewToFile(vector<string> teacherInfo);

    static Teacher *Find(string phoneNumber, string password);
};
