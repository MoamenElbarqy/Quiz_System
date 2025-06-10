#pragma once
#include <iomanip>
#include "HeaderScreen.h"
#include "Input.h"
#include "StudnetRegister.h"
#include "TeacherRegister.h"
class Register : private HeaderScreen
{
private:
    enum RegisterOptions { RegisterStudent = 1, RegisterTeacher = 2, Exit = 3 };

    static void ShowStudentRegisterScreen()
    {
        StudnetRegister::ShowStudentRegister();
    }

    static void ShowTeacherRegisterScreen()
    {
        TeacherRegister::ShowTeacherRegister();
    }

    static void BackToRegisterMenu()
    {
        cout << setw(37) << left << "" << "\n\t\t\t\tPress any key to go back to Register Menu...\n";
        system("pause>0");
        MainRegister();
    }

    static void PerformMainMenuOptions(RegisterOptions choice)
    {
        switch (choice)
        {
        case Register::RegisterStudent:
            ShowStudentRegisterScreen();
            BackToRegisterMenu();
            break;
        case Register::RegisterTeacher:
            ShowTeacherRegisterScreen();
            BackToRegisterMenu();
            break;
        case Register::Exit:
            break;
        }
    }

public:
    static void MainRegister()
    {
        system("cls");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tRegister Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Register As Student.\n";
        cout << setw(37) << left << "" << "\t[2] Register As Teacher.\n";
        cout << setw(37) << left << "" << "\t[3] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "Choose What Do you Want to Do :";
        PerformMainMenuOptions(RegisterOptions(Input::ReadNumberBetween(1, 3)));
    }
};
