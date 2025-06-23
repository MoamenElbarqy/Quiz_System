#include <fstream>
#include <stdexcept>
#include "QuizFileManger.h"

#include <QuizCleaner.h>

#include "Global.h"
#include "QuizFormatter.h"
#include "Util.h"
using namespace std;

Quiz *QuizFileManger::Find(string QuizID, string fileName) {
    fstream myFile;
    myFile.open(fileName, ios::in);
    if (!myFile.is_open())
        throw std::runtime_error("Error: Could not open" + fileName);
    string line;
    while (getline(myFile, line)) {
        if (line.empty())
            continue;
        vector<string> quizInfo = Util::SplitRecord(line);
        if (quizInfo[0] == QuizID) {
            myFile.close();
            return QuizFormatter::ConvertDataToQuizObject(quizInfo);
        }
    }
    myFile.close();
    return nullptr;
}

vector<Quiz> QuizFileManger::LoadQuizzesData(string fileName) {
    vector<Quiz> quizzes;
    fstream myFile;

    myFile.open(fileName, ios::in);

    if (!myFile.is_open())
        throw runtime_error("Can't Open " + fileName);

    string line;

    while (getline(myFile, line)) {
        if (line.empty())
            continue;

        vector<string> quizData = Util::SplitRecord(line);
        Quiz *quiz = QuizFormatter::ConvertDataToQuizObject(quizData);
        quizzes.push_back(*quiz);
        QuizCleaner::CleanUp(quiz);
    }
    myFile.close();
    return quizzes;
}

void QuizFileManger::LoadDataToFile(vector<Quiz> quizzes, string fileName) {
    fstream myFile;
    myFile.open(fileName, ios::out);
    if (!myFile.is_open())
        throw runtime_error("Error: Unable to open " + fileName + " for writing");
    for (Quiz &quiz: quizzes) {
        myFile << QuizFormatter::ConvertQuizDataToLine(quiz) << "\n";
    }
    myFile.close();
}

void QuizFileManger::AddToFile(string fileName, Quiz quiz) {
    fstream myFile;
    myFile.open(fileName, ios::app);
    if (!myFile.is_open())
        throw runtime_error("Error: Unable to open " + fileName);
    myFile << QuizFormatter::ConvertQuizDataToLine(quiz) << "\n";
    myFile.close();
}

Quiz *QuizFileManger::FindInPublished(string QuizID) { return Find(QuizID, PUBLISHED_QUIZZES_FILE); }
Quiz *QuizFileManger::FindInDrafted(string QuizID) { return Find(QuizID, DRAFTED_QUIZZES_FILE); }
Quiz *QuizFileManger::FindInDeleted(string QuizID) { return Find(QuizID, DELETED_QUIZZES_FILE); }
void QuizFileManger::LoadDataToPublished(vector<Quiz> quizzes) { LoadDataToFile(quizzes, PUBLISHED_QUIZZES_FILE); }
void QuizFileManger::LoadDataToDrafted(vector<Quiz> quizzes) { LoadDataToFile(quizzes, DRAFTED_QUIZZES_FILE); }
void QuizFileManger::LoadDataToDeleted(vector<Quiz> quizzes) { LoadDataToFile(quizzes, DELETED_QUIZZES_FILE); }
void QuizFileManger::AddToDrafted(Quiz quiz) { AddToFile(DRAFTED_QUIZZES_FILE, quiz); }
void QuizFileManger::AddToPublished(Quiz quiz) { AddToFile(PUBLISHED_QUIZZES_FILE, quiz); }
void QuizFileManger::AddToDeleted(Quiz quiz) { AddToFile(DELETED_QUIZZES_FILE, quiz); }
vector<Quiz> QuizFileManger::LoadDraftedQuizzes() { return LoadQuizzesData(DRAFTED_QUIZZES_FILE); }
vector<Quiz> QuizFileManger::LoadPublishedQuizzes() { return LoadQuizzesData(PUBLISHED_QUIZZES_FILE); }
vector<Quiz> QuizFileManger::LoadDeletedQuizzes() { return LoadQuizzesData(DELETED_QUIZZES_FILE); }
