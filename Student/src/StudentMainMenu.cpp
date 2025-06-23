#include <iostream>
#include <iomanip>
#include "StudentActionPerformer.h"
#include "Input.h"
#include "StudentMainMenu.h"
#include "ScreenHeader.h"
#include "StudentMainMenuChoices.h"

using namespace std;

void StudentMainMenu::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\tStudent Screen");
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\tStudent Main Menu\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] View Available Quizzes.\n";
    cout << setw(37) << left << "" << "\t[2] Start New Quiz.\n";
    cout << setw(37) << left << "" << "\t[3] View Previous Results.\n";
    cout << setw(37) << left << "" << "\t[4] Review Solved Quiz.\n";
    cout << setw(37) << left << "" << "\t[5] Exit.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "Choose What Do you Want to Do: ";
    StudentActionPerformer::Perform(static_cast<StudentMenuOptions>(Input::ReadNumberBetween(1, 5)));
} 