#pragma once
#include <iostream>
#include <string>
#include "Global.h"
using namespace std;

class HeaderScreen
{
protected:
	static void DrawScreenHeader(string Title, string subtitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t   " << Title;
		if (subtitle != "")
		{
			cout << "\n\t\t\t\t\t\t" << subtitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n";
		if (SystemUser)
			cout << "\n\t\t\t\t\t\tWelcome " << SystemUser->getFirstName() << "\n\n";
	}
};