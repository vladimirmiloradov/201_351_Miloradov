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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Загрузка массива из JSON
    QFile jsonFile("C:/Users/SIXTECH/Desktop/201_351_Miloradov/cridentials.json");
    if (!jsonFile.open(QIODevice::ReadOnly ))
    {
        return 0;
    }
    QByteArray saveData = jsonFile.readAll();
    QJsonDocument jsonDocument(QJsonDocument::fromJson(saveData));
    QJsonObject data = jsonDocument.object();

    //Парсинг в списки
    QStringList Logins;
    QStringList Passwords;
    QJsonArray array = data["cridentials"].toArray();
    foreach (const QJsonValue & value, array) {
        QJsonObject obj = value.toObject();
        Logins.append(obj["login"].toString());
        Passwords.append(obj["password"].toString());
    }

    //Запрос пинкода
    QTextStream cin(stdin);
    int pin(0);
    qDebug() << "Enter pincode: ";
    std::cin >> pin;

    //Если введён верный пинкод
    if (pin == 1234)
    {
        while (true)
        {
            qDebug() << "Enter id of social media account to get log/pass or -1 to exit: ";
            QTextStream cin(stdin);
            int id_user(0);
            std::cin >> id_user;
            if (id_user == -1)
            {
                return 0;
            }
            else if (id_user > 2)
            {
                qDebug() << "User with such id doesn't exist. Try another id.";
            }
            else
            {
                qDebug() << "Login: " << Logins[id_user];
                qDebug() << "Password " << Passwords[id_user];
            }
        }
    }
    else
    {
        qDebug() << "Incorrect pin. Try it again!";
    }
    return a.exec();
}
