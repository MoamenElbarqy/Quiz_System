#include "QuestionInputForm.h"
#include <iostream>
using namespace std;

Question QuestionInputForm::ReadQuestion() {
    cout << "Enter Question Title: ";
    string title = Input::ReadString();
    cout << "Enter Number Of Choices (2 - 5): ";
    int numberOfChoices = Input::ReadNumberBetween(2, 5);
    vector<string> choices;
    for (int i = 0; i < numberOfChoices; i++) {
        cout << "Enter " << i + 1 << ". ";
        choices.push_back(Input::ReadString());
    }
    cout << "Enter True Choice Order {1....." << numberOfChoices << "} :";
    int trueChoiceOrder = Input::ReadNumberBetween(1, numberOfChoices);
    return Question(title, numberOfChoices, choices, trueChoiceOrder);
} 