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
    void OnAccept();
    void OnRefuse();

protected:
    QFormLayout* m_pMainLayout{new QFormLayout(this)};
    void createButtons();
    void createConnections();
    void createLines();
    QLineEdit* m_pNameLine;
    QLineEdit* m_pCostLine;
    QLineEdit* m_pPriceLine;

    QLineEdit* m_pDefinitionLine;
    QLineEdit* m_pRemainLine;
    QLineEdit* m_pExpDateLine;
    QLineEdit* m_pNumOfPartyLine;

    void initGUI();
    QPushButton* m_pRefuse;
    QPushButton* m_pAccept;

    List* m_pList;
    Item* m_pItem;
    bool* m_pbAccepted;

};
