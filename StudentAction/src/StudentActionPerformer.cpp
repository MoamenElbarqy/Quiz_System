#include "StudentActionPerformer.h"
#include "StudentAction.h"
#include "StudentActionFactory.h"
#include "StudentActionCleaner.h"
#include "StudentMenuReseter.h"


void StudentActionPerformer::Perform(StudentMenuOptions option) {
    StudentAction *action = StudentActionFactory::Create(option);
    if (!action)
        return;
    action->Show();
    StudentActionCleaner::CleanUp(action);
    StudentMenuReseter::BackToStudentMenu();
} 