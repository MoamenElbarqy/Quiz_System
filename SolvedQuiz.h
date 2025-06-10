#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Util.h"
#include "Global.h"
using namespace std;

enum SolvedQuizMode
{
	EmptySolvedQuiz = 1,
	ExsistedSolvedQuiz = 2,
	AddNewSolvedQuiz = 3
};

class SolvedQuiz
{
private:
	string quizID;
	int totalMarks;
	int score;
	string resultStatus; // Passed / Failed
	char grade;			 // A, B, C...
	string studentName;
	vector<int> studentAnswers;
	SolvedQuizMode quizMode;

	string ConvertSolvedQuizDataToLine()
	{
		string line;
		string delimiter = "#//#";

		line += quizID + delimiter;
		line += to_string(totalMarks) + delimiter;
		line += to_string(score) + delimiter;
		line += resultStatus + delimiter;
		line += grade + delimiter;
		line += studentName + delimiter;

		for (int answer : studentAnswers)
		{
			line += to_string(answer) + delimiter;
		}

		return line.substr(0, line.length() - delimiter.length());
	}

public:
	SolvedQuiz(SolvedQuizMode QuizMode, string quizID, int totalMarks, int score,
			   string resultStatus, char grade, string studentName,
			   vector<int> studentAnswers)
		: quizMode(QuizMode), quizID(quizID), totalMarks(totalMarks),
		  score(score), resultStatus(resultStatus), grade(grade),
		  studentName(studentName), studentAnswers(studentAnswers)
	{
	}
	static vector<string> getSolvedQuizzesIDs()
	{
		fstream myFile;

		vector<string> SolvedQuizzesIDs;

		myFile.open(SOLVED_QUIZZES_FILE, ios::in);

		if (!myFile.is_open())
			throw runtime_error("Can't open " + SOLVED_QUIZZES_FILE);

		string line;

		while (getline(myFile, line))
		{
			if (line.empty()) // Saving Program From Crashing Because the Last \n int the file
				continue;

			vector<string> SolvedQuizData = Util::SplitRecord(line);
			SolvedQuizzesIDs.push_back(SolvedQuizData[0]);
		}

		myFile.close();

		return SolvedQuizzesIDs;
	}
	void AddToFile()
	{
		fstream myFile(SOLVED_QUIZZES_FILE, ios::app); 

		if (!myFile.is_open())
			throw runtime_error("Can't open " + SOLVED_QUIZZES_FILE);

		string line = ConvertSolvedQuizDataToLine();

		myFile << line << "\n";

		myFile.close();
	}

	static vector<SolvedQuiz> LoadSolvedQuizzes()
	{
		vector<SolvedQuiz> solvedQuizzes;
		fstream file(SOLVED_QUIZZES_FILE, ios::in);

		if (!file.is_open())
			throw runtime_error("Can't open " + SOLVED_QUIZZES_FILE);

		string line;
		while (getline(file, line))
		{
			if (line.empty()) // Saving Program From Crashing Because the Last \n int the file
				continue;
			vector<string> data = Util::SplitRecord(line, "#//#");

			if (data.size() < 6)
				continue;

			string quizID = data[0];
			int totalMarks = stoi(data[1]);
			int score = stoi(data[2]);
			string resultStatus = data[3];
			char grade = data[4][0];
			string studentName = data[5];

			vector<int> studentAnswers;
			for (int i = 6; i < int(data.size()); ++i)
			{
				studentAnswers.push_back(stoi(data[i]));
			}

			solvedQuizzes.push_back(SolvedQuiz(
				SolvedQuizMode::ExsistedSolvedQuiz, quizID, totalMarks, score,
				resultStatus, grade, studentName, studentAnswers));
		}

		file.close();
		return solvedQuizzes;
	}
	static SolvedQuiz Find(string quizID, string studentName)
	{
		fstream file(SOLVED_QUIZZES_FILE, ios::in);

		if (!file.is_open())
			throw runtime_error("Error: Could not open " + SOLVED_QUIZZES_FILE);

		string line;
		while (getline(file, line))
		{
			if (line.empty()) // Saving Program From Crashing Because the Last \n int the file
				continue;

			vector<string> data = Util::SplitRecord(line, "#//#");

			if (data.size() < 6)
				continue;

			if (data[0] == quizID && data[5] == studentName)
			{
				int totalMarks = stoi(data[1]);
				int score = stoi(data[2]);
				string resultStatus = data[3];
				char grade = data[4][0];
				vector<int> studentAnswers;

				for (size_t i = 6; i < data.size(); ++i)
				{
					studentAnswers.push_back(stoi(data[i]));
				}
				file.close();
				return SolvedQuiz(SolvedQuizMode::ExsistedSolvedQuiz, quizID, totalMarks, score, resultStatus, grade, studentName, studentAnswers);
			}
		}

		file.close();

		return SolvedQuiz(SolvedQuizMode::EmptySolvedQuiz, "", 0, 0, "", 'F', "", {});
	}
	bool isEmpty()
	{
		return SolvedQuizMode::EmptySolvedQuiz == quizMode;
	}
	string getQuizID()
	{
		return quizID;
	}
	int getTotalMarks()
	{
		return totalMarks;
	}
	int getScore()
	{
		return score;
	}
	string getResultStatus()
	{
		return resultStatus;
	}
	char getGrade()
	{
		return grade;
	}
	string getStudentName()
	{
		return studentName;
	}
	vector<int> getStudentAnswers()
	{
		return studentAnswers;
	}
};
