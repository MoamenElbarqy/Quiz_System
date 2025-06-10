#pragma once
#include "HeaderScreen.h"
#include "Quiz.h"
class AvailableQuizzes : private HeaderScreen
{
private:
	static void ShowTableHeader()
	{
		cout << "\t--------------------------------------------------------------------------------------------------------------\n";
		cout << "\t|    ID    |          Title            |  No. of Qs. | Qs. Degree | Total Quiz Degrees |     Publisher        \n";
		cout << "\t--------------------------------------------------------------------------------------------------------------\n";
	}
	static void ShowTableRows(vector<Quiz>& vec)
	{
		for (Quiz quiz : vec)
		{
			cout << "\t|" << setw(10) << left << quiz.getID();
			cout << "|" << setw(27) << left << quiz.getTitle();
			cout << "|" << setw(13) << left << quiz.getNumberOfQs();
			cout << "|" << setw(12) << left << quiz.getQsDegree();
			cout << "|" << setw(20) << left << quiz.getTotalDegrees();
			cout << "|" << setw(22) << left << quiz.getCreatedBy();
			cout << endl;
		}
	}
public:
    static void Show()
    {
        system("cls");

        DrawScreenHeader("\t Available Quizzes Screen");

		ShowTableHeader();

		vector<Quiz> PublishedQuizzes = Quiz::LoadPublishedQuizzes();

		ShowTableRows(PublishedQuizzes);

		cout << "\t--------------------------------------------------------------------------------------------------------------\n";

    }
};