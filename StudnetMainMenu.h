#pragma once
#include <iomanip>
#include "Input.h"
#include "HeaderScreen.h"
#include "AvailableQuizzes.h"
#include "StartNewQuiz.h"
#include "PreviousResults.h"
#include "ReviewSolvedQuiz.h"
class StudentMainMenu : private HeaderScreen 
{
private:
	enum MenuOptions
	{
		AvailableQuizzes = 1,
		StartNewQuiz = 2,
		ViewPreviousResults = 3,
		ReviewSolvedQuiz = 4,
		Exit = 5
	};
	
	static void BackToStudentMainMenu()
	{
		cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Studnet Main Menue...\n";
		system("pause>0");
		StudentMainMenu::Show();
	}
	static void PerformStudentLoginScreenOptions(MenuOptions option)
	{
		switch (option)
		{
		case MenuOptions::AvailableQuizzes:
			AvailableQuizzes::Show();
			BackToStudentMainMenu();
			break;
		case MenuOptions::StartNewQuiz:
			StartNewQuiz::Show();
			BackToStudentMainMenu();
			break;
		case MenuOptions::ViewPreviousResults:
			PreviousResults::Show();
			BackToStudentMainMenu();
			break;
		case MenuOptions::ReviewSolvedQuiz:
			ReviewSolvedQuiz::Show();
			BackToStudentMainMenu();
			break;
		case MenuOptions::Exit:
			break;
		}
	}
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\tStundet Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tStudent Main Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] View Available Quizzes.\n";
		cout << setw(37) << left << "" << "\t[2] Start New Quiz .\n";
		cout << setw(37) << left << "" << "\t[3] View Previous Results.\n";
		cout << setw(37) << left << "" << "\t[4] Review Solved Quiz.\n";
		cout << setw(37) << left << "" << "\t[5] Exit.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "Choose What Do you Want to Do :";
		PerformStudentLoginScreenOptions(MenuOptions(Input::ReadNumberBetween(1, 5)));
	}
};