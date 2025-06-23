#include <fstream>
#include <vector>
#include <string>
#include "SolvedQuizRepository.h"
#include "Global.h"
#include "SolvedQuizFormatter.h"
#include "Util.h"

using namespace std;
void SolvedQuizRepository::AddToFile(SolvedQuiz quiz) {
    fstream myFile(SOLVED_QUIZZES_FILE, ios::app);
    if (!myFile.is_open())
        throw runtime_error("Can't open " + SOLVED_QUIZZES_FILE);
    string line = SolvedQuizFormatter::ConvertSolvedQuizToLine(quiz);
    myFile << line << "\n";
    myFile.close();
}
vector<SolvedQuiz> SolvedQuizRepository::LoadSolvedQuizzes() {
    vector<SolvedQuiz> solvedQuizzes;
    fstream file(SOLVED_QUIZZES_FILE, ios::in);
    if (!file.is_open())
        throw runtime_error("Can't open " + SOLVED_QUIZZES_FILE);
    string line;
    while (getline(file, line)) {
        if (line.empty())
            continue;
        vector<string> data = Util::SplitRecord(line);
        string quizID = data[0];
        int score = stoi(data[1]);
        string studentName = data[2];
        vector<int> studentAnswers;
        for (int i = 3; i < int(data.size()); ++i) {
            studentAnswers.push_back(stoi(data[i]));
        }
        solvedQuizzes.push_back(SolvedQuiz(quizID, score, studentName, studentAnswers));
    }
    file.close();
    return solvedQuizzes;
}
vector<string> SolvedQuizRepository::GetSolvedQuizzesIDs() {
    fstream myFile;
    vector<string> solvedQuizzesIDs;
    myFile.open(SOLVED_QUIZZES_FILE, ios::in);
    if (!myFile.is_open())
        throw runtime_error("Can't open " + SOLVED_QUIZZES_FILE);
    string line;
    while (getline(myFile, line)) {
        if (line.empty())
            continue;
        vector<string> solvedQuizData = Util::SplitRecord(line);
        solvedQuizzesIDs.push_back(solvedQuizData[0]);
    }
    myFile.close();
    return solvedQuizzesIDs;
}
SolvedQuiz *SolvedQuizRepository::Find(string quizID, string studentName) {
    fstream file(SOLVED_QUIZZES_FILE, ios::in);
    if (!file.is_open())
        throw runtime_error("Error: Could not open " + SOLVED_QUIZZES_FILE);
    string line;
    while (getline(file, line)) {
        if (line.empty())
            continue;
        vector<string> data = Util::SplitRecord(line);
        if (data[0] == quizID && data[2] == studentName) {
            vector<int> studentAnswers;
            int index = 0;
            while (index < data.size() - 3) {
                studentAnswers.push_back(stoi(data[3 + index++]));
            }
            file.close();
            return new SolvedQuiz(data[0], stoi(data[1]), SystemUser->getFullName(), studentAnswers);
        }
    }
    file.close();
    return nullptr;
} 