#include <string>
#include <vector>
#include "QuizFormatter.h"
#include "Global.h"
#include "QuestionFormatter.h"

using namespace std;
string QuizFormatter::ConvertQuizDataToLine(Quiz quiz) {
    string line;
    line += quiz.getID() + DELIMITER;
    line += quiz.getTitle() + DELIMITER;
    line += to_string(quiz.getDegreesPerQuestion()) + DELIMITER;
    line += to_string(quiz.getTimeLimit()) + DELIMITER;
    line += quiz.getCreatedBy() + DELIMITER;
    vector<Question> questions = quiz.getQuestions();
    for (int i = 0; i < questions.size(); i++) {
        line += QuestionFormatter::ConvertQuestionToLine(questions[i]) + DELIMITER;
    }
    line = line.substr(0, line.length() - DELIMITER.length());
    return line;
}
Quiz *QuizFormatter::ConvertDataToQuizObject(vector<string> &quizData) {
    string quizID;
    string title;
    int numberOfQuestions = 0;
    int questionDegree = 0;
    int timeLimit = 0;
    string createdBy;
    vector<Question> questions;
    quizID = quizData[0];
    title = quizData[1];
    questionDegree = stoi(quizData[2]);
    timeLimit = stoi(quizData[3]);
    createdBy = quizData[4];
    int idx = 5;
    while (idx < quizData.size()) {
        string questionTitle = quizData[idx++];
        int numberOfChoices = stoi(quizData[idx++]);
        vector<string> choices;
        for (int i = 0; i < numberOfChoices; ++i) {
            choices.push_back(quizData[idx++]);
        }
        int trueChoiceOrder = stoi(quizData[idx++]);
        questions.push_back(Question(questionTitle, numberOfChoices, choices, trueChoiceOrder));
        numberOfQuestions++;
    }
    return new Quiz(quizID, title, numberOfQuestions, timeLimit, questionDegree, createdBy, questions);
} 