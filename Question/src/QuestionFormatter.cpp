#include <string>
#include <vector>
#include "QuestionFormatter.h"

using std::string;
using std::vector;

string QuestionFormatter::ConvertQuestionToLine(Question question) {
    return question.getQuestionTitle() + "|" + std::to_string(question.getNumberOfChoices()) + "|" + question.getChoicesAsString() + "|" + std::to_string(question.getTrueChoiceOrder());
}

Question QuestionFormatter::ConvertDataToQuestionObject(vector<string> questionData) {
    string questionTitle = questionData[0];
    int numberOfChoices = std::stoi(questionData[1]);
    vector<string> choices;
    for (int i = 0; i < numberOfChoices; i++) {
        choices.push_back(questionData[i + 2]);
    }
    int trueChoiceOrder = std::stoi(questionData[choices.size() + 2]);
    return Question(questionTitle, numberOfChoices, choices, trueChoiceOrder);
} 