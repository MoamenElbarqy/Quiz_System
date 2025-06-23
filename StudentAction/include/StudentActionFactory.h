#pragma once
#include "StudentAction.h"
#include "StudentMainMenuChoices.h"

class StudentActionFactory {
public:
    static StudentAction *Create(StudentMenuOptions option);
};
