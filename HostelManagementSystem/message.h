#ifndef MESSAGE_H
#define MESSAGE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QPlainTextEdit>
#include <QDateTime>
#include <iostream>
#include <QResource>
#include <QMessageBox>
#include <cstdbool>

class Message
{
protected:
    QFile ComplainFile;
    QFile AnnouncementFile;
public:
    Message();
    virtual void WriteMessage(QPlainTextEdit *);
    virtual void ReadMessage(QPlainTextEdit *);
    virtual ~Message();
    void SetFilePaths();
    bool CreateWarning (QString SetText, QString informativeText, int Type);
};

#endif // MESSAGE_H
