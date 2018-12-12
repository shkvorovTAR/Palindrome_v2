#include <QFile>
#include <QDebug>
#include <QString>
#include <iostream>

static QString available = "abcdefghijklmnopqrstuvwxyz0123456789";

//Funkcija proverki na palindrom
bool checkPalindrome(QString line)
{

    QString formatted = "";
    for (QChar c : line.toLower())
    {
        if (available.contains(c))
        {
            formatted += c;
        }
    }

    for (int i = 0; i < formatted.length() / 2; i++)
    {
        if (formatted[i] != formatted[formatted.length() - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    qDebug () << "Homework: Palindrome!";
    qDebug () << " ";
    qDebug () << "Input file you can find in Build directory";
    qDebug () << "Output file you can find in Build directory";

    QFile input("input.txt");
    input.open(QIODevice::ReadOnly);
    QFile output("output.txt");
    output.open(QIODevice::WriteOnly);
    while (!input.atEnd())
    {
        QString line = input.readLine();
        if (checkPalindrome(line))
        {
            output.write("yes, it  is a palindrome: ");
        }
        else
        {
            output.write("this is not a palindrome: ");
        }
        output.write(line.toStdString().c_str());
    }

    return 0;
}
