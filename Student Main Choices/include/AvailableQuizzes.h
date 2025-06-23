#pragma once
#include <vector>
#include "Quiz.h"
#include "StudentAction.h"


class AvailableQuizzes : public StudentAction {
	void ShowTableHeader();
	void ShowTableRows(std::vector<Quiz> &vec);
	void ShowTableFooter();
public:
	void Show() override;
};
