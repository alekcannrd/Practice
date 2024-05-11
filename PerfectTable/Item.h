#pragma once
#include <QString>
#include <QDate>
#include <QTextStream>
#include <QVariant>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include "Constants.h"
using namespace std;
class Item
{
private:
    unsigned m_uArticle{};
    QString m_strName{};
	double m_dCost{};
	double m_dPrice{};
    QString m_strDefinition{};
	unsigned int m_iRemain{};
    QDate m_dateTime{};
	unsigned int m_iNumOfParty{};

public:
	Item();
    QVariant operator[](int index);
    friend QTextStream& operator>>(QTextStream& in, Item& item);
    friend QTextStream& operator<<(QTextStream &out, Item& item);

    Item(int, QString, double, double, QString, int, QDate, int);

    QString getName() { return m_strName; }
	double getCost() { return m_dCost; }
	double getPrice() { return m_dPrice; }
    QString getDefinition() { return m_strDefinition; }
    unsigned getArticle() { return m_uArticle; }
	unsigned int getRemain() { return m_iRemain; }
    QDate getTime() { return m_dateTime; }
	int getNumOfParty() { return m_iNumOfParty; }
    void copy(Item* after);


};

