QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Person.cpp \
    exceptions.cpp \
    main.cpp \
    mainwindow.cpp \
    managermess.cpp \
    managermessage.cpp \
    mess.cpp \
    message.cpp \
    nonClassFunctions.cpp \
    query.cpp \
    studentmess.cpp \
    studentmessage.cpp

HEADERS += \
    Person.h \
    exceptions.h \
    mainwindow.h \
    managermess.h \
    managermessage.h \
    mess.h \
    message.h \
    nonClassFunctions.h \
    query.h \
    studentmess.h \
    studentmessage.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES +=


RESOURCES +=

DISTFILES +=
