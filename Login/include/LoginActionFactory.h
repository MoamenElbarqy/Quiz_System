#pragma once
#include "PersonLogin.h"
#include "LoginOptions.h"

class LoginActionFactory {
public:
    static PersonLogin *Create(LoginOptions option);
};
