#include "RegisterActionFactory.h"
#include "StudentRegister.h"
#include "TeacherRegister.h"

PersonRegister *RegisterActionFactory::Create(RegisterChoices option) {
    switch (option) {
        case student_register:
            return new StudentRegister();
        case teacher_register:
            return new TeacherRegister();
        default:
            return nullptr;
    }
}
