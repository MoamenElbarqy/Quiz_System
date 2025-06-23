#pragma once
#include "Person.h"

class Teacher : public Person {
public:
    Teacher(string firstName, string lastName, string phoneNumber, string email, string password,
            string gender);
};
