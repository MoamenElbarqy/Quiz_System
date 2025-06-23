#pragma once

#include "CreateNewQuiz.h"
#include "EditDraftQuiz.h"
#include "PublishQuiz.h"
#include "DeleteQuiz.h"
#include "TeacherMainChoices.h"

class TeacherActionFactory {
public:
    static TeacherAction *Create(TeacherMenuOptions option);
}; 