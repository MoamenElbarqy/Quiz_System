#pragma once
#include "HeaderScreen.h"
class EditDraftQuiz : private HeaderScreen
{
private:
public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t Edit Drafted Quiz Screen ");

		cout << "Please Enter Quiz Id You Want To Edit : ";
		string quizID = Input::ReadString();


		Quiz myQuiz = Quiz::FindInDrafted(quizID);

		if (myQuiz.isEmpty())
		{
			cout << "\n========================================\n";
			cout << " Quiz Not Found :-) \n";
			cout << "========================================\n";
			return;
		}
		vector<Quiz> draftedQuizzes = Quiz::LoadDraftedQuizzes();

		for (Quiz& cur_quiz : draftedQuizzes)
		{
			if (cur_quiz.getID() == quizID && SystemUser->getFullName() == cur_quiz.getCreatedBy())
			{
				cur_quiz = Quiz::ReadQuizInfo();
				Quiz::LoadDataToDrafted(draftedQuizzes);
				cout << "\n========================================\n";
				cout << " Quiz Edited Successfuly :-) \n";
				cout << "========================================\n";
				return;
			}
		}
		
	}
};