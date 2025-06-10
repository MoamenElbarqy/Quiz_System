#pragma once
#include "HeaderScreen.h"
class PublishQuiz : private HeaderScreen
{

private:
public:
	static void Show()
	{
		system("cls");

		DrawScreenHeader("\t Publish Quiz Screen ");

		cout << "Please Enter Quiz Id You Want To Edit : ";
		string quizID = Input::ReadString();

		vector<Quiz> draftedQuizzes = Quiz::LoadDraftedQuizzes();

		vector<Quiz>::iterator it;
		for (it = draftedQuizzes.begin(); it != draftedQuizzes.end(); it++)
		{
			if (it->getID() == quizID && SystemUser->getFullName() == it->getCreatedBy())
			{
				it->AddToPublished();
				draftedQuizzes.erase(it);
				Quiz::LoadDataToDrafted(draftedQuizzes);
				cout << "\n========================================\n";
				cout << " Quiz Published Sucssesfuly :-) \n";
				cout << "========================================\n";
				return;
			}
		}
		cout << "\n========================================\n";
		cout << " Quiz is not found  :-) \n";
		cout << "========================================\n";

	}
};

