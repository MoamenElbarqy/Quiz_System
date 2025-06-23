#pragma once
#include <vector>
#include "SolvedQuiz.h"

class SolvedQuizRepository {
public:
	static void AddToFile(SolvedQuiz quiz);
	static std::vector<SolvedQuiz> LoadSolvedQuizzes();
	static std::vector<std::string> GetSolvedQuizzesIDs();
	static SolvedQuiz *Find(std::string quizID, std::string studentName);
};
