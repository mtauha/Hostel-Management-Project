#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <QDebug>

class Person{
private:
    int CMS;
    QString UserName;
    QString Password;
    QString Name;
    int Age;
    int roomNumber;
    QString Contact;
    QString email;
    QString Address;
    QString guardianName;
    QString guardianNumber;

public:

    void setCMS(int cms);
    void setUserName(const QString& userName);
    void setPassword(const QString& password);
    void setName(const QString& name);
    void setAge(int age);
    void setRoomNumber(int roomNum);
    void setContact(const QString& contact);
    void setEmail(const QString& email);
    void setAddress(const QString& address);
    void setGuardianName(const QString& guardianName);
    void setGuardianNumber(const QString& guardianNumber);

    int getCMS();
    QString getUserName();
    QString getPassword();
    QString getName();
    int getAge();
    int getRoomNumber();
    QString getContact();
    QString getEmail();
    QString getAddress();
    QString getGuardianName();
    QString getGuardianNumber();


};

#endif // PERSON_H
