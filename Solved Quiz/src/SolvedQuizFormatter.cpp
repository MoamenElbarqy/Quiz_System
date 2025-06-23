#include <string>
#include <vector>
#include "SolvedQuizFormatter.h"
#include "Global.h"
#include "Util.h"
#include "stdexcept"

using namespace std;
string SolvedQuizFormatter::ConvertSolvedQuizToLine(SolvedQuiz solvedQuiz) {
    string result = solvedQuiz.getQuizID() + DELIMITER +
                    to_string(solvedQuiz.getScore()) + DELIMITER +
                    solvedQuiz.getStudentName() + DELIMITER;
    for (int answer: solvedQuiz.getStudentAnswers()) {
        result += to_string(answer) + DELIMITER;
    }
    return result.substr(0, result.length() - DELIMITER.length());
}
SolvedQuiz SolvedQuizFormatter::ConvertDataToSolvedQuizObject(string line) {
    vector<string> parts = Util::SplitRecord(line, DELIMITER);
    if (parts.size() < 7) {
        throw runtime_error("Invalid solved quiz format");
    }
    string quizId = parts[0];
    int score = stoi(parts[1]);
    string studentName = parts[2];
    vector<int> studentAnswers;
    for (size_t i = 3; i < parts.size(); i++) {
        studentAnswers.push_back(stoi(parts[i]));
    }
    return SolvedQuiz(quizId, score, studentName, studentAnswers);
} 