#include "TeacherInputForm.h"

vector<string> TeacherInputForm::TeacherInputData() {
    vector<string> teacherInfo;

    cout << "Please Enter Your First Name: ";
    teacherInfo.push_back(Input::ReadString());

    cout << "Please Enter Your Last Name: ";
    teacherInfo.push_back(Input::ReadString());

    cout << "Please Enter Your Phone Number: ";
    teacherInfo.push_back(Input::ReadPhoneNumber());

    cout << "Please Enter Your Email: ";
    teacherInfo.push_back(Input::ReadEmail());

    cout << "Please Enter Your Password: ";
    teacherInfo.push_back(Input::ReadString());

    cout << "Please Enter Your Gender: ";
    teacherInfo.push_back(Input::ReadString());

    return teacherInfo;
}
