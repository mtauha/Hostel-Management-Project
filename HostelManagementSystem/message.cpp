#include "message.h"

Message::Message()
{
    SetFilePaths();
}

void Message::SetFilePaths()
{
    ComplainFile.setFileName("F:/NUST/SECOND SEMESTER/OBJECT ORIENTED PROGRAMMING/PROJECT/Semester Project/HostelManagementSystem/Text Files/Complains.txt");
    AnnouncementFile.setFileName("F:/NUST/SECOND SEMESTER/OBJECT ORIENTED PROGRAMMING/PROJECT/Semester Project/HostelManagementSystem/Text Files/Announcements.txt");
}

void Message::ReadMessage(QPlainTextEdit*)
{

}

void Message::WriteMessage(QPlainTextEdit*)
{

}

bool Message :: CreateWarning(QString SetText, QString informativeText, int i){
    QMessageBox *warningMessage = new QMessageBox();
    warningMessage->setGeometry(600, 200, 300, 200);
    warningMessage->setStyleSheet("QMessageBox{background-image:url(F:/Untitled-1.png)}");
    warningMessage->setText(SetText);
    warningMessage->setInformativeText(informativeText);
    if(i==1)
        warningMessage->setIcon(QMessageBox::Warning);
    else if(i==2)
        warningMessage->setIcon(QMessageBox::Critical);
    else if(i == 3)
        warningMessage->setIcon(QMessageBox::Question);
    warningMessage->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    int Option = warningMessage->exec();
    if(Option == QMessageBox::Yes)
        return true;
    else if(Option == QMessageBox::No)
        return false;
}

Message::~Message()
{

}
