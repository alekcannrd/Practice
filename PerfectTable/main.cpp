#include "mainwindow.h"
#include<QtCharts>
#include <QApplication>






void printDiagram(std::vector<Item> items){
QBarSeries *series = new QBarSeries;

std::vector<QBarSet*> bars{};

for(size_t i{}; i<items.size(); i++){
auto set = new QBarSet(items[i].getName());
*set << items[i].getCost() ;
bars.push_back(set);
series->append(set);
}

auto chart = new QChart;
chart->addSeries(series);
chart->setTitle("Best Bar Chart");
chart->setAnimationOptions(QChart::SeriesAnimations);

//    QStringList categories {"Jan", "Feb", "Mar", "Apr", "May", "Jun"};
//    auto axisX = new QBarCategoryAxis;
//    axisX->append(categories);
//    chart->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

auto axisY = new QValueAxis;
//    axisY->setRange(0,15);
chart->addAxis(axisY, Qt::AlignLeft);
series->attachAxis(axisY);

chart->legend()->setVisible(true);
chart->legend()->setAlignment(Qt::AlignBottom);

QChartView * v = new QChartView(chart);
v->setRenderHint(QPainter::Antialiasing);

QMainWindow window;
window.setCentralWidget(v);
window.resize(420, 300);
window.show();

for(size_t i{}; i<bars.size(); i++){
    delete bars[i];
}
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    std::vector<Item> items = {Item(12,"Александрит",32000,2300,"tre",4,QDate(2000,12,12),2),Item(44,"Еда",22,33,"QQQ",1,QDate(2000,10,12),1)};
    List q{items};

//    printDiagram(items);

    std::vector<QBarSet*> bars{};
QBarSeries *series = new QBarSeries;
    for(size_t i{}; i<items.size(); i++){
    auto set = new QBarSet(items[i].getName());
    *set << items[i].getCost() ;
    bars.push_back(set);
    series->append(set);
    }

    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Best Bar Chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //    QStringList categories {"Jan", "Feb", "Mar", "Apr", "May", "Jun"};
    //    auto axisX = new QBarCategoryAxis;
    //    axisX->append(categories);
    //    chart->addAxis(axisX, Qt::AlignBottom);
    //    series->attachAxis(axisX);

    auto axisY = new QValueAxis;
//        axisY->setRange(0,50);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView * v = new QChartView(chart);
    v->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(v);
    window.resize(420, 300);
    window.show();

    for(size_t i{}; i<bars.size(); i++){
        delete bars[i];
    }


   MainWindow w(&q);
   w.show();
    return a.exec();
}
