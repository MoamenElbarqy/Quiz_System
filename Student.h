#pragma once
#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Util.h"
#include "Person.h"
#include "Global.h"

class Student : public Person
{
private:
	string ConvertObjectToLine()
	{
		string delimiter = "#//#";
		string line;
		line += getFirstName() + delimiter;
		line += getLastName() + delimiter;
		line += getPhoneNumber() + delimiter;
		line += getEmail() + delimiter;
		line += getPassword() + delimiter;
		line += getGender();
		return line;
	}

public:
	Student(Mode mode, string firstName, string lastName, string phoneNumber, string email, string password, string gender)
		: Person(mode, firstName, lastName, phoneNumber, email, password, gender)
	{
	}

	static vector<Student> LoadDataFromFile(string filename) {
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

			allData.push_back(Student(ExsistedMode,
				data[0], data[1],
				data[2], data[3],
				data[4], data[5]));
		}
		myFile.close();
		return allData;
	}

	static void SaveDataToFile(vector<Student>& allData) {
		fstream myFile;
		myFile.open(STUDENTS_FILE, ios::out);

		if (!myFile.is_open())
			throw runtime_error("Can't open " + STUDENTS_FILE);

		for (Student student : allData) {
			string record = student.ConvertObjectToLine();
			myFile << record << "\n";
		}
		myFile.close();
	}

	static void SaveNewToFile(vector<string> newInfo) {
		fstream myFile;
		myFile.open(STUDENTS_FILE, ios::app);

		if (!myFile.is_open())
			throw runtime_error("Can't Open " + STUDENTS_FILE + " File");

		string newRecord = Util::ConvertVectorDataToLine(newInfo);
		myFile << newRecord << "\n";
		myFile.close();
	}

	static Student Find(string phoneNumber, string password) {
		fstream myFile;
		myFile.open(STUDENTS_FILE, ios::in);

		if (!myFile.is_open())
			throw runtime_error("Error: Could not open " + STUDENTS_FILE);

		string line;
		while (getline(myFile, line)) {
			if (line.empty())
				continue;

			vector<string> info = Util::SplitRecord(line);
			if (info.size() < 6)
				throw runtime_error("Wrong Data In " + STUDENTS_FILE + " file");

			if (info[2] == phoneNumber && info[4] == password) {
				myFile.close();
				return Student(ExsistedMode, info[0], info[1], info[2], info[3],
					info[4], info[5]);
			}
		}

		myFile.close();
		return Student(EmptyMode, "", "", "", "", "", "");
	}
};