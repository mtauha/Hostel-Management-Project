#include "studentmessage.h"

StudentMessage::StudentMessage()
{

}

void StudentMessage::WriteMessage(QPlainTextEdit *WCB)
{
    ComplainFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream readComplain(&ComplainFile);
    QString PreviousComplains = readComplain.readAll();
    ComplainFile.close();


    ComplainFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QString endOfComplain = "\n<-------------------->\n\n";
    QTextStream write(&ComplainFile);
    QString currentComplain = WCB->toPlainText();
    QString currentComplainSUbject = WCB->toPlainText();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString(Qt::ISODate);
    currentDateTimeString.remove(10,1);
    currentDateTimeString.insert(10, '\t');
    write  <<"TIME     : "  << currentDateTimeString
           <<"\nSUBJECT  : "<<currentComplainSUbject
           <<"\nCOMPLAIN : "<< currentComplain << endOfComplain
           << PreviousComplains;
            ComplainFile.flush();
    ComplainFile.close();
}

void StudentMessage::ReadMessage(QPlainTextEdit *AB)
{
    AnnouncementFile.open(QIODevice::ReadOnly);
    QTextStream readAnnouncement(&AnnouncementFile);
    QString Ann = readAnnouncement.readAll();
    AnnouncementFile.close();
    AB->setPlainText(Ann);
}
