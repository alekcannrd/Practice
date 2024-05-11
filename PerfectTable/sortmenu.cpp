#include "sortmenu.h"


SortMenu::SortMenu(int *pChoice, QDialog *parent):
    QDialog(parent), m_piChoice(pChoice), m_pMainLayout{new QHBoxLayout(this)}
{
    initGUI();
    createConnections();
}

void SortMenu::OnArticle()
{
    *m_piChoice = 0;
    close();
}

void SortMenu::OnName()
{
    *m_piChoice = 1;
    close();
}

void SortMenu::OnCost()
{
    *m_piChoice = 2;
    close();
}

void SortMenu::OnPrice()
{
    *m_piChoice = 3;
    close();
}

void SortMenu::OnDefinition()
{
    *m_piChoice = 4;
    close();
}

void SortMenu::OnRemain()
{
    *m_piChoice = 5;
    close();
}

void SortMenu::OnTime()
{
    *m_piChoice = 6;
    close();
}

void SortMenu::OnNumOfParty()
{
    *m_piChoice = 7;
    close();
}

void SortMenu::OnRefuse()
{
    *m_piChoice = 1000;
    close();
}

void SortMenu::initGUI()
{
    setWindowTitle("Выберите поле для сортировки");
    setMinimumSize(500,500);
    createButtons();
    setLayout(m_pMainLayout);
}

void SortMenu::createButtons()
{
    m_qlBtnList.push_back(new QPushButton("Артикуль",this));
    m_qlBtnList.push_back(new QPushButton("Наименование",this));
    m_qlBtnList.push_back(new QPushButton("Закупочная стоимость",this));
    m_qlBtnList.push_back(new QPushButton("Цена",this));
    m_qlBtnList.push_back(new QPushButton("Размещение на складе",this));
    m_qlBtnList.push_back(new QPushButton("Остаток на складе",this));
    m_qlBtnList.push_back(new QPushButton("Срок годности",this));
    m_qlBtnList.push_back(new QPushButton("Номер партии",this));
    m_qlBtnList.push_back(new QPushButton("Отмена",this));

    for (int i{};i<m_qlBtnList.size();++i)
    {
        m_pMainLayout->addWidget(m_qlBtnList[i]);
    };

}

void SortMenu::createConnections()
{
    connect(m_qlBtnList[0],&QPushButton::clicked,this,OnArticle);
    connect(m_qlBtnList[1],&QPushButton::clicked,this,OnName);
    connect(m_qlBtnList[2],&QPushButton::clicked,this,OnCost);
    connect(m_qlBtnList[3],&QPushButton::clicked,this,OnPrice);
    connect(m_qlBtnList[4],&QPushButton::clicked,this,OnDefinition);
    connect(m_qlBtnList[5],&QPushButton::clicked,this,OnRemain);
    connect(m_qlBtnList[6],&QPushButton::clicked,this,OnTime);
    connect(m_qlBtnList[7],&QPushButton::clicked,this,OnNumOfParty);
    connect(m_qlBtnList[8],&QPushButton::clicked,this,OnRefuse);

}
