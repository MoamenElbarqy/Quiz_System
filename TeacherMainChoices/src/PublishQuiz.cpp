#include "PublishQuiz.h"
#include "Global.h"

void PublishQuiz::ShowSuccessfulPublishMessage() {
    cout << "\n========================================\n";
    cout << " Quiz Published Successfuly :-) \n";
    cout << "========================================\n";
}

void PublishQuiz::ShowFailedPublishMessage() {
    cout << "\n==================================================\n";
    cout << " Quiz Not Found In Your Quizzes Dr\\" + SystemUser->getFullName() + "\n";
    cout << "==================================================\n";
}

void PublishQuiz::Show() {
    system("cls");

    ScreenHeader::DrawHeader("\t Publish Quiz Screen ");

    cout << "Please Enter Quiz ID You Want To Publish : ";
    string quizID = Input::ReadString();

    vector<Quiz> DraftedQuizzes = QuizFileManger::LoadDraftedQuizzes();

    for (int i = 0; i < int(DraftedQuizzes.size()); i++) {
        if (DraftedQuizzes[i].getID() == quizID && SystemUser->getFullName() == DraftedQuizzes[i].getCreatedBy()) {
            QuizFileManger::AddToPublished(DraftedQuizzes[i]);
            DraftedQuizzes.erase(DraftedQuizzes.begin() + i);
            QuizFileManger::LoadDataToDrafted(DraftedQuizzes);
            ShowSuccessfulPublishMessage();
            return;
        }
    }
    ShowFailedPublishMessage();
}
