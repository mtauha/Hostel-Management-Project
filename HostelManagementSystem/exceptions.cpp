#include "exceptions.h"

Exceptions::Exceptions()
{

}

bool Exceptions::CheckAllExceptions(QString str, QString Type, QPlainTextEdit *EB)
{

    if(Type == "NAME1")
    {
        if(str.isEmpty()){
            EB->appendPlainText(" ~ You Must Enter Your First Name.\n");
            return false;}

        for (int i = 0; i < str.length(); i++) {
            QChar ch = str.at(i);
            if (!ch.isLetter())
            { // Check if character is not a letter
                if(ch==' '){
                    continue ;
                }

                EB->appendPlainText("  ~ Name Can not have Special Characters or Numbers (First Name).\n");
                return false; // Return true if a non-letter character is found
            }
        }
    }
    if(Type == "NAME2")
    {
        if(str.isEmpty()){
            EB->appendPlainText(" ~ You Must Enter Your Second Name.\n");
            return false;}

        for (int i = 0; i < str.length(); i++) {
            QChar ch = str.at(i);
            if (!ch.isLetter())
            { // Check if character is not a letter
                if(ch==' '){
                    continue ;
                }
                EB->appendPlainText("  ~ Name Can not have Special Characters or Numbers (Second Name).\n");
                return false; // Return true if a non-letter character is found
            }
        }
        return true; // Return true if no non-letter character is found
    }
    else if(Type == "GNAME")
    {
        {
            if(str.isEmpty())
            {
                EB->appendPlainText(" ~ You Must Enter Your Guardian's Name.\n");
                return false;
            }
            for (int i = 0; i < str.length(); i++)
            {
                QChar ch = str.at(i);
                if (!ch.isLetter())
                { // Check if character is not a letter
                    if(ch==' '){
                        continue ;
                    }
                    EB->appendPlainText("  ~ Name Can not have Special Characters or Numbers (Guardian Name).\n");
                    return false;
                }
            }
            return true; // Return false if no non-letter character is found
        }
    }
    else if(Type == "NUMBER")
    {
        if(str.isEmpty())
        {
            EB->appendPlainText("  ~ You Must Enter Your Phone Number.\n");
            return false;
        }

        if(str.at(0) !='0' || str.at(1) !='3' || (str.at(2) >'5'))
        {
            EB->appendPlainText("  ~ Invalid Phone Number (Your Number).\n");
            return false;
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (!str.at(i).isDigit())
            {
                EB->appendPlainText("  ~ Invalid Phone Number (Your Number).\n");
                return false;
            }
        }
        return true;
    }
    else if(Type == "CNIC")
    {
        if(str.isEmpty())
        {
            EB->appendPlainText("  ~ You Must Enter Your CNIC.\n");
            return false;
        }

        // Check if all characters are digits
        for (int i = 0; i < str.length(); i++)
        {
            if (!str.at(i).isDigit())
            {
                EB->appendPlainText("  ~ Invalid CNIC.\n");
                return false;
            }
        }

        // CNIC should consist of 13 characters
        if (str.length() != 13)
        {
            EB->appendPlainText("  ~ CNIC Must Contain 13 Digits.\n");
            return false;
        }
        return true;
    }
    else if(Type == "EMAIL")
    {
        if(str.isEmpty()){
            EB->appendPlainText("  ~ You Must Enter your Email Address\n");
            return false;
        }
        return true;
    }
    else if(Type == "GNUMBER")
    {
        if(str.isEmpty())
        {
            EB->appendPlainText("  ~ You Must Enter Your Guardian's Phone Number.\n");
            return false;
        }

        if(str.at(0) !='0' || str.at(1) !='3' || (str.at(2) >'5'))
        {
            EB->appendPlainText("  ~ Invalid Phone Number (Guardian).\n");
            return false;
        }

        for (int i = 0; i < str.length(); i++)
        {
            if (!str.at(i).isDigit())
            {
                EB->appendPlainText("  ~ Invalid Phone Number (Guardian).\n");
                return false;
            }
        }
        return true;
    }
    else
    {
        if(str.isEmpty()){
            EB->appendPlainText("  ~ You Must Enter your Postal Address\n");
            return false;
        }
        return true;
    }
}

