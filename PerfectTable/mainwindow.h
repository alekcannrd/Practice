#pragma once
#include <QPushButton>
#include <QTextStream>
#include <QCoreApplication>
#include "List.h"
#include "addmenu.h"
#include "tablewidget.h"
#include "doubtmenu.h"
#include "mychangemenu.h"
#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include "sortmenu.h"
#include "filteredtable.h"
#include "filtermenu.h"
#include "diagram.h"
class MainWindow: public QWidget
{
    Q_OBJECT
public:
    MainWindow(List *q,QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void OnQuit();//слот "закрыть"
    void OnAdd();//слот "добавить"
    void OnDelete();//слот "удалить"
    void OnChange();//слот "редактировать"
    void OnLoad();//слот "загрузить"
    void OnSave();//слот "сохранить"
    void OnSort();//слот "сортировать"
    void OnFilter();//слот "фильтровать"
    void OnGraphic();//слот "график"
    void OnItemChanged(int row,int column)
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

private:
    unsigned const m_cuColumnWidth{150};//ширина колонны
    unsigned const m_cuWindowWidth{m_cuColumnWidth*static_cast<int>(TITLES::TITLE_SIZE)+50};//ширина окна
    List* m_pList;
    QList<QPushButton*> m_qlButtonList;//список кнопок
    QVBoxLayout *m_pMainLayout{new QVBoxLayout(this)};//макет окна
    TableWidget* m_pTable;//таблица
    void initGUI();//инициализация интерфейса
    void createConnections();//создание связей между слотами и кнопками
    void setupWindow();//создать окно
    void createButtons();//создать кнопки

    void setupTable();//установка таблицы
};

