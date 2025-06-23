#pragma once
#include <string>

using namespace std;

class Person {
private:
	string firstName;
	string lastName;
	string phoneNumber;
	string email;
	string password;
	string gender;

public:
	Person(string firstName, string lastName, string phoneNumber, string email, string password,
	       string gender);

	// Setters
	void setFirstName(string &str);
	void setLastName(string &str);
	void setPhoneNumber(string &str);
	void setEmail(string &str);
	void setPassword(string &str);
	void setGender(string str);

	// Getters
	string getFirstName();
	string getLastName();
	string getPhoneNumber();
	string getEmail();
	string getPassword();
	string getFullName();
	string getGender();
};
