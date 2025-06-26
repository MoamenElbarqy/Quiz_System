#include <iostream>
#include <iomanip>
#include "Screenheader.h"
#include "Quiz.h"
#include "QuizFileManger.h"
#include "PreviousResults.h"
#include "Global.h"
#include "SolvedQuizRepository.h"
#include "QuizCleaner.h"
using namespace std;

void PreviousResults::ShowTableHeader() {
    cout <<
            "\t--------------------------------------------------------------------------------------------\n";
    cout <<
            "\t|    ID    |         Quiz Title         |    Quiz Marks |  Your Score   |  Publisher     \n";
    cout <<
            "\t--------------------------------------------------------------------------------------------\n";
}

void PreviousResults::ShowTableRows(vector<SolvedQuiz> &vec)
{
    for (SolvedQuiz &solved_quiz: vec)
    {
        Quiz *QuizInPublished = QuizFileManger::FindInPublished(solved_quiz.getQuizID());
        Quiz *QuizInDeleted = QuizFileManger::FindInDeleted(solved_quiz.getQuizID());
        if (QuizInPublished && QuizInDeleted)
            throw runtime_error("Invalid Quiz");
        Quiz *RealQuiz = !QuizInPublished ? QuizInDeleted : QuizInPublished;
        cout << "\t|" << setw(10) << left << solved_quiz.getQuizID();
        cout << "|" << setw(28) << left << RealQuiz->getTitle();
        cout << "|" << setw(15) << left << RealQuiz->getTotalQuizDegrees();
        cout << "|" << setw(16) << left << solved_quiz.getScore();
        cout << "|" << setw(16) << left << RealQuiz->getCreatedBy();
        cout << endl;
        QuizCleaner::CleanUp(RealQuiz);
    }
}

void PreviousResults::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Previous Results Screen");
    ShowTableHeader();
    vector<SolvedQuiz> AllSolvedQuizzes = SolvedQuizRepository::LoadSolvedQuizzes();
    vector<SolvedQuiz> studentSolvedQuizzes;
    for (int i = 0; i < AllSolvedQuizzes.size(); i++) {
        if (AllSolvedQuizzes[i].getStudentName() == SystemUser->getFullName()) {
            studentSolvedQuizzes.push_back(AllSolvedQuizzes[i]);
        }
    }
    ShowTableRows(studentSolvedQuizzes);
    cout <<
            "\t----------------------------------------------------------------------------------------------------------------------\n";
}
