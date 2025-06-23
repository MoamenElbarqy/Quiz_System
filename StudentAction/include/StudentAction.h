#pragma once

class StudentAction {
public:
    virtual ~StudentAction() = default;
    virtual void Show() = 0;
};
