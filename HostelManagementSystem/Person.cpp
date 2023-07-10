#include "Person.h"

void Person:: setCMS(int cms) {
    if(cms > 100000 && cms < 999999)
        this->CMS = cms;
    else{
        qWarning() << "Please Enter Valid CMS id";
    }
}

void Person:: setUserName(const QString& userName) {
    if(userName.contains("@"))
        this->UserName = userName;
    else{
        qWarning() << "Please Enter Valid username";
    }
}

void Person:: setPassword(const QString& password) {
    this->Password   = password;
}

void Person:: setName(const QString& name) {
    this->Name = name;
}

void Person:: setAge(int age) {
    if(age>16)
        this->Age = age;
    else{
        qWarning() << "Please Enter valid Age";
    }
}

void Person:: setRoomNumber(int roomNum) {
    if((roomNum > 99 && roomNum < 129) && (roomNum > 199 && roomNum < 229) && (roomNum > 299 && roomNum < 329)&& (roomNum > 399 && roomNum < 429) )
        this->roomNumber = roomNum;
    else{
        qWarning() << "Room does not exists";
    }
}

void Person:: setContact(const QString& contact) {
    if(contact.length() == 11)
        this->Contact = contact;
    else{
        qWarning() << "Please Enter valid phone number";
    }
}

void Person:: setEmail(const QString& email) {
    if(email.contains("@"))
        this->email = email;
    else{
        qWarning() << "Please Enter Valid email";
    }
}

void Person:: setAddress(const QString& address) {
    this->Address = address;
}

void Person:: setGuardianName(const QString& guardianName) {
    this->guardianName = guardianName;
}

void Person:: setGuardianNumber(const QString& guardianNumber) {
    if(guardianNumber.length() == 11)
        this->guardianNumber = guardianNumber;
    else{
        qWarning() << "Please Enter valid phone number";
    }
}


int Person:: getCMS(){
    return CMS;
}

QString Person:: getUserName(){
    return UserName;
}

QString Person:: getPassword(){
    return Password;
}

QString Person:: getName(){
    return Name;
}

int Person:: getAge(){
    return Age;
}

int Person:: getRoomNumber(){
    return roomNumber;
}

QString Person:: getContact(){
    return Contact;
}

QString Person:: getEmail(){
    return email;
}

QString Person:: getAddress(){
    return Address;
}

QString Person:: getGuardianName(){
    return guardianName;
}

QString Person:: getGuardianNumber(){
    return guardianNumber;
}
