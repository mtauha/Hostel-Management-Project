#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QComboBox>
#include <QPlainTextEdit>
#include <QGridLayout>
#include <QTextStream>
#include <QImage>
#include <QThread>
#include <QTimer>
#include <QDateTime>
#include <iostream>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCalendarWidget>
#include <QWidget>
#include <QFont>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QStackedWidget>
#include <QTableView>
#include "typeinfo"
#include "exceptions.h"
#include "nonClassFunctions.h"
#include "studentmessage.h"
#include "managermessage.h"
#include "query.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void ConnectDataBase();

    void CreateFirstPage();
    void CreateLoginPage(bool);
    void CreateStudentPage();
    void CreateManagerPage();
    void CreateApplyForRoomPage();
    void CreateMessOptionsPage();
    void CreateWriteMessagePage();
    void CreateReadMessagePage();
    void CreateAnotherMessagePage();
    void CreateAllocateRoomPage();
    void CreateAccountPage();


    void ClockSignal();
    QHBoxLayout* AddHorizontalLayout(QLabel*, QLineEdit*);

    void DeleteFirstPage();
    void DeleteLoginPage();
    void DeleteStudentPage(bool);
    void DeleteManagerPage(bool);
    void DeleteApplyForRoomPage();
    void DeleteMessOptionsPage();
    void DeleteReadMessagePage();
    void DeleteWriteMessagePage();
    void DeleteAnotherMessagePage();
    void DeleteAllocateRoomPage();
    void DeleteAccountPage();

    void DisplayRegistrationTable();


    void InitializeBackButton();
    void InitializeAccountButton();
    void InitializeMessageButtons();

private slots:
    void On_SubmitButton_Clicked();
    void On_LoginButtonOption_Clicked();
    void On_LoginButton_Clicked();
    void On_BackButton_Clicked(int);
    void On_AccountButton_Clicked(int);
    void ClockSlot();
    void On_LogOutButton_Clicked(int);
    void On_ExitButton_Clicked();
    void On_EditAccountButton_Clicked(int);
    void On_ApplyForRoomButton_Clicked();
    void On_AddPictureButton_Clicked();
    void On_MessOptionsButton_Clicked();
    void On_AllocateRoomButton_Clicked();
    void On_WriteMessageButton_Clicked(int);
    void On_ReadMessageButton_Clicked(int);
    void On_SendMessageButton_Clicked();
    void On_AnotherMessageButton_Clicked();
    void On_DateValue_Changed();
    //void On_WriteButton_Clicked();
    //void On_ReadButton_Clicked();

private:
    Ui::MainWindow *ui;

    QPixmap *BackGround;
    QSqlDatabase DB;
    QSqlQuery *Q;

    QPushButton *ApplyForRoomButton;
    QPushButton *LoginOptionButton;
    QLabel *TitleLabel;
    QPushButton *SubmitButton;
    QPlainTextEdit *ExceptionBox;

    QTimer *Clock;
    QTime time;
    QString TimeText;
    QLabel *TimeLabel;

    QLineEdit *PassWordLine;
    QLineEdit *UserNameLine;
    QLabel *PassWordLabel;
    QLabel *UserNameLabel;
    QGroupBox *LoginBox;
    QPushButton *LogInButton;
    QString UserNameText;
    QString PassWordText;
    QPushButton *ForgotPassword;

    QLabel *NewRegistrationLabels[10];
    QLineEdit *NewRegistrationLines[8];
    QComboBox *comboBox[4];
    QPushButton *AddPictureButton;

    QLabel *NameLabel;
    QPushButton *BackButton;
    QPushButton *StudentOptions[3];

    QPushButton *MessageButtons[2];
    QLabel *MessageSubjectLabel;
    QLabel *WriteMessageLabel;
    QPlainTextEdit *MessageSubject;
    QPlainTextEdit *WritingBox;
    QPlainTextEdit *ReadingBox;
    QPushButton *SendMessageButton;
    QPushButton *ManagerOptions[2];

    QPushButton *AnotherMessageButton;
    QLabel *MessageStatusLabel;


    QGroupBox *ManagerOptionBox;
    QPushButton *AccessStudentButton;
    QPushButton *DoMessOffButton;
    QPushButton *DoChangeRoomButton;

    QPushButton *AnnouncementButton;
    QPushButton *ExitButton;
    QPushButton *AccountButton;
    QPushButton *LogoutButton;
    QPushButton *EditAccountButton;

    QLabel *AccountInformationtitles[11];
    QLineEdit *AccountInformationValues[11];
    QPushButton *ChangePassWord;

    QPushButton *MessOptions[3];
    QStackedWidget *MessStack;
    QStackedWidget *MessDescriptionBlock;
    QWidget *MessStackWidgets[3];
    //QPushButton *MessMenuButton;
    //QPushButton *MenuChangeButton;
    //QPushButton *MessOff


    Exceptions *E;
    Message *M, *W;
    Query *q;
    QString UNCheck;

    bool isButtonVisible = false;
};
#endif // MAINWINDOW_H
