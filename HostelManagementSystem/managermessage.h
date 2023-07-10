#ifndef MANAGERMESSAGE_H
#define MANAGERMESSAGE_H

#include "message.h"

class ManagerMessage: public Message
{
public:
    ManagerMessage();
    void WriteMessage(QPlainTextEdit *) override;
    void ReadMessage(QPlainTextEdit *) override;
};

#endif // MANAGERMESSAGE_H
