#include <QCoreApplication>
#include <iostream>
#include <string>
#include <QTextStream>

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
        std::cout << "Nice" << std::endl;
    }
    return a.exec();
}
