#include <iostream>
#include <string>
#include "Global.h"
#include "Input.h"
#include "ScreenHeader.h"
#include "TeacherLogin.h"
#include "Teacher.h"
#include "TeacherFileManger.h"
#include "TeacherMainMenu.h"
#include "PersonCleaner.h"

using std::cout;
using std::string;

void TeacherLogin::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\tTeacher Login Screen");
    cout << "Please Enter Your Phone Number: ";
    string teacher_phone = Input::ReadString();
    cout << "Please Enter Your Password: ";
    string teacher_password = Input::ReadString();
    Teacher *teacher = TeacherFileManager::Find(teacher_phone, teacher_password);
    if (!teacher) {
        cout << "\n=====================================\n";
        cout << " Your Phone or Password is Wrong :-(\n";
        cout << "=====================================\n";
        return;
    }
    SystemUser = teacher;
    TeacherMainMenu::Show();
    PersonCleaner::CleanUp(SystemUser);
}
