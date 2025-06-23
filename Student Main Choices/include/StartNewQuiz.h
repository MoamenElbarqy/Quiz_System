#pragma once

#include <vector>
#include <string>
#include "StudentAction.h"

class StartNewQuiz : public StudentAction {
	bool isSolved(std::string QuizID);

	void ShowQuizResults(int stundetMarks, int ExamTotalMarks, char studentGrade, bool passed);

	static void SavingQuizResults(std::string &QuizID, int &stundetScore, std::string studentName,
	                              std::vector<int> &stundetAnswers);

	void SolvingQuiz(std::string QuizID);

public:
	void Show() override;
};
