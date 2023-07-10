#ifndef STUDENTMESS_H
#define STUDENTMESS_H

#include "mess.h"

class StudentMess:public Mess
{
public:
    StudentMess();
    void ChangeMenu(QPlainTextEdit *) override;
};

#endif // STUDENTMESS_H
