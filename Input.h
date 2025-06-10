#pragma once
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class Input
{
private:
    static bool CheckEmailDomain(string str)
    {
        // this function check the string is end with this postfix => @gmail.com
        if (str.length() <= 10)
            return false;
        return str.substr(str.length() - 10, str.length() - 1) == "@gmail.com";
    }

public:
    static float ReadFloatNumber()
    {
        float num = 0;
        cin >> num;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> num;
        }
        return num;
    }
    static string ReadString()
    {
        string str = "";
        getline(cin >> ws, str);
        return str;
    }
    static int ReadNumberBetween(int from, int to)
    {
        int num = 0;
        cin >> num;

        while (cin.fail() || num < from || num > to)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> num;
        }
        return num;
    }
    static int ReadNumber()
    {
        int num = 0;
        cin >> num;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> num;
        }
        return num;
    }
    static string ReadEmail()
    {
        // @gmail.com
        string str = "";
        getline(cin >> ws, str);
        while (!CheckEmailDomain(str))
        {
            str = "";
            getline(cin >> ws, str);
        }
        return str;
    }
    static string ReadPhoneNumber()
    {
        string str = ReadString();

        while (str.length() != 11)
        {
            str = ReadString();
        }
        return str;
    }
};