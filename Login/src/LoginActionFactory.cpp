#include "LoginActionFactory.h"
#include "PersonLogin.h"
#include"StudentLogin.h"
#include "TeacherLogin.h"

PersonLogin *LoginActionFactory::Create(LoginOptions option) {
    switch (option) {
        case student_login:
            return new StudentLogin();
        case teacher_login:
            return new TeacherLogin();
        default:
            return nullptr;
    }
} 