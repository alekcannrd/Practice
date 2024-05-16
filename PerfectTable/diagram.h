#pragma once
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QtCharts>
#include "List.h"

class Diagram: public QDialog
{
    Q_OBJECT
public:
    Diagram(List list,QDialog *parent = nullptr);
//    ~Diagram();

private slots:
    void OnClose();
private:
   QPushButton* m_pCloseBtn;
    QVBoxLayout* m_pMainLayout;
    List m_List;
    QChart* m_pChart;
    QPieSeries* m_pSeries;
    void initGUI();
    void createButtons();
    void createConnections();
    QChartView *m_pChartView;
    void setupDiagram();
};

