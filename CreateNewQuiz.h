#pragma once
#include "Global.h"
#include "Quiz.h"
#include "HeaderScreen.h"
#include <map>

using namespace std;
class CreateNewQuiz : private HeaderScreen
{
private:
	
public:
	static void Show()
	{
		DrawScreenHeader("\t Create Quiz Screen ");

		Quiz newQuiz = Quiz::ReadQuizInfo();

		if (Util::ContinueOperation("Do You Want To Publish This Quiz To Students (y / n) : "))
		{
			newQuiz.AddToPublished();
			cout << "\n=====================================\n";
			cout << " The Quiz Published Successfuly :-(\n";
			cout << "=====================================\n";
		}
		else if (Util::ContinueOperation("Do You Want To Save This Quiz in Draft (y / n) : "))
		{
			newQuiz.AddToDrafted();
			cout << "\n=====================================\n";
			cout << " The Quiz Drafted Successfuly :-(\n";
			cout << "=====================================\n";
		}
		else
		{
			cout << "\n=====================================\n";
			cout << " The Quiz Denied :-(\n";
			cout << "=====================================\n";
		}
	}
};