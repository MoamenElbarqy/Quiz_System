#include "SolvedQuiz.h"

SolvedQuiz::SolvedQuiz(string id, int score, string studentName, vector<int> &studentAnswers)
    : quizID(id), score(score), studentName(studentName), studentAnswers(studentAnswers){}


string SolvedQuiz::getQuizID() { return quizID; }
int SolvedQuiz::getScore() { return score; }
string SolvedQuiz::getStudentName() { return studentName; }
vector<int> SolvedQuiz::getStudentAnswers() { return studentAnswers; } 