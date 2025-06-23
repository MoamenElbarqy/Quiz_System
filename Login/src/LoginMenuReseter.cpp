#include <iostream>
#include <iomanip>

#include "LoginMenuReseter.h"
#include "Login.h"

using std::cout;
using std::setw;
using std::left;

void LoginMenuReseter::BackToLoginMenu() {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Login Menu...\n";
    system("pause>0");
    Login login;
    login.Show();
}
