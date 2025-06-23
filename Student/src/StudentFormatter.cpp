#include <string>
#include "StudentFormatter.h"
#include "Global.h"

using namespace std;
string StudentFormatter::ConvertObjectToLine(Student student) {
    string line;
    line += student.getFirstName() + DELIMITER;
    line += student.getLastName() + DELIMITER;
    line += student.getPhoneNumber() + DELIMITER;
    line += student.getEmail() + DELIMITER;
    line += student.getPassword() + DELIMITER;
    line += student.getGender();
    return line;
} 