#include "mainwindow.h"

MainWindow::MainWindow(List *q,QWidget *parent)
    : QWidget(parent), m_pTable{new TableWidget(this)}, m_pList{q}
{

    initGUI();
    createConnections();

}

MainWindow::~MainWindow(){}



void MainWindow::initGUI(){

    setMinimumSize(m_cuWindowWidth, 1000);
    setWindowTitle("Продовольственный магазин");
    createButtons();


    m_pTable->setGeometry(0,100,m_cuWindowWidth,800);

    setupTable();

    QHBoxLayout* toolLayout = new QHBoxLayout(this);
    for (int i{},total = m_qlButtonList.size();i<total;++i)
{
    toolLayout->addWidget(m_qlButtonList[i]);
}

    m_pMainLayout->addLayout(toolLayout);
    m_pMainLayout->addWidget(m_pTable);


    setLayout(m_pMainLayout);
}

void MainWindow::createConnections()
{

    connect(m_qlButtonList[0],&QPushButton::clicked,this,MainWindow::OnAdd);
        connect(m_qlButtonList[1],&QPushButton::clicked,this,MainWindow::OnDelete);
//        connect(m_qluttonList[2],&QPushButton::clicked,this,MainWindow::OnChange);
        connect(m_qlButtonList[8],&QPushButton::clicked,this,MainWindow::OnQuit);
        connect(m_qlButtonList[7],&QPushButton::clicked,this,MainWindow::OnLoad);
        connect(m_qlButtonList[6],&QPushButton::clicked,this,MainWindow::OnSave);
        connect(m_qlButtonList[3],&QPushButton::clicked,this,MainWindow::OnFilter);
        connect(m_qlButtonList[2],&QPushButton::clicked,this,MainWindow::OnSort);
        connect(m_qlButtonList[5],&QPushButton::clicked,this,MainWindow::OnGraphic);
        connect(m_pTable,m_pTable->cellChanged,this,&MainWindow::OnItemChanged);
        connect(m_qlButtonList[4],&QPushButton::clicked,this,&MainWindow::OnShow)
;

}

void MainWindow::createButtons()
{
    m_qlButtonList.push_back(new QPushButton("Добавить",this));
    m_qlButtonList.push_back(new QPushButton("Удалить",this));
//    m_qlButtonList.push_back(new QPushButton("Редактировать",this));
    m_qlButtonList.push_back(new QPushButton("Отсортировать",this));
    m_qlButtonList.push_back(new QPushButton("Фильтр",this));
    m_qlButtonList.push_back(new QPushButton("Отменить все фильтры",this));
    m_qlButtonList.push_back(new QPushButton("График",this));
    m_qlButtonList.push_back(new QPushButton("Сохранить как",this));
    m_qlButtonList.push_back(new QPushButton("Загрузить из файла",this));
    m_qlButtonList.push_back(new QPushButton("Выход",this));



}

void MainWindow::setupTable()//создание и заполнение таблицы данными по умолчанию
{
    m_pTable->setRowCount(m_pList->getSize());
    m_pTable->setColumnCount(static_cast<int>(TITLES::TITLE_SIZE));
    for (int i{};i<static_cast<int>(TITLES::TITLE_SIZE);++i)
    {
        m_pTable->setColumnWidth(i,m_cuColumnWidth);
        m_pTable->setHorizontalHeaderItem(i,new QTableWidgetItem{strTitleNames[i]});
    }

    for(int i = 0; i < m_pList->getSize(); ++i)
    {
        for(int j = 0; j < static_cast<int>(TITLES::TITLE_SIZE); ++j)
        {

            QTableWidgetItem *item = new QTableWidgetItem;
            item->setData(Qt::EditRole,(*m_pList)[i][j]);
            m_pTable->setItem(i, j, item);
//            item->setFlags(item->flags() &~ Qt::ItemIsEditable);
        }
    }
}



void MainWindow::OnQuit()
{
    QCoreApplication::quit();
}
void MainWindow::OnAdd()
{
    int sizeBefore = m_pList->getSize();
    AddMenu *menu = new AddMenu(m_pList);

    menu->exec();
    if (m_pList->getSize()!=sizeBefore)//проверка размера массива данных
    {
        m_pTable->insertRow(m_pList->getSize()-1);
        for(int j = 0; j < static_cast<int>(TITLES::TITLE_SIZE); ++j)
        {
            int id = m_pList->getSize()-1;
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setData(Qt::EditRole,(*m_pList)[id][j]);

            m_pTable->setItem(id, j, item);
        }
    };


}
void MainWindow::OnDelete()
{
    QList<QTableWidgetItem*> selected = m_pTable->selectedItems();

    if (selected.empty())//проверка размера массива данных
    {
        QMessageBox::warning(this,"Ошибка","Удаление невозможно: не выделен элемент","Ок");
    }

    //    bool accepted;
    else
    {
        std::vector<Item*> deletedItems;
        QString articles;
        int row;
        std::vector<int> rows;
        for (int i{},total=selected.size();i<total;++i)
        {
            if (m_pTable->row(selected[i])!=row)
            {
                row = m_pTable->row(selected[i]);
                rows.push_back(row);
                QVariant article = m_pTable->item(row,0)->data(Qt::EditRole);

                deletedItems.push_back(m_pList->findByArticle(article.toUInt()));
                articles += (article.toString())+'\n';
            }
        }


        QMessageBox doubt;
        doubt.setWindowTitle("Внимание!");
        doubt.setText("Вы уверены, что хотите удалить товары, артикул которых:\n" + articles + "?");
        QPushButton* yesBtn = doubt.addButton(tr("Да"),QMessageBox::ActionRole);
        QPushButton* noBtn = doubt.addButton(tr("Нет"),QMessageBox::ActionRole);
        noBtn->setFocus();
        doubt.exec();
        if (doubt.clickedButton() == yesBtn)
        {
            for (int i{},total=deletedItems.size();i<total;++i)
            {
                m_pList->del(*(deletedItems[i]));
                m_pTable->removeRow(rows[i]-i);
            }
        }
    };
}

//void MainWindow::OnChange()
//{
//    QList<QTableWidgetItem*> selected = m_pTable->selectedItems();

//    if (selected.empty())//проверка размера массива данных
//    {
//        QMessageBox::warning(this,"Ошибка","Редактирование невозможно: не выделен элемент","Ок");
//    }
//    if (m_pList->getSize()>0)
//    {
//        int curIndex = m_pTable->currentRow();
//        int article = (m_pTable->item(curIndex,0)->text()).toInt();
//        Item *changed = m_pList->findByArticle(article);
//        bool accepted = false;
//        MyChangeMenu* menu = new MyChangeMenu(m_pList,changed,&accepted);
//        menu->exec();
//        if (accepted)
//        {


//            for(int j = 0; j < static_cast<int>(TITLES::TITLE_SIZE); ++j)
//            {

//                QTableWidgetItem* item = m_pTable->item(curIndex,j);
//                item->setData(Qt::EditRole,(*m_pList)[curIndex][j]);
//            }
//        }
//    }
//    else
//    {
//        QMessageBox::warning(this,"Ошибка","Редактирование невозможно: пустой список","Ок");
//    }
//}

void MainWindow::OnLoad()
{
    QFileDialog *dialog = new QFileDialog(this);
    QString name = dialog->getOpenFileName(this,"Выберите файл","",tr("Text files (*txt)"));
    QFile* file = new QFile(name);
    if (!file->open(QIODevice::ReadOnly))
    {
        qWarning("Невозможно открыть файл для чтения");
    }
    else
    {
        QTextStream* in = new QTextStream(file);
        QString line;
        m_pList->clear();
        Item temp;
        while (!in->atEnd())
        {
            *in >> temp;
            m_pList->add(temp);
        }
        file->close();
        setupTable();
    }
}

void MainWindow::OnSave()
{
    QFileDialog *dialog = new QFileDialog(this);

    QString name = dialog->getSaveFileName(this,"Сохранить как","",tr("Text files (*txt)"));
    QFile* file = new QFile(name);
    if (!file->open(QIODevice::WriteOnly))
    {
        qWarning("Невозможно открыть файл для записи");
    }
    else
    {
        QTextStream* out = new QTextStream(file);
        for (int i{},total =m_pList->getSize();i<total;++i)
        {
            *out << (*m_pList)[i];
        }
        delete out;
        file->close();
    }
}

void MainWindow::OnSort()
{
    int choice;
    SortMenu* menu = new SortMenu(&choice);
    menu->exec();
    if (choice!=-1)
    {
        if (choice<static_cast<int>(TITLES::TITLE_SIZE))
        {
            m_pTable->sortItems(choice);
        }
        else
        {
            choice -= 8;
            m_pTable->sortItems(choice,Qt::DescendingOrder);
        }
    }
}

void MainWindow::OnFilter()
{
    int choice{-1};
    QString text;
    FilterMenu* menu = new FilterMenu(&choice,&text);
    menu->exec();

    if (choice!=-1)
    {
        for (int i{},total = m_pTable->rowCount();i<total;++i)
        {
            if ((m_pTable->item(i,choice)->text()!=text)&&!(m_pTable->isRowHidden(i)))
            {
                m_pTable->hideRow(i);

            }
        }


    };



    delete menu;

}

void MainWindow::OnGraphic()
{
    Diagram *diagram = new Diagram(*m_pList);
    diagram->exec();
    delete diagram;
}

void MainWindow::OnItemChanged(int row, int column)
{
    QVariant data = /*(*m_pList)[row][column] = */m_pTable->item(row,column)->data(Qt::EditRole);
    Item* item = m_pList->findByArticle(m_pTable->item(row,0)->data(Qt::EditRole).toUInt());
    switch (column)
    {
    case static_cast<int>(TITLES::article): item->setArticle(data.toUInt()); break;
    case static_cast<int>(TITLES::Cost): item->setCost(data.toDouble()); break;
    case static_cast<int>(TITLES::Price): item->setPrice(data.toDouble()); break;
    case static_cast<int>(TITLES::Definition): item->setDefinition(data.toString()); break;
    case static_cast<int>(TITLES::Name): item->setName(data.toString()); break;
    case static_cast<int>(TITLES::NumOfParty): item->setNum(data.toUInt()); break;
    case static_cast<int>(TITLES::Remain): item->setRemain(data.toUInt()); break;
    case static_cast<int>(TITLES::Time): item->setTime(data.toDate()); break;
    }
}

