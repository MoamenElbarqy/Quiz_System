#pragma once
#include "Global.h"
#include "HeaderScreen.h"
#include "Input.h"
#include "Student.h"
#include "StudnetMainMenu.h"
class StudentLogin : private HeaderScreen
{
private:
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\tStudent Login Screen");

		cout << "PLease Enter You Phone Number : ";
		string student_phone = Input::ReadString();
		cout << "Please Enter Your Password : ";
		string student_password = Input::ReadString();

		Student myStudent = Student::Find(student_phone, student_password);

		if (myStudent.isEmpty())
		{
			cout << "\n=====================================\n";
			cout << " Your Phone or Password is Wrong :-(\n";
			cout << "=====================================\n";
			return;
		}
		SystemUser = &myStudent;
		StudentMainMenu::Show(); // go is student options after login
		SystemUser = nullptr; // Make The User Empty Because The Studnet has Logout
	}
};

