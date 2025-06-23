#include <iostream>
#include "StartNewQuiz.h"
#include "SolvedQuiz.h"
#include "Global.h"
#include "SolvedQuizRepository.h"
#include "QuizFileManger.h"
#include "Quiz.h"
#include "Input.h"
#include "ScreenHeader.h"
#include "QuizCleaner.h"

using namespace std;

bool StartNewQuiz::isSolved(string QuizID) {
    SolvedQuiz *curQuiz = SolvedQuizRepository::Find(QuizID, SystemUser->getFullName());
    if (!curQuiz)
        return false;
    return true;
}

void StartNewQuiz::ShowQuizResults(int stundetMarks, int ExamTotalMarks, char studentGrade, bool passed) {
    cout << "\n=====================================\n";
    cout << " Test Done!\n";
    cout << " Your Mark : " << stundetMarks << " / " << ExamTotalMarks << "\n";
    cout << " Your Grade : " << studentGrade << "\n";
    if (passed)
        cout << "Congratulations You Passed The Exam\n";
    else
        cout << "Sorry For Telling You, You Failed\n";
    cout << "=====================================\n";
}

void StartNewQuiz::SavingQuizResults(string &QuizID, int &stundetScore, string studentName,
                                     vector<int> &stundetAnswers) {
    SolvedQuiz studentSolvedQuiz(QuizID, stundetScore, studentName, stundetAnswers);
    SolvedQuizRepository::AddToFile(studentSolvedQuiz);
}

void StartNewQuiz::SolvingQuiz(string QuizID) {
    system("cls");

    Quiz *StudentQuiz = QuizFileManger::FindInPublished(QuizID);
    ScreenHeader::DrawHeader("\t" + StudentQuiz->getTitle());

    int rightAnswers = 0;
    vector<int> studentAnswers;

    vector<Question> questions = StudentQuiz->getQuestions();

    for (int i = 0; i < StudentQuiz->getNumberOfQuestions(); i++) {
        cout << questions[i].getQuestionTitle() << "\n";
        cout << "----------------------\n\n";

        vector<string> choices = questions[i].getChoices();

        for (int j = 0; j < questions[i].getNumberOfChoices(); j++)
            cout << j + 1 << ". " << choices[j] << "\n";

        cout << "\nYour Answer is: ";
        int studentAnswer = Input::ReadNumberBetween(1, questions[i].getNumberOfChoices());

        studentAnswers.push_back(studentAnswer);

        if (studentAnswer == questions[i].getTrueChoiceOrder())
            rightAnswers++;
        cout << "\n==============================\n";
    }
    int stundetMarks = rightAnswers * StudentQuiz->getDegreesPerQuestion();
    char grade = StudentQuiz->getQuizGrade(stundetMarks);
    bool passed = StudentQuiz->isPassed(stundetMarks);

    ShowQuizResults(stundetMarks, StudentQuiz->getTotalQuizDegrees(), grade, passed);
    SavingQuizResults(QuizID, stundetMarks, SystemUser->getFullName(), studentAnswers);
    QuizCleaner::CleanUp(StudentQuiz);
}

void StartNewQuiz::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Start New Quiz Screen");
    cout << "Please Enter Quiz ID: ";
    string QuizID = Input::ReadString();
    if (isSolved(QuizID)) {
        cout << "\n=====================================\n";
        cout << " You Solved This Quiz Before :-)\n";
        cout << "=====================================\n";
        return;
    }
    Quiz *studnetQuiz = QuizFileManger::FindInPublished(QuizID);
    if (!studnetQuiz) {
        cout << "\n=============================================\n";
        cout << " Quiz ID is Wrong, Check The Quiz ID again  :-)\n";
        cout << "=============================================\n";
        return;
    }
    SolvingQuiz(QuizID);
}
