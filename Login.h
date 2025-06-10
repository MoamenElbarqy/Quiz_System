#pragma once
#include <iomanip>
#include "HeaderScreen.h"
#include "Input.h"
#include "StudentLogin.h"
#include "StudnetMainMenu.h"
#include "TeacherLogin.h"
class Login : private HeaderScreen
{
private:
	enum LoginOptions { Student = 1, Teacher = 2, Exit = 3 };
	
	static void BackToMainLoginScreen()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Login Screen...\n";
		system("pause>0");
		MainLogin();
	}
	static void PerformMainLoginOptions(LoginOptions option)
	{
		switch (option)
		{
		case Login::Student:
			StudentLogin::Show();
			BackToMainLoginScreen();
			break;
		case Login::Teacher:
			TeacherLogin::Show();
			BackToMainLoginScreen();
			break;
		case Login::Exit:
			break;
		}
	}
public:
	static void MainLogin()
	{
		system("cls");
		DrawScreenHeader("\t\tLogin Screen");
		
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tLogin Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Login As Student.\n";
		cout << setw(37) << left << "" << "\t[2] Login As Teacher.\n";
		cout << setw(37) << left << "" << "\t[3] Exit.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do :";
		PerformMainLoginOptions(LoginOptions(Input::ReadNumberBetween(1, 3)));
	}
};