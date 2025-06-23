#pragma once
#include "TeacherAction.h"
#include "ScreenHeader.h"
#include "Quiz.h"
#include "QuizFileManger.h"
#include "Input.h"

class PublishQuiz : public TeacherAction {
	void ShowSuccessfulPublishMessage();
	void ShowFailedPublishMessage();

public:
	void Show() override;
};
