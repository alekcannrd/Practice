#include "addmenu.h"
void AddMenu::initGUI()
{
    //установка размеров окна
    setMinimumSize(250,250);
    setWindowTitle("Добавить элемент");

    createLines();
    createButtons();
    setLayout(m_pMainLayout);
}


AddMenu::AddMenu(List *q, QDialog *parent) :
    QDialog(parent), m_pList(q)
{
    initGUI();
    createConnections();
}

AddMenu::~AddMenu()
{
    delete m_pNameLine;
    delete m_pCostLine;
    delete m_pPriceLine;
    delete m_pDefinitionLine;
    delete m_pRemainLine;
    delete m_pExpDateLine;
    delete m_pNumOfPartyLine;
}

void AddMenu::OnAccept()
{
    QDate date = QDate::fromString(m_pExpDateLine->text(),"dd.MM.yyyy");
    if (date.isValid())//проверка даты на валидность
    {m_pList->add(m_pList->getNextId(),m_pNameLine->text(),m_pCostLine->text().toDouble(),m_pPriceLine->text().toDouble(),m_pDefinitionLine->text(),m_pRemainLine->text().toInt(),date,m_pNumOfPartyLine->text().toInt());
    this->close();}
    else
    {

       QMessageBox::warning(this,tr("Ошибка"),tr("Некорректная дата"),"Ок");

    }

}

void AddMenu::OnRefuse()
{
    close();
}

void AddMenu::createButtons()
{
    m_pRefuse = new QPushButton("Отмена",this);
    m_pAccept = new QPushButton("Готово",this);
    m_pMainLayout->addWidget(m_pRefuse);
    m_pMainLayout->addWidget(m_pAccept);

}

void AddMenu::createConnections()
{
    connect(m_pRefuse,&QPushButton::clicked,this,OnRefuse);
    connect(m_pAccept,&QPushButton::clicked,this,OnAccept);
}

void AddMenu::createLines()
{
    m_pNameLine = new QLineEdit(this);
    m_pCostLine = new QLineEdit(this);
    m_pPriceLine = new QLineEdit(this);
    m_pDefinitionLine = new QLineEdit(this);
    m_pRemainLine = new QLineEdit(this);
    m_pExpDateLine = new QLineEdit(this);
    m_pNumOfPartyLine = new QLineEdit(this);
//создание и установка валидаторов
    QValidator *iValidator = new QIntValidator(this);
    QValidator *dValidator = new QDoubleValidator(this);
    QValidator *timeValidator = new QRegularExpressionValidator(QRegularExpression("^[0-9]{2}.[0-9]{2}.[0-9]{4}$"));

    m_pCostLine->setValidator(dValidator);
    m_pPriceLine->setValidator(dValidator);
    m_pRemainLine->setValidator(iValidator);
    m_pNumOfPartyLine->setValidator(iValidator);
    m_pExpDateLine->setValidator(timeValidator);
//размещение полей на макете
    m_pMainLayout->addRow(strTitleNames[1],m_pNameLine);
    m_pMainLayout->addRow(strTitleNames[2],m_pCostLine);
    m_pMainLayout->addRow(strTitleNames[3],m_pPriceLine);
    m_pMainLayout->addRow(strTitleNames[4],m_pDefinitionLine);
    m_pMainLayout->addRow(strTitleNames[5],m_pRemainLine);
    m_pMainLayout->addRow(strTitleNames[6],m_pExpDateLine);
    m_pMainLayout->addRow(strTitleNames[7],m_pNumOfPartyLine);

}
