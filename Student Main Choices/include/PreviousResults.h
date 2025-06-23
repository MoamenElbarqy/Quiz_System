#pragma once
#include <vector>
#include "SolvedQuiz.h"
#include "StudentAction.h"


class PreviousResults : public StudentAction {
	void ShowTableHeader();
	void ShowTableRows(std::vector<SolvedQuiz> &vec);
public:
	void Show() override;
};
