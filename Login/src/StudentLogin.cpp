#include <iostream>
#include "StudentLogin.h"
#include "ScreenHeader.h"
#include "Global.h"
#include "StudentMainMenu.h"
#include "Student.h"
#include "StudentFileManger.h"
#include "Input.h"
#include "PersonCleaner.h"

void StudentLogin::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\tStudent Login Screen");
    cout << "PLease Enter You Phone Number : ";
    string student_phone = Input::ReadString();
    cout << "Please Enter Your Password : ";
    string student_password = Input::ReadString();
    Student *student = StudentFileManger::Find(student_phone, student_password);
    if (!student) {
        cout << "\n=====================================\n";
        cout << " Your Phone or Password is Wrong :-(\n";
        cout << "=====================================\n";
        return;
    }
    SystemUser = student;
    StudentMainMenu::Show();
    PersonCleaner::CleanUp(SystemUser);
}
