#include <iostream>
#include "StudentRegister.h"
#include "ScreenHeader.h"
#include "Student.h"
#include "StudentInputForm.h"
#include "StudentFileManger.h"
#include "StudentCleaner.h"
using namespace std;

void StudentRegister::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Student Register Screen");
    vector<string> studentInfo = StudentInputForm::StudentInputData();
    Student *student = StudentFileManger::Find(studentInfo[2], studentInfo[4]);
    if (student) {
        cout << "\n========================================\n";
        cout << " You Are Already Existed In Our System :-) \n";
        cout << "========================================\n";
        StudentCleaner::CleanUp(student);
    } else {
        StudentFileManger::SaveNewToFile(studentInfo);
        cout << "\n========================================\n";
        cout << " You Added To Our System Successfully :-) \n";
        cout << "========================================\n";
    }
}
