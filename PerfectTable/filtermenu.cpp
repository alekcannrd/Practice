#include "filtermenu.h"


FilterMenu::FilterMenu(int* choice,QString *text,QDialog *parent)
    :
      QDialog(parent),
      m_pText(text),
      m_piChoice(choice),
      m_pMainLayout(new QVBoxLayout(this))

{
    initGUI();
    createConnections();
}

void FilterMenu::OnAccept()
{

    *m_pText = m_pLineEdit->text();
    *m_piChoice = m_pComboBox->currentIndex();
    close();
}

void FilterMenu::OnRefuse()
{
    close();
}

void FilterMenu::initGUI()
{
    setWindowTitle("Выберите поле для сортировки и значение для поиска");
    setFixedSize(300,200);
    createLines();
    createButtons();
    setLayout(m_pMainLayout);
}

void FilterMenu::createButtons()
{
    m_pAcceptBtn = new QPushButton("Ок",this);
    m_pRefuseBtn = new QPushButton("Отмена",this);

    QHBoxLayout* btnLayout = new QHBoxLayout(this);

    btnLayout->addWidget(m_pAcceptBtn);
    btnLayout->addWidget(m_pRefuseBtn);

    m_pMainLayout->addLayout(btnLayout);
}

void FilterMenu::createLines()
{
    m_pLineEdit = new QLineEdit(this);
    m_pComboBox = new QComboBox(this);

    QHBoxLayout* linesLayout = new QHBoxLayout(this);

    QStringList nameList = {"Артикул","Наименование","Закупочная стоимость","Цена","Размещение на складе","Остаток на складе","Срок годности","Номер партии"};
    m_pComboBox->insertItems(0,nameList);

    linesLayout->addWidget(m_pComboBox);
    linesLayout->addWidget(m_pLineEdit);

    m_pMainLayout->addLayout(linesLayout);

}

void FilterMenu::createConnections()
{
    connect(m_pAcceptBtn,&QPushButton::clicked,this,OnAccept);
    connect(m_pRefuseBtn,&QPushButton::clicked,this,OnRefuse);
}
