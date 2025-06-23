#include <iomanip>
#include "AvailableQuizzes.h"
#include <iostream>
#include "ScreenHeader.h"
#include "QuizFileManger.h"

using namespace std;
void AvailableQuizzes::ShowTableHeader() {
    cout <<
        "\t--------------------------------------------------------------------------------------------------------------\n";
    cout << "\t|    ID    |          Title            |  No. of Qs. | Total Quiz Degrees |     Publisher        \n";
    cout <<
        "\t--------------------------------------------------------------------------------------------------------------\n";
}
void AvailableQuizzes::ShowTableRows(vector<Quiz> &vec) {
    for (Quiz quiz: vec) {
        cout << "\t|" << setw(10) << left << quiz.getID();
        cout << "|" << setw(27) << left << quiz.getTitle();
        cout << "|" << setw(13) << left << quiz.getNumberOfQuestions();
        cout << "|" << setw(20) << left << quiz.getTotalQuizDegrees();
        cout << "|" << setw(22) << left << quiz.getCreatedBy();
        cout << endl;
    }
}
void AvailableQuizzes::ShowTableFooter() {
    cout <<
        "\t--------------------------------------------------------------------------------------------------------------\n";
}
void AvailableQuizzes::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Available Quizzes Screen");
    ShowTableHeader();
    vector<Quiz> PublishedQuizzes = QuizFileManger::LoadPublishedQuizzes();
    ShowTableRows(PublishedQuizzes);
    ShowTableFooter();
} 