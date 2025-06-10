#pragma once
#include <iomanip>
#include <iostream>
#include "HeaderScreen.h"
#include "Util.h"
#include "Input.h"
#include "Login.h"
#include "Register.h"
class MainMenu : private HeaderScreen
{
private:
	enum MenuChoices
	{
		Login = 1,
		Register = 2,
		Exit = 3
	};
	
	static void BackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		Show();
	}
	static void PerformMainMenuOptions(MenuChoices choice)
	{
		switch (choice)
		{
		case MainMenu::Login:
			Login::MainLogin();
			BackToMainMenu();
			break;
		case MainMenu::Register:
			Register::MainRegister();
			BackToMainMenu();
			break;
		case MainMenu::Exit:
			break;
		}
	}

public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Login.\n";
		cout << setw(37) << left << "" << "\t[2] Register.\n";
		cout << setw(37) << left << "" << "\t[3] Exit.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do :";
		PerformMainMenuOptions(MenuChoices(Input::ReadNumberBetween(1, 3)));
	}
};