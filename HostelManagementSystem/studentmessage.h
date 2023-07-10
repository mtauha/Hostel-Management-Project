#ifndef STUDENTMESSAGE_H
#define STUDENTMESSAGE_H

#include "message.h"

class StudentMessage : public Message
{
public:
    StudentMessage();
    void WriteMessage(QPlainTextEdit *) override;
    void ReadMessage(QPlainTextEdit *) override;
};

#endif // STUDENTMESSAGE_H
