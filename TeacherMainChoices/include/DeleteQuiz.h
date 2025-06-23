#pragma once
#include "ScreenHeader.h"
#include "TeacherAction.h"
#include "QuizFileManger.h"
#include "Input.h"

class DeleteQuiz : public TeacherAction {
private:
	ScreenHeader header;

	void ShowSuccessDeletionMessage();
	void ShowFailedDeletionMessage();
	bool DeleteFromPublishedQuizzes();
	bool DeleteFromDraftedQuizzes();

public:
	void Show() override;
};
