#pragma once
#include "HeaderScreen.h"
#include "SolvedQuiz.h"
class PreviousResults : private HeaderScreen
{
private:
	static void ShowTableHeader()
	{
		cout << "\t----------------------------------------------------------------------------------------------------------------------\n";
		cout << "\t|    ID    |         Quiz Title         |    Quiz Marks |  Your Score   |   Grade   |  Quiz Status   |  Publisher     \n";
		cout << "\t----------------------------------------------------------------------------------------------------------------------\n";
	}
	static void ShowTableRows(vector<SolvedQuiz>& vec)
	{
		for (SolvedQuiz quiz : vec)
		{
			Quiz QuizInPublished = Quiz::FindInPublished(quiz.getQuizID());
			Quiz QuizInDeleted = Quiz::FindInDeleted(quiz.getQuizID());

			Quiz RealQuiz = QuizInPublished.isEmpty() ? QuizInDeleted : QuizInPublished;


			if (QuizInPublished.isEmpty() && QuizInDeleted.isEmpty())
				throw runtime_error("Invalid Quiz");

			cout << "\t|" << setw(10) << left << quiz.getQuizID();
			cout << "|" << setw(28) << left << RealQuiz.getTitle();
			cout << "|" << setw(15) << left << quiz.getTotalMarks();
			cout << "|" << setw(16) << left << quiz.getScore();
			cout << "|" << setw(11) << left << quiz.getGrade();
			cout << "|" << setw(16) << left << quiz.getResultStatus();
			cout << "|" << setw(16) << left << RealQuiz.getCreatedBy();
			cout << endl;
		}
	}
public:
	static void Show()
	{
		system("cls");

		DrawScreenHeader("\t Previous Results Screen");

		ShowTableHeader();
		vector<SolvedQuiz> AllSolvedQuizzes = SolvedQuiz::LoadSolvedQuizzes();
		vector<SolvedQuiz> studentSolvedQuizzes;

		for (int i = 0; i < AllSolvedQuizzes.size(); i++)
		{
			if (AllSolvedQuizzes[i].getStudentName() == SystemUser->getFullName())
			{
				studentSolvedQuizzes.push_back(AllSolvedQuizzes[i]);
			}
		}
		ShowTableRows(studentSolvedQuizzes);
		cout << "\t----------------------------------------------------------------------------------------------------------------------\n";

	}
};

