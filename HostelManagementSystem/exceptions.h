#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <QString>
#include <cstdbool>
#include <QPlainTextEdit>
#include <iostream>
#include <QRegularExpression>


class Exceptions
{
public:
    Exceptions();
    bool CheckAllExceptions(QString, QString, QPlainTextEdit*);
};

#endif // EXCEPTIONS_H
