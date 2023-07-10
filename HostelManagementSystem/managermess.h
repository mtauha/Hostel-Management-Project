#ifndef MANAGERMESS_H
#define MANAGERMESS_H

#include "mess.h"

class ManagerMess:public Mess
{
public:
    ManagerMess();
    void ChangeMenu(QPlainTextEdit *) override;

};

#endif // MANAGERMESS_H
