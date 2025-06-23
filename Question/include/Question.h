#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Question {
private:
	string QuestionTitle;
	int NumberOfChoices;
	vector<string> choices;
	int TrueChoiceOrder;

public:
	Question(string title, int numberOfChoices, vector<string> choices, int trueChoiceOrder);
	string getQuestionTitle();
	int getNumberOfChoices();
	string getChoicesAsString();
	vector<string> getChoices();
	int getTrueChoiceOrder();
};
