#pragma once
#include "Global.h"
#include "Quiz.h"
#include "ScreenHeader.h"
#include "QuizInputForm.h"
#include "TeacherAction.h"
#include "Util.h"
#include "QuizFileManger.h"
#include <iomanip>
using namespace std;

class CreateNewQuiz : public TeacherAction {
public:
	void Show() override;
};
