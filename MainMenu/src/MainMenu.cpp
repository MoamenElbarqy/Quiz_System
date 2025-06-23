#include <iomanip>
#include "MainMenu.h"
#include "ScreenHeader.h"
#include "MainActionPerformer.h"
#include "Input.h"

using std::setw;
using std::cout;

void MainMenu::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\tMain Screen");
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Login.\n";
    cout << setw(37) << left << "" << "\t[2] Register.\n";
    cout << setw(37) << left << "" << "\t[3] Exit.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "Choose What Do you Want to Do :";
    MainActionPerformer::Perform(static_cast<MainMenuChoices>(Input::ReadNumberBetween(1, 3)));
}
