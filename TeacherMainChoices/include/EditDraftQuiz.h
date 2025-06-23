#pragma once
#include "ScreenHeader.h"
#include "TeacherAction.h"
#include "QuizFileManger.h"
#include "Input.h"
#include "QuizInputForm.h"

class EditDraftQuiz : public TeacherAction {
	void ShowSuccessEditingMessage();
	void ShowFailedEditingMessage();

public:
	void Show() override;
};
