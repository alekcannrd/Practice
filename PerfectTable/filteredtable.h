#pragma once
#include <QDialog>
#include "List.h"
#include <QPushButton>
#include <QVBoxLayout>
#include "tablewidget.h"
class FilteredTable: public QDialog
{
    Q_OBJECT
public:
    FilteredTable(List* list,QDialog *parent = nullptr);
private slots:
    void OnClose();//слот "закрыть"
private:
    List* m_pList;
    QPushButton* m_pCloseBtn;//кнопка "закрыть"
    QVBoxLayout* m_pMainLayout;//макет окна
    TableWidget* m_pTable;//таблица
    void createButtons();//создание кнопок
    void createConnections();//создание связей между кнопками и слотами

    unsigned const m_cuColumnWidth{150};//ширина колонны
    unsigned const m_cuWindowWidth{m_cuColumnWidth*static_cast<int>(TITLES::TITLE_SIZE)+50};//ширина окна
    void initGUI();//инициализация интерфейса
    void setupTable();//создание таблицы
};

