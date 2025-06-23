#include "StudentActionFactory.h"
#include "StudentMainMenuChoices.h"
#include "AvailableQuizzes.h"
#include "StartNewQuiz.h"
#include "PreviousResults.h"
#include "ReviewSolvedQuiz.h"
StudentAction *StudentActionFactory::Create(StudentMenuOptions option) {
    switch (option) {
        case available_quizzes:
            return new AvailableQuizzes();
        case start_new_quiz:
            return new StartNewQuiz();
        case view_previous_results:
            return new PreviousResults();
        case review_solved_quiz:
            return new ReviewSolvedQuiz();
        default:
            return nullptr;
    }
} 