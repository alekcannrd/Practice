#include "sortmenu.h"


SortMenu::SortMenu(int *pChoice, QDialog *parent):
    QDialog(parent), m_piChoice(pChoice), m_pMainLayout{new QVBoxLayout(this)}, m_pVectorBox(new QComboBox(this)),
    m_pFieldBox(new QComboBox(this))
{
    initGUI();
    createConnections();
}

//void SortMenu::OnArticle()
//{
//    *m_piChoice = 0+m_pVectorBox->currentIndex()*7;
//    close();
//}

//void SortMenu::OnName()
//{
//    *m_piChoice = 1+m_pVectorBox->currentIndex()*7;
//    close();
//}

//void SortMenu::OnCost()
//{
//    *m_piChoice = 2+m_pVectorBox->currentIndex()*7;
//    close();
//}

//void SortMenu::OnPrice()
//{
//    *m_piChoice = 3+m_pVectorBox->currentIndex()*7;
//    close();
//}

//void SortMenu::OnDefinition()
//{
//    *m_piChoice = 4+m_pVectorBox->currentIndex()*7;
//    close();
//}

//void SortMenu::OnRemain()
//{
//    *m_piChoice = 5+m_pVectorBox->currentIndex()*7;
//    close();
//}

//void SortMenu::OnTime()
//{
//    *m_piChoice = 6+m_pVectorBox->currentIndex()*7;
//    close();
//}

//void SortMenu::OnNumOfParty()
//{
//    *m_piChoice = 7+m_pVectorBox->currentIndex()*7;
//    close();
//}

void SortMenu::OnRefuse()
{
    *m_piChoice = -1;
    close();
}

void SortMenu::initGUI()
{
    setWindowTitle("Сортировка");
    setFixedSize(200,150);
    createButtons();
    setLayout(m_pMainLayout);
}

void SortMenu::createButtons()
{
//    m_qlBtnList.push_back(new QPushButton("Артикуль",this));
//    m_qlBtnList.push_back(new QPushButton("Наименование",this));
//    m_qlBtnList.push_back(new QPushButton("Закупочная стоимость",this));
//    m_qlBtnList.push_back(new QPushButton("Цена",this));
//    m_qlBtnList.push_back(new QPushButton("Размещение на складе",this));
//    m_qlBtnList.push_back(new QPushButton("Остаток на складе",this));
//    m_qlBtnList.push_back(new QPushButton("Срок годности",this));
//    m_qlBtnList.push_back(new QPushButton("Номер партии",this));
    m_qlBtnList.push_back(new QPushButton("Подтвердить",this));
    m_qlBtnList.push_back(new QPushButton("Отмена",this));


    QHBoxLayout* btnLayout = new QHBoxLayout(this);

    QLabel* label = new QLabel("Выберите поле для сортировки и ее направление");
    m_pMainLayout->addWidget(label);
    QStringList nameList = {"Артикул","Наименование","Закупочная стоимость","Цена","Размещение на складе","Остаток на складе","Срок годности","Номер партии"};

    m_pFieldBox->insertItems(0,nameList);

    QStringList items{"По возрастанию","По убыванию"};
    m_pVectorBox->insertItems(0,items);

    m_pMainLayout->addWidget(m_pFieldBox);
    m_pMainLayout->addWidget(m_pVectorBox);
    for (int i{};i<m_qlBtnList.size();++i)
    {
        btnLayout->addWidget(m_qlBtnList[i]);
    };
    m_pMainLayout->addLayout(btnLayout);
}

void SortMenu::createConnections()
{
    connect(m_qlBtnList[0],&QPushButton::clicked,this,&SortMenu::OnAccept);
    connect(m_qlBtnList[1],&QPushButton::clicked,this,&SortMenu::OnRefuse);

}
