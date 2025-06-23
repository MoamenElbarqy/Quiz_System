#include <iostream>
#include "QuizPrinter.h"

using namespace std;

void QuizPrinter::Print(Quiz quiz)
{
    cout << "\nQuiz creation complete!\n";
    cout << string(30, '=') << "\n";
    cout << "Summary:\n";
    cout << "- Quiz ID: " << quiz.getID() << "\n";
    cout << "- Title: " << quiz.getTitle() << "\n";
    cout << "- Questions: " << quiz.getNumberOfQuestions() << "\n";
    cout << "- Time limit: " << quiz.getTimeLimit() << " minutes\n";
    cout << string(30, '=') << "\n\n";
} 