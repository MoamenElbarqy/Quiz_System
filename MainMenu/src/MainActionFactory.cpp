#include "MainActionFactory.h"
#include "Login.h"
#include "Register.h"
#include "MainAction.h"

MainAction *MainActionFactory::Create(MainMenuChoices choice) {
    switch (choice) {
        case main_menu_login:
            return new Login();
        case main_menu_register:
            return new Register();
        default:
            return nullptr;
    }
}
