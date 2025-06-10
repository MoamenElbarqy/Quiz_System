#pragma once
#include "HeaderScreen.h"
class ReviewSolvedQuiz :private HeaderScreen
{
private:
    static void DisplayQuestionWithAnswers(Quiz& quiz, SolvedQuiz& solvedQuiz, int questionIndex)
    {
        vector<string> questionsTitles = quiz.getQuestionsTitles();
        vector<string> questionsDetails = quiz.getQuestionsDetails();
        vector<int> modelAnswers = quiz.getModelAnswer();
        vector<int> studentAnswers = solvedQuiz.getStudentAnswers();

        // Display question title
        cout << "\nQuestion " << questionIndex + 1 << ": " << questionsTitles[questionIndex] << "\n";

        // Display all choices
        int choicesStart = questionIndex * 4;
        for (int i = 0; i < 4; i++)
        {
            cout << "  " << i + 1 << ") " << questionsDetails[choicesStart + i] << "\n";
        }

        // Display student's answer
        int studentAnswer = studentAnswers[questionIndex];
        cout << "\nYour answer: " << studentAnswer << "\n";

        // Display correct answer
        int correctAnswer = modelAnswers[questionIndex];
        cout << "Correct answer: " << correctAnswer << "\n";

        // Show if answer was correct
        if (studentAnswer == correctAnswer)
        {
            cout << "Status: CORRECT (" << quiz.getQsDegree() << " points)\n";
        }
        else
        {
            cout << "Status: INCORRECT (0 points)\n";
        }

        cout << "----------------------------------------\n";
    }

public:
    static void Show()
    {
        system("cls");
        DrawScreenHeader("\t Review Solved Quiz Screen");

        cout << "Please Enter Quiz ID You Have Solved To Review: ";
        string QuizId = Input::ReadString();

        SolvedQuiz studentQuiz = SolvedQuiz::Find(QuizId, SystemUser->getFullName());

        if (studentQuiz.isEmpty())
        {
            cout << "\n==================================================\n";
            cout << " The ID is Invalid or You Didn't Solve This Quiz Yet\n";
            cout << "==================================================\n";
            return;
        }

        // Try to find quiz in published first, then in deleted
        Quiz QuizInPublished = Quiz::FindInPublished(studentQuiz.getQuizID());
        Quiz QuizInDeleted = Quiz::FindInDeleted(studentQuiz.getQuizID());
        Quiz RealQuiz = QuizInPublished.isEmpty() ? QuizInDeleted : QuizInPublished;

        if (RealQuiz.isEmpty())
        {
            cout << "\n========================================\n";
            cout << " Quiz Not Found (May Have Been Deleted)\n";
            cout << "========================================\n";
            return;
        }

        // Display quiz summary
        cout << "\nQuiz Review for: " << RealQuiz.getTitle() << "\n";
        cout << "========================================\n";
        cout << "Total Questions: " << RealQuiz.getNumberOfQs() << "\n";
        cout << "Points per Question: " << RealQuiz.getQsDegree() << "\n";
        cout << "Your Score: " << studentQuiz.getScore() << "/" << studentQuiz.getTotalMarks() << "\n";
        cout << "Result: " << studentQuiz.getResultStatus() << "\n";
        cout << "Grade: " << studentQuiz.getGrade() << "\n";
        cout << "========================================\n\n";

        // Display each question with answers
        for (int i = 0; i < RealQuiz.getNumberOfQs(); i++)
        {
            DisplayQuestionWithAnswers(RealQuiz, studentQuiz, i);
        }

        cout << "\nReview complete.\n";
    }
};