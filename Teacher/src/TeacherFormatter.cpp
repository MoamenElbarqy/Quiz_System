#include <string>
#include "Teacher.h"
#include "Global.h"
#include "TeacherFormatter.h"
using namespace std;

string TeacherFormatter::ConvertObjectToLine(Teacher teacher) {
    string result;
    result += teacher.getFirstName() + DELIMITER;
    result += teacher.getLastName() + DELIMITER;
    result += teacher.getPhoneNumber() + DELIMITER;
    result += teacher.getEmail() + DELIMITER;
    result += teacher.getPassword() + DELIMITER;
    result += teacher.getGender();
    return result;
}
