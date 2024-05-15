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

class Item
{
private:
    unsigned m_uArticle{};//Артикул
    QString m_strName{};//Наименование
    double m_dCost{};//Закупочная стоимость
    double m_dPrice{};//Цена
    QString m_strDefinition{};//Размещение на складе
    unsigned int m_iRemain{};//Остаток на складе
    QDate m_dateTime{};//Срок годности
    unsigned int m_iNumOfParty{};//Номер партии

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

