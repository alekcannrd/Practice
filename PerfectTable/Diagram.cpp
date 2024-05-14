#include "diagram.h"


Diagram::Diagram(List *list, QDialog *parent):
    QDialog(parent),
    m_pList(list),
    m_pMainLayout(new QVBoxLayout(this)),
    m_pSeries(new QBarSeries(this)),
    m_pChart(new QChart),
    m_pYAxis(new QValueAxis),
    m_pChartView(new QChartView(m_pChart))
{
    initGUI();
    createConnections();
}

Diagram::~Diagram()
{
    delete m_pCloseBtn;
    delete m_pMainLayout;
    delete m_pList;
    for (int i{},total = m_pBars->size();i<total;++i)
    {
        delete (*m_pBars)[i];
    }
    delete m_pBars;
    delete m_pSeries;
    delete m_pChart;
    delete m_pYAxis;
    delete m_pChartView;
}

void Diagram::initGUI()
{
    setWindowTitle("Диаграмма");
    setMinimumSize(500,500);
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

void Diagram::setupDiagram()
{
    for (size_t i{},total = m_pList->getSize(); i<total; ++i)
    {
        auto set = new QBarSet((*m_pList)[i].getName());
        *set << (*m_pList)[i].getCost() ;
        m_pBars->push_back(set);
        m_pSeries->append(set);
    }
    m_pChart->addSeries(m_pSeries);
    m_pChart->setTitle("Диаграмма");
    m_pChart->setAnimationOptions(QChart::SeriesAnimations);

    m_pChart->addAxis(m_pYAxis, Qt::AlignLeft);
    m_pSeries->attachAxis(m_pYAxis);

    m_pChart->legend()->setVisible(true);
    m_pChart->legend()->setAlignment(Qt::AlignBottom);


    m_pChartView->setRenderHint(QPainter::Antialiasing);

    m_pMainLayout->addWidget(m_pChartView);
}