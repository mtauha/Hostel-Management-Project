#include "managermessage.h"

ManagerMessage::ManagerMessage()
{

}

void ManagerMessage::ReadMessage(QPlainTextEdit *WCB)
{
    ComplainFile.open(QIODevice::ReadOnly);
    QTextStream readcomplain(&ComplainFile);
    QString Ann = readcomplain.readAll();
    ComplainFile.close();
    WCB->setPlaceholderText(Ann);
}

void ManagerMessage::WriteMessage(QPlainTextEdit *AB)
{
    AnnouncementFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream readComplain(&AnnouncementFile);
    QString PreviousComplains = readComplain.readAll();
    AnnouncementFile.close();


    AnnouncementFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QString endOfComplain = "\n<-------------------->\n\n";
    QTextStream write(&AnnouncementFile);
    QString currentComplain = AB->toPlainText();
    QString currentComplainSUbject = AB->toPlainText();
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString currentDateTimeString = currentDateTime.toString(Qt::ISODate);
    currentDateTimeString.remove(10,1);
    currentDateTimeString.insert(10, '\t');
    write  <<"TIME     : "  << currentDateTimeString
           <<"\nSUBJECT  : "<<currentComplainSUbject
           <<"\nCOMPLAIN : "<< currentComplain << endOfComplain
           << PreviousComplains;
            AnnouncementFile.flush();
    AnnouncementFile.close();



}
