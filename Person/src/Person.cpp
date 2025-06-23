#include "Person.h"

Person::Person(string firstName, string lastName, string phoneNumber, string email, string password, string gender)
    : firstName(firstName), lastName(lastName), phoneNumber(phoneNumber), email(email), password(password), gender(gender) {}

void Person::setFirstName(string &str) { firstName = str; }
void Person::setLastName(string &str) { lastName = str; }
void Person::setPhoneNumber(string &str) { phoneNumber = str; }
void Person::setEmail(string &str) { email = str; }
void Person::setPassword(string &str) { password = str; }
void Person::setGender(string str) { gender = str; }

string Person::getFirstName() { return firstName; }
string Person::getLastName() { return lastName; }
string Person::getPhoneNumber() { return phoneNumber; }
string Person::getEmail() { return email; }
string Person::getPassword() { return password; }
string Person::getFullName() { return firstName + " " + lastName; }
string Person::getGender() { return gender; } 