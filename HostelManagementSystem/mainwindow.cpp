#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ConnectDataBase();

    centralWidget()->setStyleSheet("background-image: url(:/PICTURES/BACKGROUNDS/BackGround.png)");
    ClockSignal();
    W = new Message();
    Q = new QSqlQuery();
    q = new Query();
    CreateFirstPage();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayRegistrationTable(){
    QWidget *mainwidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(mainwidget);
    QSqlTableModel *model = new QSqlTableModel(mainwidget);
    QTableView *tableView = new QTableView(mainwidget);

    model->setTable("Registration");
    model->select();

    tableView->setModel(model);

    tableView->setGeometry(100,50,800,500);
    tableView->setStyleSheet("QTableView { background-color: white; color: black; }"
                             "QTableView::item { padding: 5px; }"
                             "QHeaderView::section { background-color: lightgray; }");

    layout->addWidget(tableView);
    mainwidget->show();
}

//void MainWindow::DisplayRegistrationTable()
//{
//    QWidget* mainWidget = new QWidget(this);
//    QVBoxLayout* layout = new QVBoxLayout(mainWidget);
//    QTableView* tableView = new QTableView(mainWidget);
//    QSqlTableModel* model = new QSqlTableModel(mainWidget);

//    model->setTable("Registration");
//    model->select();

//    tableView->setModel(model);
//    tableView->setStyleSheet("QTableView { background-image: url(qrc:/PICTURES/BACKGROUNDS/BackGround.png); "
//                             "background-repeat: no-repeat; background-position: center; "
//                             "background-color: transparent; color: black; }"
//                             "QTableView::item { padding: 5px; }"
//                             "QHeaderView::section { background-color: lightgray; }");

//    // Set the desired size for the tableView
//    int tableViewWidth = 600;
//    int tableViewHeight = 400;
//    tableView->setMinimumSize(tableViewWidth, tableViewHeight);
//    tableView->setMaximumSize(tableViewWidth, tableViewHeight);

//    layout->addWidget(tableView);
//    layout->setAlignment(Qt::AlignCenter);
//    setCentralWidget(mainWidget);
//}



// Database Connecting Function
void MainWindow::ConnectDataBase(){
    //Initializing DataBase Object
    DB = QSqlDatabase::addDatabase("QSQLITE");

    //Opening DataBase
    DB.setDatabaseName("D:/study/sem 02/OOPS/Project/Semester Project 3/Semester Project/HostelManagementSystem/HostelDataBase.db");

    //Giving Message if DataBase Not Connected
    if(!DB.open()){
        QMessageBox *dbMessage = new QMessageBox(this);
        dbMessage->setText("DataBase Not Connected");
        dbMessage->setGeometry(600, 200, 300, 200);
        //ChangeTextDisplay(dbMessage, 14, "red", "brown", "5");
        dbMessage->setInformativeText("Do you want to Continue The Program?");
        dbMessage->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        int Option;
        Option = dbMessage->exec();
        if(Option == QMessageBox::No)
            exit(0);
    }
}




//Functions for Displaying Pages on Runtime

void MainWindow::CreateFirstPage(){
    // Initializing Both Buttons
    ApplyForRoomButton = new QPushButton("Apply For Room",this);
    LoginOptionButton = new QPushButton("Log In",this);
    TitleLabel = new QLabel("Hostel Management System",this);

    // Customizing Both of Buttons
    ApplyForRoomButton->setGeometry(295, 400, 230, 100);
    LoginOptionButton->setGeometry(575, 400, 230, 100);
    TitleLabel->setGeometry(255, 100, 610, 100);

    //NewRegistrationButton->setStyleSheet("background: translucent");
    // Initializing and Customizing Exit Button
    ExitButton = new QPushButton("X", this);
    ExitButton->setGeometry(1050, 20, 30, 30);
    ChangeTextDisplay(ExitButton, 16, "Cambria", "300" );
    ChangeTextDisplay(LoginOptionButton, 24,"Sans Serif", "500");
    ChangeTextDisplay(ApplyForRoomButton, 24,"Sans Serif", "500");
    ChangeTextDisplay(TitleLabel, 38, "Cambria", "500");

    Animation(LoginOptionButton, "tomato", "yellowgreen", "50");
    Animation(ApplyForRoomButton,"lightsalmon", "floralwhite", "50");
    Animation(ExitButton, "black", "red", "15");
    Animation(TitleLabel, "navy", "0", "20");

    //Showing all widgets of this Window
    TitleLabel->show();
    ApplyForRoomButton->show();
    LoginOptionButton->show();
    ExitButton->show();

    //All Button Connections for this Window
    connect(ApplyForRoomButton, SIGNAL(clicked(bool)), this, SLOT(On_ApplyForRoomButton_Clicked()));
    connect(LoginOptionButton, SIGNAL(clicked(bool)), this, SLOT(On_LoginButtonOption_Clicked()));
    connect(ExitButton, SIGNAL(clicked(bool)), this, SLOT(On_ExitButton_Clicked()));
}

void MainWindow::CreateApplyForRoomPage()
{
    InitializeBackButton();

    SubmitButton = new QPushButton("SUBMIT", this);
    SubmitButton->setGeometry(550, 575, 100, 40);
    ChangeTextDisplay(SubmitButton, 14, "Cambria", "100");
    Animation(SubmitButton, "steelblue", "lime", "5");

    //Customizing Add Picture Button
    AddPictureButton = new QPushButton("Add Picture",this);
    AddPictureButton->setGeometry(950, 75, 120, 120);

    NewRegistrationLabels[0] = new QLabel("First Name", this);
    NewRegistrationLabels[1] = new QLabel("Last Name", this);
    NewRegistrationLabels[2] = new QLabel("CNIC", this);
    NewRegistrationLabels[3] = new QLabel("Date of Birth", this);
    NewRegistrationLabels[4] = new QLabel("Postal Address", this);
    NewRegistrationLabels[5] = new QLabel("Email Address", this);
    NewRegistrationLabels[6] = new QLabel("Phone Number", this);
    NewRegistrationLabels[7] = new QLabel("Guardian Name", this);
    NewRegistrationLabels[8] = new QLabel("Guardian Phone No", this);
    NewRegistrationLabels[9] = new QLabel("Domicile District", this);

    for(int i=0; i<8; i++)
    {
        NewRegistrationLines[i] = new QLineEdit(this);
    }

    for(int i =0, y = 150, z = 150; i<10;i++, y= y +40, z+=40)
    {
        NewRegistrationLabels[i]->setGeometry(100 , y, 200, 25);
        ChangeTextDisplay(NewRegistrationLabels[i], 16, "Times New Roman", "bold");
        NewRegistrationLabels[i]->show();

        if(i > 7)
            continue;
        if(i == 3)
            z+=40;
        NewRegistrationLines[i]->setGeometry(300 , z, 350, 25);
        ChangeTextDisplay(NewRegistrationLines[i], 16, "Times New Roman", "1");
        Animation(NewRegistrationLines[i], "blue", "green", "1");
        NewRegistrationLines[i]->show();
    }

    for(int i = 0, x = 300 ; i < 4; i++, x+=100){
        comboBox[i] = new QComboBox(this);
        if (i == 0 || i == 2)
            comboBox[i]->setGeometry(x, 270, 100 ,25);
        else if(i == 1){
            comboBox[i]->setGeometry(x, 270, 150, 25);
            x+=50;
        }
        else
            comboBox[i]->setGeometry(300, 510, 350, 25);
        comboBox[i]->show();
    }
    AddDistricts(comboBox[3]);
    AddInitialDate(comboBox[0], comboBox[1], comboBox[2]);

    AddPictureButton->show();
    SubmitButton->show();

    //All Connections of this Window
    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(0);} );
    connect(AddPictureButton, SIGNAL(clicked(bool)), this, SLOT(On_AddPictureButton_Clicked()));
    connect(SubmitButton, SIGNAL(clicked(bool)), this, SLOT(On_SubmitButton_Clicked()));
    connect(comboBox[1], SIGNAL(currentIndexChanged(int)), this, SLOT(On_DateValue_Changed()));
    connect(comboBox[2], SIGNAL(currentIndexChanged(int)), this, SLOT(On_DateValue_Changed()));
    ExceptionBox = new QPlainTextEdit(this);
}

void MainWindow::CreateLoginPage(bool ByLogout){

    //Test button
    QPushButton *button;

    //creating GroupBox for Login
    LoginBox = new QGroupBox("SIGN IN", this);
    LoginBox->setGeometry(350,150,350,300);
    ChangeTextDisplay(LoginBox, 15, "Cambria", "bold");

    //Creating elements of groupbox
    UserNameLabel = new QLabel("USERNAME : ", LoginBox);
    PassWordLabel = new QLabel("PASSWORD : ", LoginBox);
    UserNameLine = new QLineEdit(LoginBox);
    PassWordLine = new QLineEdit(LoginBox);
    LogInButton = new QPushButton("LOGIN", this);
    ForgotPassword = new QPushButton("FORGOT PASSWORD ?", this);
    button = new QPushButton("Test",this);


    //Customizing Graphics
    ForgotPassword->setGeometry(400, 475, 250, 50);
    ChangeTextDisplay(UserNameLine, 14, "Calibri", "10");
    ChangeTextDisplay(PassWordLine, 14, "Calibri", "10");
    ChangeTextDisplay(LogInButton, 14, "Calibri",  "500");
    ChangeTextDisplay(ForgotPassword, 14, "Cambria",  "600");
    PassWordLine->setEchoMode(QLineEdit::Password);
    LoginBox->setStyleSheet("QGroupBox{background-image:url(:/PICTURES/BACKGROUNDS/GroupBoxBackground.png);}");

    InitializeBackButton();

    //Initializing Layouts
    QHBoxLayout *hLayout1 = new QHBoxLayout();
    QHBoxLayout *hLayout2 = new QHBoxLayout();
    QHBoxLayout *hLayout3 = new QHBoxLayout();
    QVBoxLayout *vLayout = new QVBoxLayout();

    //Adding Group elemnts to Horizontal Layout
    hLayout1->addWidget(UserNameLabel);
    hLayout1->addWidget(UserNameLine);
    hLayout2->addWidget(PassWordLabel);
    hLayout2->addWidget(PassWordLine);
    //hLayout3->addWidget(ForgotPassword);
    hLayout3->addStretch(20);
    hLayout3->addWidget(LogInButton);
    hLayout3->addStretch(10);
    hLayout3->addWidget(button);

    //Customizing Vertical Layout
    vLayout->addStretch(1);
    vLayout->addLayout(hLayout1);
    vLayout->addStretch(2);
    vLayout->addLayout(hLayout2);
    vLayout->addStretch(5);
    vLayout->addLayout(hLayout3);
    LoginBox->setLayout(vLayout);

    if(!ByLogout){
        UserNameLine->setText(UserNameText);
        PassWordLine->setText(PassWordText);
    }

    //Displaying All Widgets of this Window
    LoginBox->show();
    ForgotPassword->show();

    // All Button Connections for this Window
    connect(LogInButton, SIGNAL(clicked(bool)), this, SLOT(On_LoginButton_Clicked()));
    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(1);} );
    connect(button, &QPushButton::clicked, [this]() {
        Query *w = new Query;

        w->Transfer_Reg_Main("412365","404");

        delete w;
    } );

}




void MainWindow::CreateStudentPage(){
    /*
    QGridLayout *gLayout = new QGridLayout(this);


    // Creating GroupBox for Student Option
    StudentOptionBox = new QGroupBox(this);
    StudentOptionBox->setGeometry(200,70,500,500);*/

    M = new StudentMessage();

    //Custmizing Welcome Message
    QString name = "Welcome!";
    name+= q->getAttribute<QString, QString>("User_name", UNCheck, "Main", 3);
    NameLabel = new QLabel(name, this);
    NameLabel->setGeometry(400, 40, 200, 30);
    ChangeTextDisplay(NameLabel, 15, "Times New Roman", "bold");

    InitializeAccountButton();
    InitializeBackButton();
    InitializeMessageButtons();


    //Adding Option Buttons to groupbox (StudentOptionBox)
    StudentOptions[0] = new QPushButton("Mess Off Request", this);
    StudentOptions[1] = new QPushButton("Change Room", this);
    StudentOptions[2] = new QPushButton("Write Complain", this);
    for(int x = 200, y = 100, i =0; i < 3; i++){
        StudentOptions[i]->setGeometry(x, y, 150, 75);
        if(i%2==0)
            x+=200;
        else
            y+= 125;
    }
    //gLayout->addWidget(RequestMessOptionsButton, 0, 0);
    //gLayout->addWidget(RequestChangeRoomButton, 0, 1);
    //gLayout->addWidget(WriteComplainButton, 1, 0);

    //Displaying All elements of this window
    for(int i = 0; i < 3; i++)
        StudentOptions[i]->show();
    NameLabel->show();
    //PhotoLabel->show();

    //All Button SIgnals for this Window

    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(2);} );
    connect(AccountButton, &QPushButton::clicked, [this]() {On_AccountButton_Clicked(1);} );
    connect(StudentOptions[0], SIGNAL(clicked(bool)), this, SLOT(On_MessOptionsButton_Clicked()));
    connect(MessageButtons[0], &QPushButton::clicked, [this]() {On_WriteMessageButton_Clicked(1);} );
    connect(MessageButtons[1], &QPushButton::clicked, [this]() {On_ReadMessageButton_Clicked(1);} );
}


void MainWindow::CreateManagerPage()
{
    M = new ManagerMessage();
    QString name = "Welcome! Manager";
    NameLabel = new QLabel(name, this);
    NameLabel->setGeometry(400, 40, 200, 30);
    ChangeTextDisplay(NameLabel, 15, "Times New Roman", "bold");

    InitializeAccountButton();
    InitializeBackButton();
    InitializeMessageButtons();

    ManagerOptions[0] = new QPushButton("Allocate Room", this);
    ManagerOptions[1] = new QPushButton("Mess Options", this);

    for(int x = 200, y = 100, i =0; i < 2; i++){
        ManagerOptions[i]->setGeometry(x, y, 150, 75);
        if(i%2==0)
            x+=200;
        else
            y+= 125;
    }

    NameLabel->show();

    for(int i = 0; i < 2; i++){
        ManagerOptions[i]->show();
    }

    connect(ManagerOptions[1], SIGNAL(clicked(bool)), this, SLOT(On_MessOptionsButton_Clicked()));
    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(3);} );
    connect(AccountButton, &QPushButton::clicked, [this]() {On_AccountButton_Clicked(2);} );
    connect(MessageButtons[0], &QPushButton::clicked, [this]() {On_WriteMessageButton_Clicked(2);} );
    connect(MessageButtons[1], &QPushButton::clicked, [this]() {On_ReadMessageButton_Clicked(2);} );
    connect(ManagerOptions[0], SIGNAL(clicked(bool)), this, SLOT(On_AllocateRoomButton_Clicked()));

}


void MainWindow::CreateAllocateRoomPage()
{
    DisplayRegistrationTable();

    InitializeAccountButton();
    InitializeBackButton();
    InitializeMessageButtons();

    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(4);} );
    connect(AccountButton, &QPushButton::clicked, [this]() {On_AccountButton_Clicked(3);} );
    connect(MessageButtons[0], &QPushButton::clicked, [this]() {On_WriteMessageButton_Clicked(3);} );
    connect(MessageButtons[1], &QPushButton::clicked, [this]() {On_ReadMessageButton_Clicked(3);} );
}

//void MainWindow::CreateMessOptionsPage()
//{

//    InitializeAccountButton();
//    InitializeBackButton();
//    InitializeMessageButtons();

//    MessStack = new QStackedWidget(this);
//    MessStack->setCurrentIndex(0);
//    MessStack->setGeometry(225, 180, 1000, 800);

//    QString MessOff;
//    if(typeid(*M) == typeid(StudentMessage)){
//        MessOff = "Request Mess Off";
//    }
//    else{
//        MessOff = "Mess Off Requests";
//    }


//    MessOptions[0] = new QPushButton("Menu", this);
//    MessOptions[1] = new QPushButton("Timings", this);
//    MessOptions[2] = new QPushButton(MessOff,this);



//    for(int i = 0, x = 225; i < 3; i++, x += 180){
//        MessOptions[i]->setGeometry(x, 100, 160, 50);
//        MessOptions[i]->show();
//        MessStackWidgets[i] = new QWidget(this);
//        //MessStackWidgets[i]->setGeometry(225, 180, 540, 400);
//        MessStack->addWidget(MessStackWidgets[i]);
//        MessOptions[i]->show();
//    }

//    QTableView *MessMenu = new QTableView(this);
//    QTableView *MessTimings = new QTableView(this);
//    QPlainTextEdit *ChangeMenu = new QPlainTextEdit(this);
//    MessMenu->setParent(MessStackWidgets[0]);
//    MessTimings->setParent(MessStackWidgets[1]);
//    ChangeMenu->setParent(MessStackWidgets[2]);

//    MessStack->show();


//    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(5);} );
//    connect(AccountButton, &QPushButton::clicked, [this]() {On_AccountButton_Clicked(4);} );
//    connect(MessageButtons[0], &QPushButton::clicked, [this]() {On_WriteMessageButton_Clicked(3);} );
//    connect(MessageButtons[1], &QPushButton::clicked, [this]() {On_ReadMessageButton_Clicked(3);} );

//    connect(MessOptions[0], &QPushButton::clicked, [this, MessMenu]() {
//        // Open the table and display it in the QTableView widget
//        QSqlTableModel *model = new QSqlTableModel(this, DB);
//        model->setTable("Mess");  // Replace "Menu" with your actual table name
//        model->select();

//        MessMenu->setModel(model);
//        MessMenu->show();

//        // Set the current index of the stacked widget to show the QTableView widget
//        MessStack->setCurrentIndex(0);
//    });
//    connect(MessOptions[1], &QPushButton::clicked, [this, MessMenu]() {
//        // Open the table and display it in the QTableView widget
//        QSqlTableModel *model = new QSqlTableModel(this, DB);
//        //model->setTable("");  // Replace "Menu" with your actual table name
//        model->select();

//        MessMenu->setModel(model);
//        MessMenu->show();

//        // Set the current index of the stacked widget to show the QTableView widget
//        MessStack->setCurrentIndex(1);
//    });
//    connect(MessOptions[2], &QPushButton::clicked, [this, MessMenu]() {

//        MessStack->setCurrentIndex(2);
//    });
//}

void MainWindow:: CreateMessOptionsPage()
{

    MessStack = new QStackedWidget(this);
    MessStack->setCurrentIndex(0);
    MessStack->setGeometry(225, 180, 1000, 800);

    QString MessOff;
    if (typeid(*M) == typeid(StudentMessage)) {
        MessOff = "Request Mess Off";
    } else {
        MessOff = "Mess Off Requests";
    }

    MessOptions[0] = new QPushButton("Menu", this);
    MessOptions[1] = new QPushButton("Timings", this);
    MessOptions[2] = new QPushButton(MessOff, this);

    for (int i = 0, x = 225; i < 3; i++, x += 180) {
        MessOptions[i]->setGeometry(x, 100, 160, 50);
        MessOptions[i]->show();
        MessStackWidgets[i] = new QWidget(this);
        MessStack->addWidget(MessStackWidgets[i]);
        MessOptions[i]->show();
    }

    QTableView* MessMenu = new QTableView(MessStackWidgets[0]);
    QTableView* MessTimings = new QTableView(MessStackWidgets[1]);
    QPlainTextEdit* ChangeMenu = new QPlainTextEdit(MessStackWidgets[2]);

    MessMenu->setGeometry(0, 0, 1000, 800);
    MessTimings->setGeometry(0, 0, 540, 400);
    ChangeMenu->setGeometry(0, 0, 540, 400);

    MessStack->show();

    connect(BackButton, &QPushButton::clicked, [this]() { On_BackButton_Clicked(5); });
    connect(AccountButton, &QPushButton::clicked, [this]() { On_AccountButton_Clicked(4); });
    connect(MessageButtons[0], &QPushButton::clicked, [this]() { On_WriteMessageButton_Clicked(3); });
    connect(MessageButtons[1], &QPushButton::clicked, [this]() { On_ReadMessageButton_Clicked(3); });

    connect(MessOptions[0], &QPushButton::clicked, [this, MessMenu]() {
        QSqlTableModel* model = new QSqlTableModel(this, DB);
        model->setTable("Mess");
        model->select();

        MessMenu->setModel(model);
        MessStack->setCurrentIndex(0);
    });

    connect(MessOptions[1], &QPushButton::clicked, [this, MessTimings]() {
        QSqlTableModel* model = new QSqlTableModel(this, DB);
        // model->setTable(""); // Replace with your actual table name
        model->select();

        MessTimings->setModel(model);
        MessStack->setCurrentIndex(1);
    });

    connect(MessOptions[2], &QPushButton::clicked, [this, ChangeMenu]() {
        MessStack->setCurrentIndex(2);
    });

}

void MainWindow::CreateWriteMessagePage()
{
    InitializeAccountButton();
    InitializeBackButton();
    //InitializeMessageButtons();

    MessageSubject = new QPlainTextEdit(this);
    MessageSubject->setGeometry(100, 100, 300, 80);
    ChangeTextDisplay(MessageSubject, 14, "Times New Roman", "100");
    Animation(MessageSubject, "black", "steelblue", "20");

    WriteMessageLabel = new QLabel("Write Message Here : ", this);
    MessageSubjectLabel = new QLabel("Subject : ", this);
    WriteMessageLabel->setGeometry(130, 220, 200, 30);
    MessageSubjectLabel->setGeometry(130, 50, 100, 30);
    ChangeTextDisplay(WriteMessageLabel, 16, "Cambria", "500");
    ChangeTextDisplay(MessageSubjectLabel, 16, "Cambria", "500");

    WritingBox = new QPlainTextEdit(this);
    WritingBox->setGeometry(100, 280, 500, 300);
    ChangeTextDisplay(WritingBox, 14, "Times New Roman", "100");
    Animation(WritingBox, "black", "steelblue", "20");

    SendMessageButton = new QPushButton("MESSAGE", this);
    SendMessageButton->setGeometry(525, 630, 75, 25);

    MessageSubject->show();
    WritingBox->show();
    SendMessageButton->show();
    WriteMessageLabel->show();
    MessageSubjectLabel->show();

    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(6);} );
    connect(AccountButton, &QPushButton::clicked, [this]() {On_AccountButton_Clicked(5);} );
    connect(SendMessageButton, SIGNAL(clicked(bool)), this, SLOT(On_SendMessageButton_Clicked()));
}

void MainWindow::CreateReadMessagePage()
{
    InitializeBackButton();
    InitializeAccountButton();

    ReadingBox = new QPlainTextEdit(this);
    ReadingBox->setReadOnly(true);
    ReadingBox->setGeometry(150, 100, 500, 400);
    M->ReadMessage(ReadingBox);
    ReadingBox->show();

    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(7);} );
    connect(AccountButton, &QPushButton::clicked, [this]() {On_AccountButton_Clicked(6);} );
}

void MainWindow::CreateAnotherMessagePage()
{
    InitializeAccountButton();
    InitializeBackButton();
    //InitializeMessageButtons();

    AnotherMessageButton = new QPushButton("Write Another\n  Message", this);
    AnotherMessageButton->setGeometry(300, 200, 150, 75);

    MessageStatusLabel = new QLabel("Submitted", this);
    MessageStatusLabel->setGeometry(300, 100, 200, 50);

    MessageStatusLabel->show();
    AnotherMessageButton->show();

    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(8);} );
    connect(AccountButton, &QPushButton::clicked, [this]() {On_AccountButton_Clicked(7);} );
    connect(AnotherMessageButton, SIGNAL(clicked(bool)), this, SLOT(On_AnotherMessageButton_Clicked()));
}

void MainWindow::CreateAccountPage()
{
    InitializeBackButton();

    ChangePassWord = new QPushButton("CHANGE PASSWORD", this);
    ChangePassWord->setGeometry(325, 575, 200, 75);
    ChangeTextDisplay(ChangePassWord, 18, "Arial Black", "100");
    Animation(ChangePassWord, "lime", "lightgrey", "10");

    for(int i = 0 ,y = 100; i < 11 ;i++, y += 40){
        AccountInformationtitles[i] = new QLabel( this);
        AccountInformationValues[i] = new QLineEdit(this);
        AccountInformationValues[i]->setReadOnly(true);
        AccountInformationValues[i]->setText(q->getAttribute<QString, QString>("User_name", UNCheck, "Main", i));
        AccountInformationtitles[i]->setGeometry(150, y, 250, 25);
        AccountInformationValues[i]->setGeometry(400, y, 350, 25);
        ChangeTextDisplay(AccountInformationtitles[i], 16, "Cambria", "1000");
        ChangeTextDisplay(AccountInformationValues[i], 16, "Cascida Code Semilight", "10");
        AccountInformationtitles[i]->show();
        AccountInformationValues[i]->show();
    }
    InitializeQLabels(AccountInformationtitles);
    ChangePassWord->show();


    connect(BackButton, &QPushButton::clicked, [this]() {On_BackButton_Clicked(9);} );

}

// Slot Functins of All Button Signals

void MainWindow::On_ApplyForRoomButton_Clicked()
{
    DeleteFirstPage();
    CreateApplyForRoomPage();
}

void MainWindow::On_SubmitButton_Clicked()
{
    //Exception Box
    E = new Exceptions();

    ExceptionBox->setGeometry(775, 400, 295, 240);
    ExceptionBox->setReadOnly(true);
    ChangeTextDisplay(ExceptionBox, 14, "Times New Roman", "1000");
    Animation(ExceptionBox, "Black", "Red", "10");


    QString tempSetter; // string use for checking only and then setting person/student datamembers
    // QString error;

    bool NoException =true;
    ExceptionBox->clear();
    //  error = "";

    for (int i = 0; i < 8; i++) {
        tempSetter = NewRegistrationLines[i]->text();
        switch (i) {
        case 0:
            NoException = E->CheckAllExceptions(tempSetter, "NAME1", ExceptionBox) &&  NoException;
            break;
        case 1:
            NoException = E->CheckAllExceptions(tempSetter, "NAME2", ExceptionBox) &&  NoException;
            break;
        case 2:
            NoException = E->CheckAllExceptions(tempSetter, "CNIC", ExceptionBox) &&  NoException;
            break;
        case 3:
            NoException = E->CheckAllExceptions(tempSetter, "ADDRESS", ExceptionBox) && NoException;
            break;
        case 4:
            NoException = E->CheckAllExceptions(tempSetter, "EMAIL", ExceptionBox) && NoException;
            break;
        case 5:
        case 7:
            NoException = E->CheckAllExceptions(tempSetter, "GNUMBER", ExceptionBox) && NoException;
            break;
        case 6:
            NoException = E->CheckAllExceptions(tempSetter, "GNAME", ExceptionBox) && NoException;
            break;
        }
    }
    ExceptionBox->show();


}


void MainWindow::On_LoginButtonOption_Clicked()
{
    DeleteFirstPage();
    CreateLoginPage(true);
}

void MainWindow::On_BackButton_Clicked(int i)
{
    switch (i)
    {
    case 0:
        DeleteApplyForRoomPage();
        CreateFirstPage();
        break;
    case 1:
        DeleteLoginPage();
        CreateFirstPage();
        break;

    case 2:
        DeleteStudentPage(false);
        CreateLoginPage(false);
        break;

    case 3:
        DeleteManagerPage(false);
        CreateLoginPage(false);
        break;
    case 4:
        DeleteAllocateRoomPage();
        CreateManagerPage();
    case 5:
        DeleteMessOptionsPage();
        if(typeid(*M) == typeid(StudentMessage))
            CreateStudentPage();
        else
            CreateManagerPage();
        break;
    case 6:
        DeleteWriteMessagePage();
        if(typeid(*M) == typeid(StudentMessage))
            CreateStudentPage();
        else
            CreateManagerPage();
        break;
    case 7:
        DeleteReadMessagePage();
        if(typeid(*M) == typeid(StudentMessage))
            CreateStudentPage();
        else
            CreateManagerPage();
        break;
    case 8:
        DeleteAnotherMessagePage();
        if(typeid(*M) == typeid(StudentMessage))
            CreateStudentPage();
        else
            CreateManagerPage();
    case 9:
        DeleteAccountPage();
        CreateStudentPage();
        break;
    default:
        break;
    }
}

void MainWindow::On_LogOutButton_Clicked(int i)
{
    On_AccountButton_Clicked(0);
    switch(i){
    case 1:
        DeleteStudentPage(false);
        break;
    case 2:
        DeleteManagerPage(false);
        break;
    case 3:
        DeleteAllocateRoomPage();
    case 4:
        DeleteMessOptionsPage();
        break;
    case 5:
        DeleteWriteMessagePage();
        break;
    case 6:
        DeleteReadMessagePage();
        break;
    case 7:
        DeleteAnotherMessagePage();
        break;
    }
    CreateLoginPage(true);
}

void MainWindow::On_AddPictureButton_Clicked(){
    // Open a file dialog to select an image file
    QString imagePath = QFileDialog::getOpenFileName(nullptr, "Select Image", "", "Image Files (*.png *.jpg)");

    // Check if a file was selected
    if (!imagePath.isEmpty()) {
        // Open the selected file
        QFile imageFile(imagePath);

        // Check if the file was opened successfully
        if (imageFile.open(QIODevice::ReadOnly)) {
            // Read the image data
            QByteArray imageData = imageFile.readAll();

            // Get the project directory's source file path
            QString projectDirectory = QDir::currentPath();

            // Construct the destination file path within the project directory
            QString destinationPath = projectDirectory + "/image.png";

            // Create a new file in the project directory
            QFile destinationFile(destinationPath);

            // Check if the file was created successfully
            if (destinationFile.open(QIODevice::WriteOnly)) {
                // Write the image data to the destination file
                destinationFile.write(imageData);
                destinationFile.close();

                qDebug() << "Image saved successfully!";
            } else {
                qDebug() << "Failed to create the destination file.";
            }

            imageFile.close();
        } else {
            qDebug() << "Failed to open the selected file.";
        }
    } else {
        qDebug() << "No file selected.";
    }

}

void MainWindow::On_LoginButton_Clicked()
{  // Get the default database connection

    // Getting Texts from Both Line Edits for Authentication
    UserNameText = UserNameLine->text();
    PassWordText = PassWordLine->text();

//    bool uFound = false, pFound = false;
    if(UserNameText.isEmpty()){
        QMessageBox *q = new QMessageBox;

        q->setWindowTitle("Error");
        q->setText("Username box is empty");
        q->setStyleSheet("QMessageBox { border-radius: 10px; }");
        q->exec();

        delete q;
    }


    //Checking Username and Password
    bool check = Q->exec("SELECT * FROM Main WHERE User_name = ':" + UserNameText + "'");
    qDebug() << check;
    if(Q->exec("SELECT * FROM Main WHERE User_name = ':" + UserNameText + "'"))
    {
        if(PassWordText == q->getAttribute<QString, QString>("User_name", UserNameText, "Main",2)){
            DeleteLoginPage();
            CreateStudentPage();
        }
    }
    else{
        if(W->CreateWarning("Invalid Login", "Do you Want to Try Again ?", 2));
        else On_BackButton_Clicked(1);
    }

    if(UserNameText == "m"){
        if(PassWordText == "n"){
            DeleteLoginPage();
            CreateManagerPage();
        }
    }


}

void MainWindow::On_AccountButton_Clicked(int i)
{
    if(!(isButtonVisible))
    {
        EditAccountButton = new QPushButton("Account", this);
        LogoutButton = new QPushButton("<- Log Out", this);
        EditAccountButton->setGeometry(950, 210, 120, 30);
        LogoutButton->setGeometry(950, 255, 120, 30);
        EditAccountButton->show();
        LogoutButton->show();
        isButtonVisible = true;
        connect(LogoutButton, &QPushButton::clicked, [this, i]() {On_LogOutButton_Clicked(i);} );
        connect(EditAccountButton, &QPushButton::clicked, [this, i]() {On_EditAccountButton_Clicked(i);} );
    }
    else
    {
        delete EditAccountButton;
        delete LogoutButton;
        isButtonVisible = false;
    }
    return;
}


void MainWindow::On_MessOptionsButton_Clicked()
{
    if(typeid(*M) == typeid(StudentMessage))
        DeleteStudentPage(true);
    else
        DeleteManagerPage(true);
    CreateMessOptionsPage();
}



void MainWindow::On_AllocateRoomButton_Clicked()
{
    DeleteManagerPage(false);
    CreateAllocateRoomPage();
}

void MainWindow::On_EditAccountButton_Clicked(int i)
{
    On_AccountButton_Clicked(0);
    switch(i){
    case 1:
        DeleteStudentPage(false);
        break;
    case 2:
        DeleteManagerPage(false);
        break;
    case 3:
        DeleteAllocateRoomPage();
    case 4:
        DeleteMessOptionsPage();
        break;
    case 5:
        DeleteWriteMessagePage();
        break;
    case 6:
        DeleteReadMessagePage();
        break;
    case 7:
        DeleteAnotherMessagePage();
        break;
    }
    CreateAccountPage();

}


void MainWindow::On_SendMessageButton_Clicked()
{
    M->WriteMessage(WritingBox);
    DeleteWriteMessagePage();
    CreateAnotherMessagePage();
}

void MainWindow::On_WriteMessageButton_Clicked(int i)
{
    switch(i){
    case 1:
        DeleteStudentPage(true);
        break;
    case 2:
        DeleteManagerPage(true);
        break;
    case 3:
        DeleteMessOptionsPage();
        break;
    }

    CreateWriteMessagePage();
}

void MainWindow::On_ReadMessageButton_Clicked(int i)
{
    switch(i){
    case 1:
        DeleteStudentPage(true);
        break;
    case 2:
        DeleteManagerPage(true);
        break;
    case 3:
        DeleteMessOptionsPage();
        break;
    }
    CreateReadMessagePage();
}

void MainWindow::On_AnotherMessageButton_Clicked()
{
    DeleteAnotherMessagePage();
    CreateWriteMessagePage();
}
void MainWindow::On_ExitButton_Clicked()
{
    if(W->CreateWarning("EXIT", "Are You Sure you Want to Exit ?", 3))
        exit(0);
}




// Functions to delete Pages

void MainWindow::DeleteFirstPage()
{
    delete TitleLabel;
    delete ApplyForRoomButton;
    delete LoginOptionButton;
}

void MainWindow::DeleteLoginPage()
{
    delete LoginBox;
    delete BackButton;
    delete ForgotPassword;
}

void MainWindow::DeleteApplyForRoomPage()
{
    //delete[] NewRegistrationLabels;
    //delete[] NewRegistrationLines;

    for(int i =0; i<10;i++){
        delete NewRegistrationLabels[i];
        if(i>7)
            continue;
        delete NewRegistrationLines[i];
    }

    for(int i=0; i<4; i++)
        delete comboBox[i];
    delete BackButton;
    delete AddPictureButton;
    delete ExceptionBox;
    delete SubmitButton;
}

void MainWindow::DeleteStudentPage(bool i)
{
    if(isButtonVisible == true)
        On_AccountButton_Clicked(0);
    for(int i =0; i<3;i++)
        delete StudentOptions[i];
    delete NameLabel;
    delete BackButton;
    delete AccountButton;
    delete MessageButtons[0];
    delete MessageButtons[1];
    if(!i)
        delete M;
}

void MainWindow::DeleteManagerPage(bool i){
    if(isButtonVisible == true)
        On_AccountButton_Clicked(0);
    delete AccountButton;
    delete NameLabel;
    delete BackButton;
    delete MessageButtons[0];
    delete MessageButtons[1];
    for(int i =0; i < 2; i++)
        delete ManagerOptions[i];
    if(!i)
        delete M;
}

void MainWindow::DeleteAllocateRoomPage()
{
    delete AccountButton;
    delete BackButton;
    delete MessageButtons[0];
    delete MessageButtons[1];
    for(int i =0; i < 2; i++)
        delete ManagerOptions[i];
}

void MainWindow::DeleteMessOptionsPage()
{
    if(isButtonVisible == true)
        On_AccountButton_Clicked(0);
    delete AccountButton;
    delete BackButton;
    delete MessageButtons[0];
    delete MessageButtons[1];
    for(int i =0; i < 3; i++)
        delete MessOptions[i];
}

void MainWindow::DeleteWriteMessagePage()
{
    if(isButtonVisible == true)
        On_AccountButton_Clicked(0);
    delete BackButton;
    delete AccountButton;
    delete WritingBox;
    delete MessageSubject;
    delete MessageSubjectLabel;
    delete WriteMessageLabel;
    delete SendMessageButton;
}

void MainWindow::DeleteReadMessagePage()
{
    if(isButtonVisible == true)
        On_AccountButton_Clicked(0);
    delete BackButton;
    delete AccountButton;
    delete ReadingBox;
}

void MainWindow::DeleteAnotherMessagePage()
{
    if(isButtonVisible == true)
        On_AccountButton_Clicked(0);
    delete BackButton;
    delete AccountButton;
    delete AnotherMessageButton;
    delete MessageStatusLabel;
}

void MainWindow::DeleteAccountPage()
{
    for(int i = 0; i <11; i++){
        delete AccountInformationtitles[i];
        delete AccountInformationValues[i];
    }
    delete ChangePassWord;
    delete BackButton;
}

void MainWindow::On_DateValue_Changed()
{
    bool leapYear;
    if(((comboBox[2]->currentText()).toInt() % 4 == 0) && ((comboBox[2]->currentText()).toInt() % 100 != 0))
        leapYear =true;
    else leapYear = false;

    int ind = comboBox[1]->currentIndex();
    comboBox[0]->clear();
    for(int i = 1; i < 32 ; i++){
        if(ind == 1 && leapYear && (i == 30 || i ==31))
            continue;
        else if(ind == 1 && !leapYear && (i == 29 || i ==30 || i == 31))
            continue;
        else if((ind == 3 || ind == 5 || ind == 8 || ind == 10) && i == 31)
            continue;
        comboBox[0]->addItem(QString::number(i));
    }
}

void MainWindow::ClockSignal()
{
    Clock = new QTimer(this);
    connect(Clock, SIGNAL(timeout()), this, SLOT(ClockSlot()));

    Clock->start(1000);
}

void MainWindow::ClockSlot()
{
    TimeLabel = new QLabel(this);
    TimeLabel->setGeometry(940, 20, 100, 30);
    ChangeTextDisplay(TimeLabel, 14, "Cambria", "1");
    Animation(TimeLabel, "white", "navy", "0");
    time = QTime::currentTime();
    TimeText = time.toString(" hh : mm : ss");
    TimeLabel->setText(TimeText);

    TimeLabel->show();
}


QHBoxLayout* MainWindow::AddHorizontalLayout(QLabel *label, QLineEdit* line)
{
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(label);
    hLayout->addWidget(line);
    return hLayout;
}


void MainWindow:: InitializeBackButton()
{
    BackButton = new QPushButton("<-", this);
    BackButton->setGeometry(20,20,30,30);
    ChangeTextDisplay(BackButton, 14, "Calibri", "500");
    Animation(BackButton, "white", "blue", "15");
    BackButton->show();
}

void MainWindow:: InitializeAccountButton()
{
    AccountButton = new QPushButton("",this);
    AccountButton->setGeometry(950, 75, 120, 120);
    /*
    AccountButton->setStyleSheet("border-radius: 60px;"
                                 "background-image: url(:/new/prefix1/Tauha Photo.jpg);"
                                 "    background-repeat: no-repeat;"
                                 "    background-position: center center;"
                                 "    background-size: contain;");

*/
    //AccountButton->setStyleSheet("background-image: url(D:/HARIS/IMG-20220824-WA0002.jpg); background-repeat: no-repeat; background-position: center; background-size: cover;");
    QPixmap pixmap("D:/HARIS/IMG-20220824-WA0002.jpg");

    // Scale the pixmap to the size of the button
    QPixmap scaledPixmap = pixmap.scaled(AccountButton->size());

    // Create an icon from the scaled pixmap
    QIcon icon(scaledPixmap);

    // Set the icon as the button's icon
    AccountButton->setIcon(icon);
    AccountButton->setIconSize(AccountButton->size());
    AccountButton->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    AccountButton->show();
}

void MainWindow::InitializeMessageButtons()
{
    QPixmap pixmap1(":/PICTURES/OTHERS/WriteIcon.jpg");
    QPixmap pixmap2(":/PICTURES/OTHERS/ReadIcon.png");

    for(int i =0, x = 830; i < 2; i++, x+=40){
        MessageButtons[i] = new QPushButton("", this);
        MessageButtons[i]->setGeometry(x, 20, 30, 30);
    }
    // Scale the pixmap to the size of the button
    QPixmap scaledPixmap1 = pixmap1.scaled(MessageButtons[0]->size());
    QPixmap scaledPixmap2 = pixmap2.scaled(MessageButtons[1]->size());
    // Create an icon from the scaled pixmap
    QIcon icon1(scaledPixmap1);
    QIcon icon2(scaledPixmap2);

    // Set the icon as the button's icon
    MessageButtons[0]->setIcon(icon1);
    MessageButtons[0]->setIconSize(MessageButtons[0]->size());
    MessageButtons[0]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    MessageButtons[1]->setIcon(icon2);
    MessageButtons[1]->setIconSize(MessageButtons[1]->size());
    MessageButtons[1]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    MessageButtons[0]->show();
    MessageButtons[1]->show();
}

