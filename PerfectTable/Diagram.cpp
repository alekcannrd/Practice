#include "diagram.h"


Diagram::Diagram(List list, QDialog *parent):
    QDialog(parent),
    m_pMainLayout(new QVBoxLayout(this)),
    m_List(list),
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

//    delete m_pSeries;
//    delete m_pChart;
//    delete m_pChartView;
//}

void Diagram::OnClose()
{
    close();
}

void Diagram::initGUI()
{
    setWindowTitle("Диаграмма");
    setMinimumSize(750,750);
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
//    for (size_t i{},total = m_List->getSize(); i<total; ++i)
//    {
//        auto set = new QBarSet((*m_List)[i].getName());
//        *set << (*m_List)[i].getCost() ;
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

    m_List.sortByDefinition();


    auto prev = m_List[0].getDefinition();
    double TOTALIncom{};
    double totalIncom{};

    for (size_t i{},total = m_List.getSize(); i<total; ++i)
    {
        //
        double incom{((m_List)[i].getPrice()-(m_List)[i].getCost())*(m_List)[i].getRemain()};
        TOTALIncom+=incom;
        if(prev == (m_List)[i].getDefinition() and i!=total-1){
            totalIncom += incom;
        }
        if(prev == (m_List)[i].getDefinition() and i==total-1){
            totalIncom+=incom;
            m_pSeries->append(prev + " " + QString::number(qRound(totalIncom)),qRound(totalIncom));
        }
        if (prev != (m_List)[i].getDefinition() and i==total-1){
            m_pSeries->append(prev + " " + QString::number(qRound(totalIncom)),qRound(totalIncom));
            totalIncom = incom;
            m_pSeries->append((m_List)[i].getDefinition() + " " + QString::number(qRound(totalIncom)),qRound(totalIncom));
        }
        if (prev != (m_List)[i].getDefinition() and i!=total-1){
            m_pSeries->append(prev + " " + QString::number(qRound(totalIncom)),qRound(totalIncom));
            totalIncom = incom;
            prev = (m_List)[i].getDefinition();
        }

    }



    TOTALIncom = qRound(TOTALIncom);
    m_pSeries->setLabelsVisible(true);
//    m_pSeries->set

    m_pChart->setTitle("Диаграмма прибавочной стоимости по расположению на складе");

    m_pChart->legend()->setVisible(false);
    m_pChart->addSeries(m_pSeries);

    m_pChart->setAnimationOptions(QChart::SeriesAnimations);

    m_pChartView->setRenderHint(QPainter::Antialiasing);

    auto help = new QLabel{"Диаграмма отражает прибыль магазина, извлеченную из продажи всех товаров на конкретной полке.\nОбщая прибыль составит: " + QString::number(TOTALIncom)};

    m_pMainLayout->addWidget(m_pChartView);
    m_pMainLayout->addWidget(help);
}

