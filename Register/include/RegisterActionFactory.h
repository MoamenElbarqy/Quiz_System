#pragma once

#include "RegisterChoices.h"
#include "PersonRegister.h"

class RegisterActionFactory {
public:
    static PersonRegister *Create(RegisterChoices option);
}; 