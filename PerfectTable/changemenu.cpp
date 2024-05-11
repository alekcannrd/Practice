#include "changemenu.h"
void ChangeMenu::initGUI()
{
    setMinimumSize(250,250);
    setWindowTitle("ChangeMenu");
    createLines();
    createButtons();
    setLayout(m_pMainLayout);
}


ChangeMenu::ChangeMenu(List *q, Item* item, bool* accepted, QDialog *parent) :
    QDialog(parent), m_pList{q}, m_pItem(item), m_pbAccepted(accepted)
{
    initGUI();
    createConnections();
}

ChangeMenu::~ChangeMenu()
{
    delete m_pNameLine;
    delete m_pCostLine;
    delete m_pPriceLine;
    delete m_pDefinitionLine;
    delete m_pRemainLine;
    delete m_pExpDateLine;
    delete m_pNumOfPartyLine;
}

void ChangeMenu::OnAccept()
{
    QDate date = QDate::fromString(m_pExpDateLine->text(),"dd.MM.yyyy");
    if (date.isValid())
    {
        Item* item = new Item(m_pItem->getArticle(),m_pNameLine->text(),m_pCostLine->text().toDouble(),m_pPriceLine->text().toDouble(),m_pDefinitionLine->text(),m_pRemainLine->text().toInt(),date,m_pNumOfPartyLine->text().toInt());

        m_pList->change(m_pItem,item);
        *m_pbAccepted = true;
        this->close();
    }
    else
    {

        QMessageBox::warning(this,tr("Ошибка"),tr("Некорректная дата"),QMessageBox::Cancel);
    }


}

void ChangeMenu::OnRefuse()
{
    close();
}

void ChangeMenu::createButtons()
{
    m_pRefuse = new QPushButton("Отмена",this);
    m_pAccept = new QPushButton("Готово",this);
    m_pMainLayout->addWidget(m_pRefuse);
    m_pMainLayout->addWidget(m_pAccept);

}

void ChangeMenu::createConnections()
{
    connect(m_pRefuse,&QPushButton::clicked,this,OnRefuse);
    connect(m_pAccept,&QPushButton::clicked,this,OnAccept);
}

void ChangeMenu::createLines()
{
    m_pNameLine = new QLineEdit(this);
    m_pCostLine = new QLineEdit(this);
    m_pPriceLine = new QLineEdit(this);
    m_pDefinitionLine = new QLineEdit(this);
    m_pRemainLine = new QLineEdit(this);
    m_pExpDateLine = new QLineEdit(this);
    m_pNumOfPartyLine = new QLineEdit(this);

    QValidator *iValidator = new QIntValidator(this);
    QValidator *dValidator = new QDoubleValidator(this);
    QValidator *timeValidator = new QRegularExpressionValidator(QRegularExpression("^[0-9]{2}.[0-9]{2}.[0-9]{4}$"));

    m_pCostLine->setValidator(dValidator);
    m_pPriceLine->setValidator(dValidator);
    m_pRemainLine->setValidator(iValidator);
    m_pNumOfPartyLine->setValidator(iValidator);
    m_pExpDateLine->setValidator(timeValidator);


    m_pMainLayout->addRow(strTitleNames[1],m_pNameLine);
    m_pMainLayout->addRow(strTitleNames[2],m_pCostLine);
    m_pMainLayout->addRow(strTitleNames[3],m_pPriceLine);
    m_pMainLayout->addRow(strTitleNames[4],m_pDefinitionLine);
    m_pMainLayout->addRow(strTitleNames[5],m_pRemainLine);
    m_pMainLayout->addRow(strTitleNames[6],m_pExpDateLine);
    m_pMainLayout->addRow(strTitleNames[7],m_pNumOfPartyLine);

}
