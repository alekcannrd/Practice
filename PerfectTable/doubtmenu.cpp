#include "doubtmenu.h"



DoubtMenu::DoubtMenu(bool *accepted, QDialog *parent):
    QDialog(parent), m_pbAccepted(accepted), m_pMainLayout{new QHBoxLayout(this)}
{
    initGUI();
    createConnections();
}

void DoubtMenu::OnAccept()
{
    *m_pbAccepted = true;
    close();
}

void DoubtMenu::OnRefuse()
{
    close();
}

void DoubtMenu::initGUI()
{
    setMinimumSize(200,200);
    setWindowTitle("Вы уверены?");
    createButtons();
    createConnections();
    setLayout(m_pMainLayout);
}

void DoubtMenu::createButtons()

{
    m_pAcceptBtn = new QPushButton("Да",this);
    m_pRefuseBtn = new QPushButton("Нет",this);
    m_pMainLayout->addWidget(m_pAcceptBtn);


    m_pMainLayout->addWidget(m_pRefuseBtn);
}

void DoubtMenu::createConnections()
{
    connect(m_pAcceptBtn, QPushButton::clicked,this,OnAccept);
    connect(m_pRefuseBtn, QPushButton::clicked,this,OnRefuse);
}
