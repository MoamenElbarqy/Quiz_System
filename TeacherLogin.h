#pragma once
#include "HeaderScreen.h"
#include "Input.h"
#include "Teacher.h"
#include "TeacherMainMenu.h"

class TeacherLogin : private HeaderScreen
{
private:
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\tTeacher Login Screen");

		cout << "Please Enter Your Phone Number: ";
		string teacher_phone = Input::ReadString();
		cout << "Please Enter Your Password: ";
		string teacher_password = Input::ReadString();

		Teacher myTeacher = Teacher::Find(teacher_phone, teacher_password);

		if (myTeacher.isEmpty())
		{
			cout << "\n=====================================\n";
			cout << " Your Phone or Password is Wrong :-(\n";
			cout << "=====================================\n";
			return;
		}
		SystemUser = &myTeacher;
		TeacherMainMenu::Show(); // Go to teacher options after login
		SystemUser = nullptr; // Make The User Empty Because The Teacher has Logout
	}
};
