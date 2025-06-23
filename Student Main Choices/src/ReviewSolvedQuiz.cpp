#include <iostream>
#include "ScreenHeader.h"
#include "Quiz.h"
#include "QuizFileManger.h"
#include "SolvedQuiz.h"
#include "SolvedQuizRepository.h"
#include "Input.h"
#include "ReviewSolvedQuiz.h"
#include "GLobal.h"

using namespace std;

void ReviewSolvedQuiz::ReviewQuestions(const vector<Question> &questions, const vector<int> &studentAnswers) {
    for (size_t i = 0; i < questions.size(); i++) {
        Question currentQuestion = questions[i];
        cout << "\nQuestion " << i + 1 << ": " << currentQuestion.getQuestionTitle() << "\n";
        cout << "----------------------\n";
        vector<string> choices = currentQuestion.getChoices();
        for (int j = 0; j < currentQuestion.getNumberOfChoices(); j++) {
            cout << j + 1 << ". " << choices[j] << "\n";
        }
        string studentAnswer = choices[studentAnswers[i] - 1];
        cout << "\nYour answer: " << studentAnswer << "\n";
        string correctAnswer = choices[currentQuestion.getTrueChoiceOrder() - 1];
        cout << "Correct answer: " << correctAnswer << "\n";
        if (studentAnswer == correctAnswer) {
            cout << "Status: CORRECT \n";
        } else {
            cout << "Status: INCORRECT\n";
        }
        cout << "==============================\n";
    }
}

void ReviewSolvedQuiz::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Review Solved Quiz Screen");
    cout << "Please Enter Quiz ID You Have Solved To Review: ";
    string QuizId = Input::ReadString();
    SolvedQuiz *studentQuiz = SolvedQuizRepository::Find(QuizId, SystemUser->getFullName());
    if (!studentQuiz) {
        cout << "\n==================================================\n";
        cout << " The ID is Invalid or You Didn't Solve This Quiz Yet\n";
        cout << "==================================================\n";
        return;
    }
    Quiz *QuizInPublished = QuizFileManger::FindInPublished(studentQuiz->getQuizID());
    Quiz *QuizInDeleted = QuizFileManger::FindInDeleted(studentQuiz->getQuizID());
    if (QuizInPublished && QuizInDeleted)
        throw runtime_error("Invalid Quiz");

    Quiz *origianlQuiz = !QuizInPublished ? QuizInDeleted : QuizInPublished;
    cout << "\nQuiz Review for: " << origianlQuiz->getTitle() << "\n";
    cout << "========================================\n";
    cout << "Total Questions: " << origianlQuiz->getNumberOfQuestions() << "\n";
    cout << "Your Score: " << studentQuiz->getScore() << "/" << origianlQuiz->getTotalQuizDegrees() << "\n";
    cout << "========================================\n\n";
    ReviewQuestions(origianlQuiz->getQuestions(), studentQuiz->getStudentAnswers());
    cout << "\nReview complete.\n";
}
