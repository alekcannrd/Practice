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
    setWindowTitle("Идеальная таблица");
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
        connect(m_qlButtonList[2],&QPushButton::clicked,this,MainWindow::OnChange);
        connect(m_qlButtonList[8],&QPushButton::clicked,this,MainWindow::OnQuit);
        connect(m_qlButtonList[7],&QPushButton::clicked,this,MainWindow::OnLoad);
        connect(m_qlButtonList[6],&QPushButton::clicked,this,MainWindow::OnSave);
        connect(m_qlButtonList[4],&QPushButton::clicked,this,MainWindow::OnFilter);
        connect(m_qlButtonList[3],&QPushButton::clicked,this,MainWindow::OnSort);
        connect(m_qlButtonList[5],&QPushButton::clicked,this,MainWindow::OnGraphic);
}

void MainWindow::createButtons()
{
    m_qlButtonList.push_back(new QPushButton("Добавить",this));
    m_qlButtonList.push_back(new QPushButton("Удалить",this));
    m_qlButtonList.push_back(new QPushButton("Редактировать",this));
    m_qlButtonList.push_back(new QPushButton("Отсортировать",this));
    m_qlButtonList.push_back(new QPushButton("Найти",this));
    m_qlButtonList.push_back(new QPushButton("График",this));
    m_qlButtonList.push_back(new QPushButton("Сохранить как",this));
    m_qlButtonList.push_back(new QPushButton("Загрузить из файла",this));
    m_qlButtonList.push_back(new QPushButton("Выход",this));



}

void MainWindow::setupTable()
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
            item->setFlags(item->flags() &~ Qt::ItemIsEditable);
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
    if (m_pList->getSize()!=sizeBefore)
    {
        m_pTable->insertRow(m_pList->getSize()-1);
        for(int j = 0; j < static_cast<int>(TITLES::TITLE_SIZE); ++j)
        {
            int id = m_pList->getSize()-1;
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setData(Qt::EditRole,(*m_pList)[id][j]);

            m_pTable->setItem(id, j, item);
            item->setFlags(item->flags() &~ Qt::ItemIsEditable);
        }
    };


}
void MainWindow::OnDelete()
{
    bool accepted;
    DoubtMenu* menu = new DoubtMenu(&accepted);
    menu->exec();
    if (accepted)
    {
        if (m_pList->getSize()>0)
        {

            int curIndex = m_pTable->currentRow();

            int article = (m_pTable->item(curIndex,0)->text()).toInt();
            Item *deleted = m_pList->findByArticle(article);
            m_pList->del(*deleted);
            m_pTable->removeRow(curIndex);
        }
        else
        {
            QMessageBox::warning(this,"Ошибка","Удаление невозможно: пустой список",QMessageBox::Cancel);
        }
    };
}

void MainWindow::OnChange()
{
    QList<QTableWidgetItem*> selected = m_pTable->selectedItems();

    if (selected.empty())
    {
        QMessageBox::warning(this,"Ошибка","Редактирование невозможно: не выделен элемент",QMessageBox::Cancel);
    }
    if (m_pList->getSize()>0)
    {
        int curIndex = m_pTable->currentRow();
        int article = (m_pTable->item(curIndex,0)->text()).toInt();
        Item *changed = m_pList->findByArticle(article);
        bool accepted = false;
        MyChangeMenu* menu = new MyChangeMenu(m_pList,changed,&accepted);
        menu->exec();
        if (accepted)
        {


            for(int j = 0; j < static_cast<int>(TITLES::TITLE_SIZE); ++j)
            {

                QTableWidgetItem* item = m_pTable->item(curIndex,j);
                item->setData(Qt::EditRole,(*m_pList)[curIndex][j]);
            }
        }
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Редактирование невозможно: пустой список",QMessageBox::Cancel);
    }
}

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
    if (choice<static_cast<int>(TITLES::TITLE_SIZE))
    {
        m_pTable->sortItems(choice);
    };
}

void MainWindow::OnFilter()
{
    int choice{-1};
    QString text;
    FilterMenu* menu = new FilterMenu(&choice,&text);
    menu->exec();

    if (choice!=-1)
    {
        List* newList = new List;
        for (int i{},total = m_pList->getSize();i<total;++i)
        {
            if (m_pTable->item(i,choice)->text()==text)
            {
                newList->add((*m_pList)[i]);
            }
        }

        FilteredTable* table = new FilteredTable(newList);
        table->exec();
        delete newList;delete table;
    };


    delete menu;

}

void MainWindow::OnGraphic()
{
    Diagram *diagram = new Diagram(m_pList);
    diagram->exec();
    delete diagram;
}

