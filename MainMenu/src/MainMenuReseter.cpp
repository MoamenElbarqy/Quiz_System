#include <iostream>
#include <iomanip>
#include "MainMenuReseter.h"
#include "MainMenu.h"

using namespace std;
void MainMenuReseter::BackToMainMenu() {
    cout << "\t Press Any Key To Back To Main Menu ....";
    system("Pause>0");
    MainMenu::Show();
} 