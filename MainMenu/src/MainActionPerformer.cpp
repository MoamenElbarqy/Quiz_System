#include "MainActionPerformer.h"
#include "MainMenuChoices.h"
#include "MainActionCleaner.h"
#include "MainActionFactory.h"

void MainActionPerformer::Perform(MainMenuChoices choice) {
    MainAction *action = MainActionFactory::Create(choice);
    if (!action)
        return;
    action->Show();
    MainActionCleaner::CleanUp(action);
} 