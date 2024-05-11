#pragma once
#include "List.h"
#include <QWidget>
#include "Constants.h"
#include "Item.h"
#include "tablewidget.h"

class Table : public QWidget
{
    Q_OBJECT

public:
    Table(List* list, QWidget *parent = nullptr);
    ~Table();

private:
    TableWidget *m_pTable;
    void initGUI(List *list);
    void createConnections();
    void setupTable(List* list);
    //void addRow(Item* item);
};
