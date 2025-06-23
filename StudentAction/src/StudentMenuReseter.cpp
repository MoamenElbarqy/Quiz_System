//
// Created by Moamen Elbarky on 6/22/2025.
//
#include "StudentMenuReseter.h"
#include "StudentMainMenu.h"
#include <iostream>
#include <iomanip>
using namespace std;

void StudentMenuReseter::BackToStudentMenu() {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Login Screen...\n";
    system("pause>0");
    StudentMainMenu::Show();
}
