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
    Diagram(List *list,QDialog *parent = nullptr);
    ~Diagram();

private slots:
    void OnClose();
private:
    QPushButton* m_pCloseBtn;
    QVBoxLayout* m_pMainLayout;
    List* m_pList;
    std::vector<QBarSet*>* m_pBars;
    QBarSeries *m_pSeries;
    QChart* m_pChart;
    QValueAxis* m_pYAxis;
    void initGUI();
    void createButtons();
    void createConnections();
    QChartView *m_pChartView;
    void setupDiagram();
};

//std::vector<Item> items = {Item(12,"Александрит",32000,2300,"tre",4,QDate(2000,12,12),2),Item(44,"Еда",22,33,"QQQ",1,QDate(2000,10,12),1)};
//List q{items};

//    printDiagram(items);

//std::vector<QBarSet*> bars{};
//QBarSeries *series = new QBarSeries;
//for(size_t i{}; i<items.size(); i++){
//auto set = new QBarSet(items[i].getName());
//*set << items[i].getCost() ;
//bars.push_back(set);
//series->append(set);
//}

//auto chart = new QChart;
//chart->addSeries(series);
//chart->setTitle("Best Bar Chart");
//chart->setAnimationOptions(QChart::SeriesAnimations);

//    QStringList categories {"Jan", "Feb", "Mar", "Apr", "May", "Jun"};
//    auto axisX = new QBarCategoryAxis;
//    axisX->append(categories);
//    chart->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

//auto axisY = new QValueAxis;
////        axisY->setRange(0,50);
//chart->addAxis(axisY, Qt::AlignLeft);
//series->attachAxis(axisY);

//chart->legend()->setVisible(true);
//chart->legend()->setAlignment(Qt::AlignBottom);

//QChartView * v = new QChartView(chart);
//v->setRenderHint(QPainter::Antialiasing);

//QMainWindow window;
//window.setCentralWidget(v);
//window.resize(420, 300);
//window.show();

//for(size_t i{}; i<bars.size(); i++){
//    delete bars[i];
//}

