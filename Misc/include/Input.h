#pragma once
#include <string>
#include <iostream>

using namespace std;

class Input
{
    static bool CheckEmailDomain(const string &str);

public:
    static float ReadFloatNumber();
    static string ReadString();
    static int ReadNumberBetween(int from, int to);
    static int ReadNumber();
    static string ReadEmail();
    static string ReadPhoneNumber();
};
