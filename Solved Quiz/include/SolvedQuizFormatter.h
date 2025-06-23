#pragma once
#include <string>
#include "SolvedQuiz.h"

class SolvedQuizFormatter {
public:
    static std::string ConvertSolvedQuizToLine(SolvedQuiz solvedQuiz);
    static SolvedQuiz ConvertDataToSolvedQuizObject(std::string line);
};
