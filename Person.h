#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "Util.h"
#include "Global.h"
using namespace std;

enum Mode
{
	ExsistedMode = 1,
	EmptyMode = 2,
	AddNewMode = 3,
	UpdateMode = 4
};
class Person
{
public:
	

private:
	string firstName;
	string lastName;
	string phoneNumber;
	string email;
	string password;
	string gender;
	Mode mode;

public:
	Person(Mode mode, string firstName, string lastName, string phoneNumber, string email, string password, string gender)
		: mode(mode), firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), email(email), password(password), gender(gender)
	{
	}

	bool isEmpty()
	{
		return mode == Mode::EmptyMode;
	}

	// Setters
	void setFirstName(const string &str) { firstName = str; }
	void setLastName(const string &str) { lastName = str; }
	void setPhoneNumber(const string &str) { phoneNumber = str; }
	void setEmail(const string &str) { email = str; }
	void setPassword(const string &str) { password = str; }
	void setGender(string str) { gender = str; }

	// Getters
	string getFirstName() { return firstName; }
	string getLastName() { return lastName; }
	string getPhoneNumber() { return phoneNumber; }
	string getEmail() { return email; }
	string getPassword() { return password; }
	string getFullName() { return firstName + " " + lastName; }
	string getGender() { return gender; }
	Mode getMode() { return mode; }


};
