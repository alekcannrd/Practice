#pragma once
#include <QPushButton>
#include <QTextStream>
#include <QCoreApplication>
#include "List.h"
#include "addmenu.h"
#include "tablewidget.h"
#include "doubtmenu.h"
#include "changemenu.h"
#include <QMenuBar>
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "sortmenu.h"
#include "filteredtable.h"
#include "filtermenu.h"
class MainWindow: public QWidget
{
    Q_OBJECT
public:
    MainWindow(List *q,QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void OnQuit();
    void OnAdd();
    void OnDelete();
    void OnChange();
    void OnLoad();
    void OnSave();
    void OnSort();
    void OnFilter();
//    void OnGraphic();

private:
    unsigned const m_cuColumnWidth{150};
    unsigned const m_cuWindowWidth{m_cuColumnWidth*static_cast<int>(TITLES::TITLE_SIZE)+50};
    List* m_pList;
    QList<QPushButton*> m_qlButtonList;
    QVBoxLayout *m_pMainLayout{new QVBoxLayout(this)};
    TableWidget* m_pTable;
    void initGUI();
    void createConnections();
    void setupWindow();
    void createButtons();
    void defineSlots();
    void setupTable();
};

