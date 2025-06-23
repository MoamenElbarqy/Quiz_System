#pragma once
#include <string>
#include <vector>
#include "Question.h"


class Quiz {  
	string QuizID;  
	string Title;  
	int NumberOfQuestions;  
	int TimeLimit;  
	int DegreesPerQuestion = 0;
	string CreatedBy;  
	vector<Question> Questions;  

public:  
	Quiz(string id, string title, int number, int time, int degreesPerQuestion,  
		string createdBy, vector<Question> questions);

	bool isPassed(int studentDegree);
	// Getters  

	int getTotalQuizDegrees();
	int getNumberOfQuestions();
	string getID();
	string getCreatedBy();
	int getTimeLimit();
	string getTitle();
	vector<Question> getQuestions();
	int getDegreesPerQuestion();
	char getQuizGrade(int stundetMarks);

};
