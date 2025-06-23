#include "Question.h"

Question::Question(string title, int numberOfChoices, vector<string> choices, int trueChoiceOrder)
    : QuestionTitle(title), NumberOfChoices(numberOfChoices), choices(choices), TrueChoiceOrder(trueChoiceOrder) {}

string Question::getQuestionTitle() { return QuestionTitle; }
int Question::getNumberOfChoices() { return NumberOfChoices; }
string Question::getChoicesAsString() {
    string result;
    for (int i = 0; i < choices.size(); i++)
        result += choices[i] + "|";
    return result.substr(0, result.length() - 1);
}
vector<string> Question::getChoices() { return choices; }
int Question::getTrueChoiceOrder() { return TrueChoiceOrder; } 