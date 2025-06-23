#include "LoginActionPerformer.h"
#include "PersonLogin.h"
#include "LoginActionFactory.h"
#include "LoginActionCleaner.h"
#include "LoginMenuReseter.h"

void LoginActionPerformer::Perform(LoginOptions option) {
    PersonLogin *action = LoginActionFactory::Create(option);
    if (!action)
        return;
    action->Show();
    LoginActionCleaner::CleanUp(action);
    LoginMenuReseter::BackToLoginMenu();
} 