#include <iostream>
#include "StudentInputForm.h"
#include "Input.h"

using namespace std;
vector<string> StudentInputForm::StudentInputData()
{
    vector<string> studentInfo;
    cout << "Please Enter Your First Name: ";
    studentInfo.push_back(Input::ReadString());
    cout << "Please Enter Your Last Name: ";
    studentInfo.push_back(Input::ReadString());
    cout << "Please Enter Your Phone Number: ";
    studentInfo.push_back(Input::ReadPhoneNumber());
    cout << "Please Enter Your Email: ";
    studentInfo.push_back(Input::ReadEmail());
    cout << "Please Enter Your Password: ";
    studentInfo.push_back(Input::ReadString());
    cout << "Please Enter Your Gender: ";
    studentInfo.push_back(Input::ReadString());
    return studentInfo;
} 