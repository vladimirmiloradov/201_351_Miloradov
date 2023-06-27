#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QTextStream>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QFile>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTextStream cin(stdin);
    int pin(0);
    std::cout << "Enter pincode: ";
    std::cin >> pin;
    if (pin == 1234)
    {
        while (true)
        {
            QFile jsonFile("C:/Users/SIXTECH/Desktop/201_351_Miloradov/cridentials.json");
            if (!jsonFile.open(QIODevice::ReadOnly ))
            {
                return 0;
            }
            QByteArray saveData = jsonFile.readAll();
            QJsonDocument jsonDocument(QJsonDocument::fromJson(saveData));
            QJsonObject data = jsonDocument.object();
            QJsonArray array = data["cridentials"].toArray();
            std::cout << "Enter id of social media account to get log/pass or -1 to exit: ";
            QTextStream cin(stdin);
            int id_user(0);
            std::cin >> id_user;
            if (id_user == -1)
            {
                return 0;
            }
            else if (id_user > 2)
            {
                std::cout << "User with such id doesn't exist. Try another id.";
            }
            else
            {
                QJsonValueRef output = array[id_user];
                qDebug() << output;
            }
        }
    }
    return a.exec();
}
