//
// Created by Moamen Elbarky on 6/23/2025.
//
#include "TeacherCleaner.h"

void TeacherCleaner::CleanUp(Teacher *&teacher) {
    delete teacher;
    teacher = nullptr;
}
