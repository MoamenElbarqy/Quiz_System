#include <iostream>
#include "Global.h"
#include "QuizInputForm.h"
#include "QuestionInputForm.h"
using namespace std;
Quiz QuizInputForm::ReadQuizInfo()
{
    system("cls");

    cout << "Quiz Information\n";
    cout << "----------------\n";

    cout << "Enter Quiz ID: ";
    string id = Input::ReadString();

    cout << "Enter Quiz Title: ";
    string title = Input::ReadString();

    cout << "Enter Number of Questions (1-10): ";
    int numQuestions = Input::ReadNumberBetween(1, 10);

    cout << "Enter Time Limit (minutes, 5-180): ";
    int quizTime = Input::ReadNumberBetween(5, 180);

    cout << "Enter Number of Degrees Per Question : ";
    int DegreresPerQuestion = Input::ReadNumber();

    vector<Question> questions;
    cout << "\n-----------------------\n";

    for (int i = 0; i < numQuestions; i++) {
        cout << "Question [" << i + 1 << "/" << numQuestions << "] :\n";
        questions.push_back(QuestionInputForm::ReadQuestion());
        cout << "\n\n";
    }


    Quiz quiz(id, title, numQuestions, quizTime, DegreresPerQuestion, SystemUser->getFullName(), questions);
    QuizPrinter::Print(quiz);
    return quiz;
} 