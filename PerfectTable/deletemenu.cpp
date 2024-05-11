#include "deletemenu.h"



DeleteMenu::DeleteMenu(List *list, QDialog *parent) :
    QDialog(parent), m_pList(list)
{
    initGUI();
    createConnections();
}

void DeleteMenu::initGUI()
{
    setMinimumSize(250,250);
    setWindowTitle("Are");
    createLines();
    createButtons();
    //setLayout(m_pMainLayout);

}

void DeleteMenu::createLines()
{
//    m_pIdLine = new QLineEdit("Артикул: ",this);

}

void DeleteMenu::createButtons()
{
    m_pAcceptBtn = new QPushButton("Принять", this);
    m_pRefuseBtn = new QPushButton("Отменить",this);
}

void DeleteMenu::createConnections()
{
    connect(m_pAcceptBtn, &QPushButton::clicked, this, OnAccept);
    connect(m_pRefuseBtn, &QPushButton::clicked, this, OnRefuse);
}
