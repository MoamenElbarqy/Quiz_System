#include "EditDraftQuiz.h"
#include "Global.h"

void EditDraftQuiz::ShowSuccessEditingMessage() {
    cout << "\n========================================\n";
    cout << " Quiz Edited Successfuly :-) \n";
    cout << "========================================\n";
}

void EditDraftQuiz::ShowFailedEditingMessage() {
    cout << "\n==================================================\n";
    cout << " Quiz Not Found In Your Quizzes Dr\\" + SystemUser->getFullName() + "\n";
    cout << "==================================================\n";
}

void EditDraftQuiz::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Edit Draft Quiz Screen ");

    cout << "Please Enter Quiz ID You Want To Edit : ";
    string quizID = Input::ReadString();

    vector<Quiz> DraftedQuizzes = QuizFileManger::LoadDraftedQuizzes();
    for (int i = 0; i < int(DraftedQuizzes.size()); i++) {
        if (DraftedQuizzes[i].getID() == quizID && SystemUser->getFullName() == DraftedQuizzes[i].getCreatedBy()) {
            Quiz newQuiz = QuizInputForm::ReadQuizInfo();
            DraftedQuizzes[i] = newQuiz;
            QuizFileManger::LoadDataToDrafted(DraftedQuizzes);

            ShowSuccessEditingMessage();
            return;
        }
    }

    ShowSuccessEditingMessage();
}
