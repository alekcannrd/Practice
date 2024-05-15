#pragma once
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include "List.h"

class MyChangeMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MyChangeMenu(List *q,Item* item, bool *accepted,QDialog *parent = nullptr);
    ~MyChangeMenu();
protected slots:
    void OnAccept();//слот "принять"
    void OnRefuse();//слот "отмена"

protected:
    QFormLayout* m_pMainLayout{new QFormLayout(this)};//макет окна
    void createButtons();//создание кнопок
    void createConnections();//создание связей между кнопками и слотами
    void createLines();//создание полей для ввода
    QLineEdit* m_pNameLine;//поле наименования
    QLineEdit* m_pCostLine;//поле стоимости
    QLineEdit* m_pPriceLine;//поле цены

    QLineEdit* m_pDefinitionLine;//поле размещения на складе
    QLineEdit* m_pRemainLine;//поле остатка на складе
    QLineEdit* m_pExpDateLine;//поле срока годности
    QLineEdit* m_pNumOfPartyLine;//поле номера партии

    void initGUI();//инициализация интерфейса
    QPushButton* m_pRefuse;//кнопка "отмена"
    QPushButton* m_pAccept;//кнопка "подтвердить"

    List* m_pList;
    Item* m_pItem;
    bool* m_pbAccepted;

};
