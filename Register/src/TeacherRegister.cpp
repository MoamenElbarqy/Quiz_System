#include <iostream>
#include <vector>
#include "Teacher.h"
#include "TeacherInputForm.h"
#include "TeacherFileManger.h"
#include "TeacherRegister.h"
#include <TeacherCleaner.h>

#include "ScreenHeader.h"
using namespace std;


void TeacherRegister::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Teacher Register Screen");
    vector<string> teacherInfo = TeacherInputForm::TeacherInputData();
    Teacher *teacher = TeacherFileManager::Find(teacherInfo[2], teacherInfo[4]);
    if (teacher) {
        cout << "\n========================================\n";
        cout << " You Are Already Existed In Our System :-) \n";
        cout << "========================================\n";
        TeacherCleaner (teacher);
    } else {
        TeacherFileManager::SaveNewToFile(teacherInfo);
        cout << "\n========================================\n";
        cout << " You Added To Our System Successfully :-) \n";
        cout << "========================================\n";
    }
}
