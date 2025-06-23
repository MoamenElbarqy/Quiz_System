#pragma once
#include <string>
#include "Person.h"

class Student : public Person {
public:
    Student(std::string firstName, std::string lastName, std::string phoneNumber, std::string email, std::string password, std::string gender);
};
