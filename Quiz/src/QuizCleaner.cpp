//
// Created by Moamen Elbarky on 6/23/2025.
//
#include "QuizCleaner.h"
void QuizCleaner::CleanUp(Quiz *&quiz) {
    delete quiz;
    quiz = nullptr;
}
