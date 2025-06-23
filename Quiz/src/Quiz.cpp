#include <string>
#include <vector>
#include "Quiz.h"
using namespace std;
Quiz::Quiz(string id, string title, int number, int time, int degreesPerQuestion, string createdBy, vector<Question> questions)

     : QuizID(id), Title(title), NumberOfQuestions(number), TimeLimit(time),
      DegreesPerQuestion(degreesPerQuestion), CreatedBy(createdBy), Questions(questions) {}
bool Quiz::isPassed(int studentDegree)
{
    int total = getTotalQuizDegrees();
    if (total == 0) return false;
    float percentage = (float)studentDegree / total * 100;
    return percentage >= 50;
}
int Quiz::getTotalQuizDegrees() { return DegreesPerQuestion * NumberOfQuestions; }
int Quiz::getNumberOfQuestions() { return NumberOfQuestions; }
string Quiz::getID() { return QuizID; }
string Quiz::getCreatedBy() { return CreatedBy; }
int Quiz::getTimeLimit() { return TimeLimit; }
string Quiz::getTitle() { return Title; }
vector<Question> Quiz::getQuestions() { return Questions; }
int Quiz::getDegreesPerQuestion() { return DegreesPerQuestion; }

char Quiz::getQuizGrade(int stundetMarks)
{
    int stundetPercentage = stundetMarks * 100 / getTotalQuizDegrees();
    if (stundetPercentage >= 90)
        return 'A';
    else if (stundetPercentage >= 80)
        return 'B';
    else if (stundetPercentage >= 70)
        return 'C';
    else if (stundetPercentage >= 50)
        return 'D';
    return 'F';
} 