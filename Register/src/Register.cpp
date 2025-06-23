#include <iostream>
#include <iomanip>
#include "ScreenHeader.h"
#include "RegisterActionPerformer.h"
#include "Input.h"
#include "Register.h"
using namespace std;

void Register::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Register Screen");
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t\tRegister Menu\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Register As Student.\n";
    cout << setw(37) << left << "" << "\t[2] Register As Teacher.\n";
    cout << setw(37) << left << "" << "\t[3] Exit.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "Choose What Do you Want to Do :";
    RegisterActionPerformer::Perform(static_cast<RegisterChoices>(Input::ReadNumberBetween(1, 3)));
} 