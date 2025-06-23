#include "TeacherActionFactory.h"
#include "CreateNewQuiz.h"
#include "EditDraftQuiz.h"
#include "PublishQuiz.h"
#include "DeleteQuiz.h"

TeacherAction *TeacherActionFactory::Create(TeacherMenuOptions option) {
    switch (option) {
        case create_quiz:
            return new CreateNewQuiz();
        case edit_draft_quiz:
            return new EditDraftQuiz();
        case publish_quiz:
            return new PublishQuiz();
        case delete_quiz:
            return new DeleteQuiz();
        case teacher_menu_exit:
            return nullptr;
        default:
            return nullptr;
    }
} 