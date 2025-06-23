//
// Created by Moamen Elbarky on 6/23/2025.
//
#include "StudentCleaner.h"

void StudentCleaner::CleanUp(Student *&student) {
    delete student;
    student = nullptr;
}
