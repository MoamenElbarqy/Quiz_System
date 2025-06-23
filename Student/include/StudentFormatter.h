#pragma once
#include "Student.h"
#include <string>

class StudentFormatter {
public:
    static std::string ConvertObjectToLine(Student student);
};
