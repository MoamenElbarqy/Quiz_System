#include <iomanip>
#include <iostream>
#include "TeacherMainMenu.h"
#include "ScreenHeader.h"
#include "TeacherActionPerformer.h"

using namespace std;

void TeacherMainMenu::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\tTeacher Screen");

    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\tTeacher Main Menu\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Create New Quiz.\n";
    cout << setw(37) << left << "" << "\t[2] Edit Drafted Quiz.\n";
    cout << setw(37) << left << "" << "\t[3] Publish Quiz.\n";
    cout << setw(37) << left << "" << "\t[4] Delete Quiz.\n";
    cout << setw(37) << left << "" << "\t[5] Exit.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "Choose What Do you Want to Do: ";
    TeacherActionPerformer::Perform(TeacherMenuOptions(Input::ReadNumberBetween(1, 5)));
}
