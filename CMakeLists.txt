cmake_minimum_required(VERSION 3.20)
project(Quiz_System)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        "${CMAKE_CURRENT_SOURCE_DIR}/Login/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/MainMenu/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Misc/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Person/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Question/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Quiz/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Quiz System/includes"
        "${CMAKE_CURRENT_SOURCE_DIR}/Register/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Solved Quiz/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Student/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Student Main Choices/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/StudentAction/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/Teacher/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/TeacherAction/include"
        "${CMAKE_CURRENT_SOURCE_DIR}/TeacherMainChoices/include"
)
add_executable(Quiz_System main.cpp
        Register/src/RegisterMenuReseter.cpp
        Misc/src/Global.cpp
        Login/src/LoginActionCleaner.cpp
        Login/src/LoginActionFactory.cpp
        Login/src/Login.cpp
        Login/src/StudentLogin.cpp
        Login/src/TeacherLogin.cpp
        Login/src/LoginMenuReseter.cpp
        Login/src/LoginActionPerformer.cpp
        MainMenu/src/MainActionCleaner.cpp
        MainMenu/src/MainMenu.cpp
        MainMenu/src/MainActionFactory.cpp
        MainMenu/src/MainMenuReseter.cpp
        MainMenu/src/MainActionPerformer.cpp
        Misc/src/ScreenHeader.cpp
        Misc/src/Util.cpp
        Misc/src/Input.cpp
        Person/src/Person.cpp
        Question/src/Question.cpp
        Question/src/QuestionFormatter.cpp
        Question/src/QuestionInputForm.cpp
        Register/src/RegisterActionCleaner.cpp
        Register/src/Register.cpp
        Register/src/RegisterActionPerformer.cpp
        Register/src/RegisterActionFactory.cpp
        Register/src/TeacherRegister.cpp
        Register/src/StudentRegister.cpp
        "Solved Quiz/src/SolvedQuizFormatter.cpp"
        "Solved Quiz/src/SolvedQuiz.cpp"
        "Solved Quiz/src/SolvedQuizRepository.cpp"
        Teacher/src/TeacherFileManger.cpp
        Teacher/src/TeacherFormatter.cpp
        Teacher/src/TeacherMainMenu.cpp
        Teacher/src/Teacher.cpp
        Teacher/src/TeacherInputForm.cpp
        StudentAction/src/StudentMenuReseter.cpp
        "StudentAction/src/StudentActionPerformer.cpp"
        "StudentAction/src/StudentActionFactory.cpp"
        "StudentAction/src/StudentActionCleaner.cpp"
        "Student Main Choices/src/AvailableQuizzes.cpp"
        "Student Main Choices/src/PreviousResults.cpp"
        "Student Main Choices/src/ReviewSolvedQuiz.cpp"
        "Student Main Choices/src/StartNewQuiz.cpp"

        "TeacherAction/src/TeacherMenuReseter.cpp"
        "TeacherAction/src/TeacherActionFactory.cpp"
        "TeacherAction/src/TeacherActionPerformer.cpp"
        "TeacherAction/src/TeacherActionCleaner.cpp"
        "TeacherMainChoices/src/PublishQuiz.cpp"
        "TeacherMainChoices/src/DeleteQuiz.cpp"
        "TeacherMainChoices/src/EditDraftQuiz.cpp"
        "TeacherMainChoices/src/CreateNewQuiz.cpp"
        "TeacherMainChoices/src/CreateNewQuiz.cpp"
        "Student/src/StudentFileManger.cpp"
        "Student/src/StudentInputForm.cpp"
        "Quiz/src/QuizFileManger.cpp"
        "Quiz/src/QuizInputForm.cpp"
        "Student/src/StudentMainMenu.cpp"
        "Student/src/Student.cpp"
        "Student/src/StudentFormatter.cpp"
        "Quiz/src/Quiz.cpp"
        "Quiz/src/QuizFormatter.cpp"
        "Quiz/src/QuizPrinter.cpp"
        Quiz/src/QuizCleaner.cpp
        Teacher/src/TeacherCleaner.cpp
        Student/src/StudentCleaner.cpp
        Person/src/PersonCleaner.cpp

)
