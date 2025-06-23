#include <iostream>
#include <string>
#include "ScreenHeader.h"
#include "Global.h"

using std::string;
using std::cout;

void ScreenHeader::DrawHeader(string Title, string subtitle) {
    cout << "\t\t\t\t\t______________________________________";
    cout << "\n\n\t\t\t\t\t   " << Title;
    if (subtitle != "") {
        cout << "\n\t\t\t\t\t\t" << subtitle;
    }
    cout << "\n\t\t\t\t\t______________________________________\n";
    if (SystemUser)
        cout << "\n\t\t\t\t\t\tWelcome " << SystemUser->getFirstName() << "\n\n";
} 