#pragma once
#include <string>
#include "Question.h"

class QuestionFormatter {
public:
    static string ConvertQuestionToLine(Question question);
    static Question ConvertDataToQuestionObject(vector<string> questionData);
};
