#pragma once
#include <vector>
#include "HeaderScreen.h"
#include "Teacher.h"
class TeacherRegister : private HeaderScreen
{
private:

    static vector<string> ReadTeacherInfo()
    {
        vector<string> result;

        cout << "Please Enter This Info :- \n\n";

        cout << "First Name : ";
        string FirstName = Input::ReadString();
        result.push_back(FirstName);


        cout << "Last Name : ";
        string LastName = Input::ReadString();
        result.push_back(LastName);


        cout << "Phone Number : ";
        string PhoneNumber = Input::ReadPhoneNumber();
        result.push_back(PhoneNumber);


        cout << "Email : ";
        string email = Input::ReadEmail();
        result.push_back(email);


        cout << "Password : ";
        string password = Input::ReadString();
        result.push_back(password);

        cout << "Gender (male / female): ";
        string gender = Input::ReadString();
        result.push_back(gender);

        return result;
    }

public:

    static void ShowTeacherRegister()
    {
        system("cls");
        DrawScreenHeader("\t Teacher Register Screen");


        vector<string> teacherInfo = ReadTeacherInfo();


        Teacher newTeacher = Teacher::Find(teacherInfo[2], teacherInfo[4]); 
        if (!newTeacher.isEmpty())
        {
            cout << "\n========================================\n";
            cout << " You Are Already Existed In Our System :-) \n";
            cout << "========================================\n";
        }
        else
        {
            Teacher::SaveNewToFile(teacherInfo);
            cout << "\n========================================\n";
            cout << " You Added To Our System Successfully :-) \n";
            cout << "========================================\n";
        }
    }
};
