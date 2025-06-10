#pragma once
#include "HeaderScreen.h"
class DeleteQuiz :private HeaderScreen
{
private:
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t Delete Quiz Screen ");

		cout << "You Want To Delete Drafed [1] Quiz Or Published Quiz [2] : ";

		int choice = Input::ReadNumberBetween(1, 2);

		cout << "Please Enter Quiz ID You Want To Delete : ";

		string quizID = Input::ReadString();

		switch (choice)
		{
		case 1:
		{
			vector<Quiz> DraftedQuizzes = Quiz::LoadDraftedQuizzes();
			for (auto it = DraftedQuizzes.begin(); it != DraftedQuizzes.end(); it++)
			{
				if (it->getID() == quizID && SystemUser->getFullName() == it->getCreatedBy())
				{
					it->AddToDeleted();
					DraftedQuizzes.erase(it);
					Quiz::LoadDataToDrafted(DraftedQuizzes);
					cout << "\n========================================\n";
					cout << " Quiz Deleted Successfuly :-) \n";
					cout << "========================================\n";
					return;
				}
			}
			cout << "\n==================================================\n";
			cout << " Quiz Not Found In Your Quizzes Dr\\" + SystemUser->getFullName() + "\n";
			cout << "==================================================\n";
			break;
		}

		case 2:
		{
			vector<Quiz> PublishedQuizzes = Quiz::LoadPublishedQuizzes();
			for (auto it = PublishedQuizzes.begin(); it != PublishedQuizzes.end(); it++)
			{
				if (it->getID() == quizID && SystemUser->getFullName() == it->getCreatedBy())
				{
					it->AddToDeleted();
					PublishedQuizzes.erase(it);
					Quiz::LoadDataToPublished(PublishedQuizzes);
					cout << "\n========================================\n";
					cout << " Quiz Deleted Successfuly :-) \n";
					cout << "========================================\n";
					return;
				}
			}
			cout << "\n=====================================================\n";
			cout << " Quiz Not Found In Your Quizzes Dr\\" + SystemUser->getFullName() + "\n";
			cout << "=====================================================\n";
			break;
		}

		}


	}
};

/*
*

*/