#include "RegisterActionPerformer.h"
#include "PersonRegister.h"
#include "RegisterActionFactory.h"
#include "RegisterActionCleaner.h"
#include "RegisterMenuReseter.h"

void RegisterActionPerformer::Perform(RegisterChoices option) {
    PersonRegister *action = RegisterActionFactory::Create(option);
    if (!action)
        return;
    action->Show();
    RegisterActionCleaner::CleanUp(action);
    RegisterMenuReseter::BackToRegisterMenu();
} 