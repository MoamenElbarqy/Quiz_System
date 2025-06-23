#pragma once
#include "MainAction.h"
#include "MainMenuChoices.h"

class MainActionFactory {
public:
	static MainAction *Create(MainMenuChoices choice);
};
