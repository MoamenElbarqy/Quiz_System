#include "DeleteQuiz.h"
#include "Global.h"

void DeleteQuiz::ShowSuccessDeletionMessage() {
    cout << "\n========================================\n";
    cout << " Quiz Deleted Successfuly :-) \n";
    cout << "========================================\n";
}

void DeleteQuiz::ShowFailedDeletionMessage() {
    cout << "\n=====================================================\n";
    cout << " Quiz Not Found In Your Quizzes Dr\\" + SystemUser->getFullName() + "\n";
    cout << "=====================================================\n";
}

bool DeleteQuiz::DeleteFromPublishedQuizzes()
{
    cout << "Please Enter Quiz ID You Want To Delete : ";

    string quizID = Input::ReadString();
    vector<Quiz> PublishedQuizzes = QuizFileManger::LoadPublishedQuizzes();
    for (int i = 0; i < int(PublishedQuizzes.size()); i++) {
        if (PublishedQuizzes[i].getID() == quizID && SystemUser->getFullName() == PublishedQuizzes[i].
            getCreatedBy()) {
            QuizFileManger::AddToDeleted(PublishedQuizzes[i]);
            PublishedQuizzes.erase(PublishedQuizzes.begin() + i);
            QuizFileManger::LoadDataToPublished(PublishedQuizzes);
            return true;
        }
    }
    return false;
}

bool DeleteQuiz::DeleteFromDraftedQuizzes() {
    cout << "Please Enter Quiz ID You Want To Delete : ";

    string quizID = Input::ReadString();
    vector<Quiz> DraftedQuizzes = QuizFileManger::LoadDraftedQuizzes();
    for (int i = 0; i < int(DraftedQuizzes.size()); i++) {
        if (DraftedQuizzes[i].getID() == quizID && SystemUser->getFullName() == DraftedQuizzes[i].
            getCreatedBy()) {
            QuizFileManger::AddToDeleted(DraftedQuizzes[i]);
            DraftedQuizzes.erase(DraftedQuizzes.begin() + i);
            QuizFileManger::LoadDataToDrafted(DraftedQuizzes);
            return true;
        }
    }
    return false;
}

void DeleteQuiz::Show() {
    system("cls");
    ScreenHeader::DrawHeader("\t Delete Quiz Screen ");

    cout << "You Want To Delete Drafed [1] Quiz Or Published Quiz [2] : ";

    int choice = Input::ReadNumberBetween(1, 2);

    switch (choice) {
        case 1:
            if (DeleteFromDraftedQuizzes())
                ShowSuccessDeletionMessage();
            else
                ShowFailedDeletionMessage();
            break;

        case 2:
            if (DeleteFromPublishedQuizzes())
                ShowSuccessDeletionMessage();
            else
                ShowFailedDeletionMessage();
            break;
    }
}
