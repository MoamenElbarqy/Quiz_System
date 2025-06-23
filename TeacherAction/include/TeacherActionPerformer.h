#pragma once
#include "TeacherAction.h"
#include "TeacherActionCleaner.h"
#include "TeacherActionFactory.h"
#include "TeacherMenuReseter.h"
#include "TeacherMainChoices.h"

class TeacherActionPerformer {
public:
    static void Perform(TeacherMenuOptions option);
};
