//
// Created by Moamen Elbarky on 6/23/2025.
//
#include "PersonCleaner.h"

void PersonCleaner::CleanUp(Person *person) {
    delete person;
    person = nullptr;
}
