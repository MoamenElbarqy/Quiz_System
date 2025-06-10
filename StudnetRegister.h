#pragma once
#include <vector>
#include "HeaderScreen.h"
#include "Student.h"
class StudnetRegister : private HeaderScreen
{
private:
	static vector<string> ReadStudentInfo()
	{
		vector<string> result;

		cout << "Please Enter This Info :- \n\n";

		cout << "First Name : ";
		string FirstName = Input::ReadString();
		result.push_back(FirstName);

		cout << "Last Name : ";
		string LastName = Input::ReadString();
		result.push_back(LastName);

		cout << "Phone Number : ";
		string PhoneNumber = Input::ReadPhoneNumber();
		result.push_back(PhoneNumber);

		cout << "Email : ";
		string email = Input::ReadEmail();
		result.push_back(email);

		cout << "Password : ";
		string password = Input::ReadString();
		result.push_back(password);

		cout << "Gender (male / female): ";
		string gender = Input::ReadString();
		result.push_back(gender);

		return result;
	}
public:
	static void ShowStudentRegister()
	{
		system("cls");
		DrawScreenHeader("\t Student Register Screen");


		vector<string> studnetInfo = ReadStudentInfo();

		Student newStudent = Student::Find(studnetInfo[2], studnetInfo[4]); // Searching The Studnet in Our Data or Not
		if (!newStudent.isEmpty())
		{
			cout << "\n========================================\n";
			cout << " You Are Already Exisited In Our System :-) \n";
			cout << "========================================\n";
		}
		Student::SaveNewToFile(studnetInfo);
		cout << "\n========================================\n";
		cout << " You Added To Out System Sucsessfuly :-) \n";
		cout << "========================================\n";
	}
};

