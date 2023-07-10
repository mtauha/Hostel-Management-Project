#ifndef MESS_H
#define MESS_H

#include <QTableView>
#include <QPlainTextEdit>
#include "message.h"

class Mess
{
protected:


public:
    Mess();
    //virtual ~Mess()
    void MessMenu(QTableView *);
    void MessTimings(QTableView *);
    virtual void ChangeMenu(QPlainTextEdit *);
};

#endif // MESS_H
