#pragma once
#include <vector>
#include "Student.h"

// Responsible for managing student data files: Load, Save, Search

class StudentFileManger {
public:
	static std::vector<Student> LoadDataFromFile(std::string filename);
	static void SaveDataToFile(std::vector<Student> &allData);
	static void SaveNewToFile(std::vector<std::string> newInfo);
	static Student* Find(std::string phoneNumber, std::string password);
};
