#include <iomanip>
#include "Login.h"
#include "ScreenHeader.h"
#include "LoginOptions.h"
#include "Input.h"
#include "LoginActionPerformer.h"

using std::setw;
using std::cout;


void Login::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t\tLogin Screen");
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t\t\tLogin Menu\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "\t[1] Login As Student.\n";
    cout << setw(37) << left << "" << "\t[2] Login As Teacher.\n";
    cout << setw(37) << left << "" << "\t[3] Exit.\n";
    cout << setw(37) << left << "" << "===========================================\n";
    cout << setw(37) << left << "" << "Choose What Do you Want to Do :";
    LoginActionPerformer::Perform(static_cast<LoginOptions>(Input::ReadNumberBetween(1, 3)));
} 