#ifndef NONCLASSFUNCTIONS_H
#define NONCLASSFUNCTIONS_H

#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QPlainTextEdit>

void AddDistricts(QComboBox *DT);
void AddInitialDate(QComboBox *Day, QComboBox *Month, QComboBox *Year);

template<class widget>
void ChangeTextDisplay(widget *name, int size, QString Font, QString BOLD){
    QFont f(Font, size);
    name->setFont(f);
    name->setStyleSheet("font-weight : "+BOLD+";");

}

template<class widget>
void Animation(widget *Name, QString color1, QString color2, QString radius){

    if (dynamic_cast<QPushButton*>(Name) != nullptr)
    {
        Name->setStyleSheet(
            "QPushButton:enabled{border-radius: "+radius+"px;"
                                                             "background-color:"+color2+";"
                       "color:"+color1+";}"
                       "QPushButton:pressed{"
                       "background-color: indigo;"
                       "color: seagreen;}"
                       "QPushButton:hover:!pressed{"
                       "background-color:"+color1+";"
                       "color: "+color2+";}"
            );
    }

    // Check if the widget is a QLineEdit
    else if (dynamic_cast<QLineEdit*>(Name) != nullptr)
    {
        Name->setStyleSheet(
            "QLineEdit:hover {border-radius: "+radius+"px;"
            "color:" + color1 + ";"
            "background-color: " + color1 + ";}"
            "QLineEdit:focus {color:" + color1 + ";"
            "background-color: " + color2 + ";}"
        );
    }
    else if(dynamic_cast<QComboBox*>(Name) != nullptr){
        Name->setStyleSheet(
            "QComboBox {border-radius: "+radius+"px;"
                                                    "background-color: red;}"
                                                    "QComboBox::down-arrow {background-color: blue;}"
                                                    "QComboBox::drop-down:open {background-color: black;}"
                                                    "QComboBox::item:selected {"
                                                    "background-color: cyan;"
                                                    "color: green;}"
            );
    }
    else if (dynamic_cast<QLabel*>(Name) != nullptr)
    {
        Name->setStyleSheet(
            "QLabel {"
            "border-radius:"+radius+"px;"
                       "background-color:"+color2+";"
                       "color: "+color1+";}");
    }
    else if (dynamic_cast<QPlainTextEdit*>(Name) != nullptr){
        Name->setStyleSheet(
            "QPlainTextEdit{border-radius:"+radius+";color:"+color2+";background-color:rgba(241, 234, 185, 0.1);"
                                                                            "border : 5px solid red; border-color:rgb(188, 137, 82);}"
                                                                            "QPlainTextEdit:hover{border-radius:"+radius+"; color:" +color1+";background-color:rgba(241, 234, 185, 0.9);}"
            );
    }

}

void InitializeQLabels(QLabel *[]);


#endif // NONCLASSFUNCTIONS_H
