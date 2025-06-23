#include "TeacherActionPerformer.h"

void TeacherActionPerformer::Perform(TeacherMenuOptions option) {
    TeacherAction *action = TeacherActionFactory::Create(option); // OCP

    if (!action)
        return;

    action->Show();
    TeacherActionCleaner::CleanUp(action);
    TeacherMenuReseter::BackToTeacherMenu();
} 