#include "diagram.h"


Diagram::Diagram(List *list, QDialog *parent):
    QDialog(parent),
    m_pMainLayout(new QVBoxLayout(this)),
    m_pList(list),
    m_pChart(new QChart()),
    m_pSeries(new QPieSeries(this)),
    m_pChartView(new QChartView(m_pChart))
//    m_pBars(new std::vector<QBarSet*>)
{
    initGUI();
    createConnections();
}

//Diagram::~Diagram()
//{
//    delete m_pCloseBtn;
//    delete m_pMainLayout;
//    for (int i{},total = m_pBars->size();i<total;++i)
//    {
//        delete (*m_pBars)[i];
//    }
//    delete m_pBars;
//    delete m_pSeries;
//    delete m_pChart;
//    delete m_pYAxis;
//    delete m_pChartView;
//}

void Diagram::OnClose()
{
    close();
}

void Diagram::initGUI()
{
    setWindowTitle("Диаграмма");
    setMinimumSize(500,500);
    setupDiagram();
    createButtons();
    setLayout(m_pMainLayout);
}



void Diagram::createButtons()
{
    m_pCloseBtn = new QPushButton("Ок.",this);
    m_pMainLayout->addWidget(m_pCloseBtn);
}

void Diagram::createConnections()
{
    connect(m_pCloseBtn,&QPushButton::clicked,this,Diagram::OnClose);
}

//void Diagram::setupDiagram()
//{
//    for (size_t i{},total = m_pList->getSize(); i<total; ++i)
//    {
//        auto set = new QBarSet((*m_pList)[i].getName());
//        *set << (*m_pList)[i].getCost() ;
//        m_pBars->push_back(set);
//        m_pSeries->append(set);
//    }
//    m_pChart->addSeries(m_pSeries);
//    m_pChart->setTitle("Диаграмма");
//    m_pChart->setAnimationOptions(QChart::SeriesAnimations);

//    m_pChart->addAxis(m_pYAxis, Qt::AlignLeft);
//    m_pSeries->attachAxis(m_pYAxis);

//    m_pChart->legend()->setVisible(true);
//    m_pChart->legend()->setAlignment(Qt::AlignBottom);


//    m_pChartView->setRenderHint(QPainter::Antialiasing);

//    m_pMainLayout->addWidget(m_pChartView);
//}

void Diagram::setupDiagram()
{

    m_pList->sortByDefinition();


    auto prev = (*m_pList)[0].getDefinition();

    int totalIncom{};

    for (size_t i{},total = m_pList->getSize(); i<total; ++i)
    {
       if(prev == (*m_pList)[i].getDefinition() and i!=total-1){
           totalIncom += ((*m_pList)[i].getCost()-(*m_pList)[i].getPrice())*(*m_pList)[i].getRemain();
       }
       else{
           m_pSeries->append(prev,totalIncom);
           totalIncom = ((*m_pList)[i].getCost()-(*m_pList)[i].getPrice())*(*m_pList)[i].getRemain();
           prev = (*m_pList)[i].getDefinition();
       }
    }


    m_pChart->setTitle("моя диаграмма");
    m_pChart->legend()->setVisible(true);

    m_pChart->addSeries(m_pSeries);

    m_pChart->setAnimationOptions(QChart::SeriesAnimations);




    m_pChartView->setRenderHint(QPainter::Antialiasing);

    m_pMainLayout->addWidget(m_pChartView);
}
