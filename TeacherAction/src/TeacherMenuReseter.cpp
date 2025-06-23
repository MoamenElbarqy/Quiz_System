//
// Created by Moamen Elbarky on 6/22/2025.
//
#include "TeacherMenuReseter.h"
#include "TeacherMainMenu.h"

void TeacherMenuReseter::BackToTeacherMenu() {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Teacher Menu...\n";
    system("pause>0");
    TeacherMainMenu::Show();
}
