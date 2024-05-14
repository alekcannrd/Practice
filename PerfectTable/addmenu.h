#pragma once
#include <QApplication>
#include <QDialog>
#include <QMessageBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegularExpressionValidator>
#include "List.h"
class AddMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AddMenu(List *q,QDialog *parent = nullptr);
    ~AddMenu();
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

};


