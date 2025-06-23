#include "TeacherActionCleaner.h"

void TeacherActionCleaner::CleanUp(TeacherAction * &action) {
    delete action;
    action = nullptr;
} 