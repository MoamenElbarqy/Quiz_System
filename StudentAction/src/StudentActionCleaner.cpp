#include "StudentActionCleaner.h"
void StudentActionCleaner::CleanUp(StudentAction * &action)
{
    delete action;
    action = nullptr;
} 