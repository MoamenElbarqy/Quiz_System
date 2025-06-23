#pragma once
#include <vector>
#include <string>
#include "Question.h"
#include "StudentAction.h"

class ReviewSolvedQuiz : public StudentAction {
    void ReviewQuestions(const std::vector<Question> &questions, const std::vector<int> &studentAnswers);
public:
    void Show() override;

};
