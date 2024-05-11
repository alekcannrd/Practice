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
    void OnClose();
private:
    List* m_pList;
    QPushButton* m_pCloseBtn;
    QVBoxLayout* m_pMainLayout;
    TableWidget* m_pTable;
    void createButtons();
    void createConnections();

    unsigned const m_cuColumnWidth{150};
    unsigned const m_cuWindowWidth{m_cuColumnWidth*static_cast<int>(TITLES::TITLE_SIZE)+50};
    void initGUI();
    void setupTable();
};

