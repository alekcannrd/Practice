#include "filteredtable.h"


FilteredTable::FilteredTable(List* list,QDialog *parent)
    :
      QDialog(parent),
      m_pList(list),
      m_pMainLayout(new QVBoxLayout(this)),
      m_pTable(new TableWidget(this))
{
    initGUI();
    createConnections();
}

void FilteredTable::OnClose()
{
    close();
}

void FilteredTable::createButtons(){
    m_pCloseBtn = new QPushButton("Закрыть",this);
    m_pMainLayout->addWidget(m_pCloseBtn);
}

void FilteredTable::createConnections()
{
    connect(m_pCloseBtn,&QPushButton::clicked,this,OnClose);
}

void FilteredTable::initGUI()
{
    setWindowTitle("Отфильтрованная таблица");
    setMinimumSize(m_cuWindowWidth,500);
    setupTable();
    m_pMainLayout->addWidget(m_pTable);
    createButtons();
    setLayout(m_pMainLayout);


}

void FilteredTable::setupTable()
{
    m_pTable->setRowCount(m_pList->getSize());
    m_pTable->setColumnCount(static_cast<int>(TITLES::TITLE_SIZE));
    for (int i{};i<static_cast<int>(TITLES::TITLE_SIZE);++i)
    {
        m_pTable->setColumnWidth(i,150);
        m_pTable->setHorizontalHeaderItem(i,new QTableWidgetItem{strTitleNames[i]});
    }

    for(int i = 0; i < m_pList->getSize(); ++i)
    {
        for(int j = 0; j < static_cast<int>(TITLES::TITLE_SIZE); ++j)
        {

            QTableWidgetItem *item = new QTableWidgetItem;
            item->setData(Qt::EditRole,(*m_pList)[i][j]);
            m_pTable->setItem(i, j, item);
            item->setFlags(item->flags() &~ Qt::ItemIsEditable);
        }
    }
}
