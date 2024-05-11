#include "table.h"
#include <QHBoxLayout>
#include <QPushButton>


Table::Table(List* list,QWidget *parent)
    : QWidget(parent),
      m_pTable{new TableWidget(this)}
{
    initGUI(list);
    //Item a = Item(1,"qwe",2,2,"asd",54,34,23);
    //addRow(&a);
}

Table::~Table()
{

}

void Table::initGUI(List *list)
{
    QHBoxLayout *pMain{new QHBoxLayout()};

    setupTable(list);

    pMain->addWidget(m_pTable);

    setWindowTitle("WindowerTest");

    setLayout(pMain);
}

void Table::setupTable(List *list)
{
    m_pTable->setRowCount(list->getSize());
    m_pTable->setColumnCount(static_cast<int>(TITLES::TITLE_SIZE));

    for(int i = 0; i < list->getSize(); ++i)
    {
        for(int j = 0; j < static_cast<int>(TITLES::TITLE_SIZE); ++j)
        {
            QTableWidgetItem *item = new QTableWidgetItem;

            //{list->m_vItemList[i][j]};
            m_pTable->setItem(i, j, item);
            item->setFlags(item->flags() &~ Qt::ItemIsEditable);
        }
    }

}

//void Table::addRow(Item *item)
//{
//    int currentRow = m_pTable->rowCount();
//    m_pTable->insertRow(currentRow);
//    for (int i{};i<static_cast<int>(TITLES::TITLE_SIZE);++i)
//    {
//        m_pTable->setItem(currentRow,i,new QTableWidgetItem((*item)[i]));
//    };
//}

