#pragma once

#include <vector>
#include <string>

using namespace std;


class SolvedQuiz {
	string quizID;
	int score;
	string studentName;
	vector<int> studentAnswers;

public:
	SolvedQuiz(string id, int score,
	           string studentName, vector<int> &studentAnswers);

	string getQuizID();
	int getScore();
	string getStudentName();
	vector<int> getStudentAnswers();
};
