#include "CreateNewQuiz.h"

void CreateNewQuiz::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Create Quiz Screen ");

    Quiz newQuiz = QuizInputForm::ReadQuizInfo();

    if (Util::ContinueOperation("Do You Want To Publish This Quiz To Students (y / n) : ")) {
        QuizFileManger::AddToPublished(newQuiz);
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << " The Quiz Published Successfully :-)\n";
        cout << setw(37) << left << "" << "===========================================\n";
    } else if (Util::ContinueOperation("Do You Want To Save This Quiz in Draft (y / n) : ")) {
        QuizFileManger::AddToDrafted(newQuiz);
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << " The Quiz Drafted Successfully :-)\n";
        cout << setw(37) << left << "" << "===========================================\n";
    } else {
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << " The Quiz Denied :-(\n";
        cout << setw(37) << left << "" << "===========================================\n";
    }
} 