#ifndef QUERY_H
#define QUERY_H
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
#include <QtSql/QSqlRecord>


class Query
{
public:
    Query();


    template<typename Type, typename Type2>
    Type getAttribute(const QString& attribute2, const Type2& attribute2Value, const QString& table, int place) {
        QSqlQuery query;

        QString getQuery = "SELECT * FROM " + table + " WHERE " + attribute2 + " = :" + attribute2;

        query.prepare(getQuery);
        query.bindValue(":" + attribute2, attribute2Value);

        // Execute the query and retrieve the result
        if (query.exec() && query.next()) {
            return query.value(place).value<Type>();
        }

        // Return a default value if no result is found or if an error occurs
        return Type();
    }

    template <typename Type, int Place, typename IDType>
    void updateAttribute(const QString& attribute,Type attributeValue, const QString& TableName,QString id, IDType StudentId){

        QMessageBox messageBox;
        QSqlDatabase db = QSqlDatabase::database();  // Get the default database connection
        QSqlRecord tableSchema = db.record(TableName);  // Retrieve the table schema

        if (tableSchema.contains(attribute)) {
            // Attribute exists in the table, proceed with the update operation

            QSqlQuery query;
            query.prepare("UPDATE " + TableName + " SET " + attribute + " = :attributeValue WHERE " + id + " = :StudentId");
            query.bindValue(":attributeValue", attributeValue);  // Replace Type with the actual value you want to set for the attribute
            query.bindValue(":StudentId", StudentId);


            if (query.exec()) {
                messageBox.setWindowTitle("Update Info");
                messageBox.setText("Attribute has been updated");
                messageBox.setStyleSheet("QMessageBox { border-radius: 10px; }");
                messageBox.exec();
            } else {
                // Handle error if the update operation fails
                messageBox.setWindowTitle("Update Error");
                messageBox.setText("Attribute has not been updated");
                messageBox.setStyleSheet("QMessageBox { border-radius: 10px; }");
                messageBox.exec();
            }
        } else {
            // Attribute does not exist in the table, show an error message or handle it accordingly
            messageBox.setWindowTitle("Error 404");
            messageBox.setText("Attribute not found");
            messageBox.setStyleSheet("QMessageBox { border-radius: 10px; }");
            messageBox.exec();
        }
    }

    void Transfer_Reg_Main(QString key, QString Room) {
        QMessageBox* messageBox = new QMessageBox;

        QString Selection = "SELECT * FROM Registration WHERE CNIC = :key";
        QString Insert = "INSERT INTO Main (Name, Date_Of_Birth, Room_Number, Contact, Address, Email, CNIC, Guardian_Name, Guardian_Contact, District, Photo_Link) "
                         "VALUES (:value1, :value2, :value3, :value4, :value5, :value6, :value7, :value8, :value9, :value10, :value11)";
        QString Delete = "DELETE FROM Registration WHERE CNIC = :key";

        QSqlQuery selectQuery;
        QSqlQuery insertQuery;
        QSqlQuery deleteQuery;

        selectQuery.prepare(Selection);
        selectQuery.bindValue(":key", key);

        if (selectQuery.exec()) {
            if (selectQuery.next()) {
                // Retrieve the data from the registration table
                QString value1 = selectQuery.value(1).toString();
                QString value2 = selectQuery.value(2).toString();
                QString value3 = Room; // Set Room as Room_Number
                QString value4 = selectQuery.value(3).toString();
                QString value5 = selectQuery.value(4).toString();
                QString value6 = selectQuery.value(0).toString();
                QString value7 = selectQuery.value(6).toString();
                QString value8 = selectQuery.value(7).toString();
                QString value9 = selectQuery.value(8).toString();
                QString value10 = selectQuery.value(9).toString();
                QString value11 = selectQuery.value(5).toString(); // Assuming Photo_Link is at index 5

                // Insert the data into the main table
                insertQuery.prepare(Insert);
                insertQuery.bindValue(":value1", value1);
                insertQuery.bindValue(":value2", value2);
                insertQuery.bindValue(":value3", value3);
                insertQuery.bindValue(":value4", value4);
                insertQuery.bindValue(":value5", value5);
                insertQuery.bindValue(":value6", value6);
                insertQuery.bindValue(":value7", value7);
                insertQuery.bindValue(":value8", value8);
                insertQuery.bindValue(":value9", value9);
                insertQuery.bindValue(":value10", value10);
                insertQuery.bindValue(":value11", value11);

                if (insertQuery.exec()) {
                    // Remove the data from the registration table
                    deleteQuery.prepare(Delete);
                    deleteQuery.bindValue(":key", key);

                    if (deleteQuery.exec()) {
                        messageBox->setWindowTitle("Transfer Success");
                        messageBox->setText("Data transferred");
                        messageBox->setStyleSheet("QMessageBox { border-radius: 10px; }");
                        messageBox->exec();
                    } else {
                        messageBox->setWindowTitle("Delete Error");
                        messageBox->setText("Failed to delete data from Registration table");
                        messageBox->setStyleSheet("QMessageBox { border-radius: 10px; }");
                        messageBox->exec();
                    }
                } else {
                    messageBox->setWindowTitle("Insert Error");
                    messageBox->setText("Failed to insert data into Main table");
                    messageBox->setStyleSheet("QMessageBox { border-radius: 10px; }");
                    messageBox->exec();
                }
            } else {
                messageBox->setWindowTitle("Record Not Found");
                messageBox->setText("No record found in Registration table with the provided CNIC");
                messageBox->setStyleSheet("QMessageBox { border-radius: 10px; }");
                messageBox->exec();
            }
        } else {
            messageBox->setWindowTitle("Select Error");
            messageBox->setText("Failed to execute the select query");
            messageBox->setStyleSheet("QMessageBox { border-radius: 10px; }");
            messageBox->exec();
        }
    }



    void setMembers(QString key, QString Room, QString UN, QString PW, QString CMS){
        Transfer_Reg_Main(key,Room);

        QSqlQuery query;
        query.prepare("INSERT INTO Main (CMS, User_name, Password) VALUES (:cms, :un, :pd)");
        query.bindValue(":cms", CMS);
        query.bindValue(":un", UN);
        query.bindValue(":pd", PW);


        if (!query.exec()) {
            QMessageBox messageBox;
            messageBox.setWindowTitle("Insert Error");
            messageBox.setText("Failed to insert data into Main table");
            messageBox.setStyleSheet("QMessageBox { border-radius: 10px; }");
            messageBox.exec();
        }
    }


    void CheckVacantRoom(QString table)
    {
        QSqlQuery *query = new QSqlQuery;
        QMessageBox *messageBox = new QMessageBox;


        query->prepare("SELECT Room_Number FROM " + table);

        if (query->exec()) {
            QStringList vacantRooms;
            while (query->next()) {
                QString roomNumber = query->value(0).toString();
                QString vacancy = query->value(2).toString();
                qDebug() << vacancy;
                int check = vacancy.toInt();
                qDebug() << check;
                if(check > 0 && check <= 3)
                    vacantRooms.append(roomNumber);
            }

            if (vacantRooms.isEmpty()) {
                messageBox->setWindowTitle("No Vacant Rooms");
                messageBox->setText("All rooms are occupied.");
            } else {
                QString vacantRoomsText = "Vacant Rooms:\n" + vacantRooms.join("\n");
                messageBox->setWindowTitle("Vacant Rooms");
                messageBox->setText(vacantRoomsText);
            }

            messageBox->setStyleSheet("QMessageBox { border-radius: 10px; }");
            messageBox->exec();

            delete messageBox;
        } else {
            messageBox->setWindowTitle("Error");
            messageBox->setText("Failed to execute the query");
            messageBox->setStyleSheet("QMessageBox { border-radius: 10px; }");
            messageBox->exec();

            delete messageBox;
        }

        delete query;
    }
};



#endif // QUERY_H
