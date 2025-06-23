#pragma once
#include "Quiz.h"

class QuizFormatter {
public:
	static string ConvertQuizDataToLine(Quiz quiz);
	static Quiz *ConvertDataToQuizObject(vector<string> &quizData);
};
