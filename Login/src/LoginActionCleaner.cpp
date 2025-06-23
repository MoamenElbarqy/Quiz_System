#include "LoginActionCleaner.h"

void LoginActionCleaner::CleanUp(PersonLogin * &action) {
    delete action;
    action = nullptr;
} 