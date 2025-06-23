#include "RegisterActionCleaner.h"
void RegisterActionCleaner::CleanUp(PersonRegister * &action) {
    delete action;
    action = nullptr;
} 