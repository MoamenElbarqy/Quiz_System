#include  <iostream>
#include <iomanip>
#include "RegisterMenuReseter.h"
#include "Register.h"

using namespace  std;

void RegisterMenuReseter::BackToRegisterMenu() {
    cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Register Menu...\n";
    system("pause>0");
    Register reg;
    reg.Show();
}
