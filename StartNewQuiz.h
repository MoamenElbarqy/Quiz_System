#pragma once
#include "HeaderScreen.h"
#include "Student.h"
#include "SolvedQuiz.h"

class StartNewQuiz : private HeaderScreen
{
private:
	static bool isSolved(string QuizID)
	{
		SolvedQuiz curQuiz = SolvedQuiz::Find(QuizID, SystemUser->getFullName());
		if (!curQuiz.isEmpty())
			return true;

		return false;
	}

	static void ShowQuizResults(int stundetMarks, int ExamTotalMarks,
		char studentGrade, bool passed)
	{
		cout << "\n=====================================\n";
		cout << " Test Done!\n";
		cout << " Your Mark : " << stundetMarks << " / " << ExamTotalMarks << "\n";
		cout << " Your Grade : " << studentGrade << "\n";

		if (passed)
			cout << "Congratulations You Passed The Exam\n";
		else
			cout << "Sorry For Telling You, You Failed\n";

		cout << "=====================================\n";
	}

	static void SavingQuizResults(string QuizID, int ExamMarks, int stundetScore,
		string resultOfExam, char studentGrade,
		string studentName, vector<int> stundetAnswers)
	{
		SolvedQuiz studentSolvedQuiz(SolvedQuizMode::AddNewSolvedQuiz, QuizID, ExamMarks,
			stundetScore, resultOfExam, studentGrade,
			studentName, stundetAnswers);
		studentSolvedQuiz.AddToFile();
	}

	static void SolvingQuiz(string QuizID)
	{
		system("cls");
		Quiz studnetQuiz = Quiz::FindInPublished(QuizID);
		DrawScreenHeader("\t" + studnetQuiz.getTitle());

		int rightAnswers = 0;
		vector<string> QuestionsTitles = studnetQuiz.getQuestionsTitles();
		vector<string> QuestionsDetails = studnetQuiz.getQuestionsDetails();
		vector<int> ModelAnswer = studnetQuiz.getModelAnswer();
		vector<int> studentAnswers;

		for (int i = 0; i < studnetQuiz.getNumberOfQs(); i++)
		{
			// Display question
			cout << "\n"
				<< QuestionsTitles[i] << "\n\n";

			// Display choices
			for (int k = 0, j = 4 * i + k; k < 4; k++, j++)
			{
				cout << "  " << k + 1 << ") " << QuestionsDetails[j] << "\n";
			}

			// Get student's answer
			cout << "\nYour Answer is: ";
			int studentAnswer = Input::ReadNumberBetween(1, 4);
			studentAnswers.push_back(studentAnswer);

			if (studentAnswer == ModelAnswer[i])
				rightAnswers++;

			cout << "\n==============================\n";
		}

		// Calculate and show results
		int stundetMarks = rightAnswers * studnetQuiz.getQsDegree();
		char grade = studnetQuiz.getQuizGrade(stundetMarks);
		bool passed = studnetQuiz.isPassed(stundetMarks);

		ShowQuizResults(stundetMarks, studnetQuiz.getTotalDegrees(), grade, passed);

		// Save results
		string resultOfExam = passed ? "Passed" : "Failed";
		SavingQuizResults(QuizID, studnetQuiz.getTotalDegrees(), stundetMarks,
			resultOfExam, grade, SystemUser->getFullName(), studentAnswers);
	}

public:
	static void Show()
	{
		system("cls");
		DrawScreenHeader("\t Start New Quiz Screen");

		cout << "Please Enter Quiz ID: ";
		string QuizID = Input::ReadString();

		// Check if already solved
		if (isSolved(QuizID))
		{
			cout << "\n=====================================\n";
			cout << " You Solved This Quiz Before :-)\n";
			cout << "=====================================\n";
			return;
		}

		// Verify quiz exists
		Quiz studnetQuiz = Quiz::FindInPublished(QuizID);
		if (studnetQuiz.isEmpty())
		{
			cout << "\n=============================================\n";
			cout << " Quiz ID is Wrong, Check The Quiz ID again  :-)\n";
			cout << "=============================================\n";
			return;
		}

		// Start the exam
		SolvingQuiz(QuizID);
	}
};