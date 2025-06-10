#pragma once
#include <string>
#include <map>
#include "Global.h"
using namespace std;
class Quiz
{
private:
	enum QuizMode
	{
		EmptyMode = 1,
		ExsistedMode = 2
	};
	string QuizID;
	string Title;
	int NumberOfQuestions;
	int QuestionDegree;
	int TimeLimit;
	string CreatedBy;
	QuizMode quizMode;

	vector<string> QuizQuestionsTitles;
	vector<string> QuizQuestionsDetails;
	vector<int> modelAnswer;

	string ConvertQuizDataToLine()
	{
		string delimiter = "#//#";
		string line;
		line += QuizID + delimiter;
		line += Title + delimiter;
		line += to_string(NumberOfQuestions) + delimiter;
		line += to_string(QuestionDegree) + delimiter;
		line += to_string(TimeLimit) + delimiter;
		line += CreatedBy + delimiter;

		for (string &str : QuizQuestionsTitles)
		{
			line += str + delimiter;
		}
		for (string &str : QuizQuestionsDetails)
		{
			line += str + delimiter;
		}
		for (int &answer : modelAnswer)
		{
			line += to_string(answer) + delimiter;
		}
		return line.substr(0, line.length() - delimiter.length());
	}
	void AddToFile(string fileName)
	{
		fstream myFile;
		myFile.open(fileName, ios::app);

		if (!myFile.is_open())
			throw runtime_error("Error: Unable to open " + fileName);

		myFile << ConvertQuizDataToLine() << "\n";

		myFile.close();
	}
	static Quiz ConvertDataToQuizObject(vector<string> quizData)
	{
		string quizID;
		string title;
		int numberOfQuestions = 0;
		int questionDegree = 0;
		int timeLimit = 0;
		string createdBy;
		vector<string> quizTitles;
		vector<string> quizDetails;

		vector<int> answers;

		quizID = quizData[0];
		title = quizData[1];
		numberOfQuestions = stoi(quizData[2]);
		questionDegree = stoi(quizData[3]);
		timeLimit = stoi(quizData[4]);
		createdBy = quizData[5];

		int titleStart = 6;
		int choicesStart = titleStart + numberOfQuestions;
		int answersStart = choicesStart + (numberOfQuestions * 4);
		for (int i = 0; i < numberOfQuestions; i++)
		{
			quizTitles.push_back(quizData[titleStart + i]);
		}
		for (int i = 0; i < numberOfQuestions * 4; i++)
		{
			quizDetails.push_back(quizData[choicesStart + i]);
		}
		for (int i = 0; i < numberOfQuestions; i++)
		{
			answers.push_back(stoi(quizData[answersStart + i]));
		}

		return Quiz(Quiz::QuizMode::ExsistedMode, quizID, title, numberOfQuestions, questionDegree,
					timeLimit, createdBy, quizTitles, quizDetails, answers);
	}
	static vector<Quiz> LoadQuizzesData(string fileName)
	{
		vector<Quiz> quizzes;
		fstream myFile;

		myFile.open(fileName, ios::in);
		if (!myFile.is_open())
			throw runtime_error("Can't Open " + fileName);

		string line;

		while (getline(myFile, line))
		{
			if (line.empty()) // Saving Program From Crashing Because the Last \n int the file
				continue;

			vector<string> quizData = Util::SplitRecord(line);

			quizzes.push_back(ConvertDataToQuizObject(quizData));
		}

		myFile.close();
		return quizzes;
	}
	static string QsOrder(int index)
	{
		string Orders[] = {"First", "Second", "Third", "Fourth"};
		return Orders[index - 1];
	}
	static void LoadDataToFile(vector<Quiz> quizzes, string fileName)
	{
		fstream myFile;

		myFile.open(fileName, ios::out);

		if (!myFile.is_open())
			throw runtime_error("Error: Unable to open " + fileName + " for writing");

		for (Quiz &quiz : quizzes)
		{
			myFile << quiz.ConvertQuizDataToLine() << "\n";
		}

		myFile.close();
	}

public:
	Quiz(QuizMode mode, string id, string title, int number, int degree, int time, string createdBy, vector<string> QuizTitles, vector<string> QuizDetails, vector<int> answers)
		: quizMode(mode),
		  QuizID(id),
		  Title(title),
		  NumberOfQuestions(number),
		  QuestionDegree(degree),
		  TimeLimit(time),
		  CreatedBy(createdBy),
		  QuizQuestionsTitles(QuizTitles),
		  QuizQuestionsDetails(QuizDetails),
		  modelAnswer(answers)
	{
	}

	static Quiz ReadQuizInfo()
	{
		system("cls");

		// Section 1: Basic Quiz Information
		cout << "Quiz Information\n";
		cout << "----------------\n";

		cout << "Enter Quiz ID: ";
		string id = Input::ReadString();

		cout << "Enter Quiz Title: ";
		string title = Input::ReadString();

		cout << "Enter Number of Questions (1-10): ";
		int numQuestions = Input::ReadNumberBetween(1, 10);

		cout << "Enter Points per Question (1-5): ";
		int questionDegree = Input::ReadNumberBetween(1, 5);

		cout << "Enter Time Limit (minutes, 5-180): ";
		int quizTime = Input::ReadNumberBetween(5, 180);

		vector<string> qsTitles;
		vector<string> qsDetails;
		vector<int> quizTrueChoices;

		for (int i = 0; i < numQuestions; i++)
		{
			cout << "\nQuestion " << (i + 1) << "/" << numQuestions << "\n";
			cout << string(20, '-') << "\n";

			cout << "Enter Question Text: ";
			qsTitles.push_back(Input::ReadString());

			for (int j = 1; j <= 4; j++)
			{
				cout << "  Enter " << QsOrder(j) << " Choice: ";
				qsDetails.push_back(Input::ReadString());
			}

			cout << "Select Correct Choice (1-4): ";
			quizTrueChoices.push_back(Input::ReadNumberBetween(1, 4));

			if (i < numQuestions - 1)
			{
				cout << "\n";
			}
		}

		cout << "\nQuiz creation complete!\n";
		cout << string(30, '=') << "\n";
		cout << "Summary:\n";
		cout << "- Quiz ID: " << id << "\n";
		cout << "- Title: " << title << "\n";
		cout << "- Questions: " << numQuestions << "\n";
		cout << "- Points per question: " << questionDegree << "\n";
		cout << "- Time limit: " << quizTime << " minutes\n";
		cout << string(30, '=') << "\n\n";

		return Quiz(
			Quiz::QuizMode::ExsistedMode,
			id,
			title,
			numQuestions,
			questionDegree,
			quizTime,
			SystemUser->getFullName(),
			qsTitles,
			qsDetails,
			quizTrueChoices);
	}
	static Quiz Find(string QuizID, string fileName)
	{
		fstream myFile;
		myFile.open(fileName, ios::in);

		if (!myFile.is_open())
			throw std::runtime_error("Error: Could not open" + fileName);

		string line;
		while (getline(myFile, line))
		{
			if (line.empty()) // Saving Program From Crashing Because the Last \n int the file
				continue;

			vector<string> quizInfo = Util::SplitRecord(line);
			if (quizInfo[0] == QuizID)
			{
				myFile.close();
				return ConvertDataToQuizObject(quizInfo);
			}
		}
		myFile.close();

		return Quiz(QuizMode::EmptyMode, "", "", 0, 0, 0, "", {}, {}, {});
	}
	static Quiz FindInPublished(string QuizID)
	{
		return Find(QuizID, PUBLISHED_QUIZZES_FILE);
	}
	static Quiz FindInDrafted(string QuizID)
	{
		return Find(QuizID, DRAFTED_QUIZZES_FILE);
	}
	static Quiz FindInDeleted(string QuizID)
	{
		return Find(QuizID, DELETED_QUIZZES_FILE);
	}

	bool isEmpty()
	{
		return quizMode == QuizMode::EmptyMode;
	}
	static void LoadDataToPublished(vector<Quiz> quizzes)
	{
		LoadDataToFile(quizzes, PUBLISHED_QUIZZES_FILE);
	}
	static void LoadDataToDrafted(vector<Quiz> quizzes)
	{
		LoadDataToFile(quizzes, DRAFTED_QUIZZES_FILE);
	}
	static void LoadDataToDeleted(vector<Quiz> quizzes)
	{
		LoadDataToFile(quizzes, DELETED_QUIZZES_FILE);
	}
	int getTotalDegrees()
	{
		return NumberOfQuestions * QuestionDegree;
	}
	int getNumberOfQs()
	{
		return NumberOfQuestions;
	}
	void AddToDrafted()
	{
		AddToFile(DRAFTED_QUIZZES_FILE);
	}

	void AddToPublished()
	{
		AddToFile(PUBLISHED_QUIZZES_FILE);
	}
	void AddToDeleted()
	{
		AddToFile(DELETED_QUIZZES_FILE);
	}
	string getID()
	{
		return QuizID;
	}
	static vector<Quiz> LoadDraftedQuizzes()
	{
		return LoadQuizzesData(DRAFTED_QUIZZES_FILE);
	}
	static vector<Quiz> LoadPublishedQuizzes()
	{

		return LoadQuizzesData(PUBLISHED_QUIZZES_FILE);
	}
	static vector<Quiz> LoadDeletedQuizzes()
	{
		return LoadQuizzesData(DELETED_QUIZZES_FILE);
	}
	string getCreatedBy()
	{
		return CreatedBy;
	}

	int getQsDegree()
	{
		return QuestionDegree;
	}
	int getTimeLimit()
	{
		return TimeLimit;
	}
	string getTitle()
	{
		return Title;
	}
	vector<string> getQuestionsTitles()
	{
		return QuizQuestionsTitles;
	}
	vector<string> getQuestionsDetails()
	{
		return QuizQuestionsDetails;
	}
	vector<int> getModelAnswer()
	{
		return modelAnswer;
	}
	char getQuizGrade(int stundetMarks)
	{
		int stundetPercentage = stundetMarks * 100 / getTotalDegrees();
		if (stundetPercentage >= 90)
		{
			return 'A';
		}
		else if (stundetPercentage >= 80)
		{
			return 'B';
		}
		else if (stundetPercentage >= 70)
		{
			return 'C';
		}
		else if (stundetPercentage >= 50)
		{
			return 'D';
		}

		return 'F';
	}
	bool isPassed(int studnetDegree)
	{
		return studnetDegree >= getTotalDegrees() / 2;
	}
};