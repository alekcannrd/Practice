#pragma once
#include <QDialog>
#include <QPushButton>
#include <QHBoxLayout>
#include <QList>
class SortMenu: public QDialog
{
    Q_OBJECT
public:
    SortMenu(int *pChoice, QDialog *parent = nullptr);
private slots:
    void OnArticle();
    void OnName();
    void OnCost();
    void OnPrice();
    void OnDefinition();
    void OnRemain();
    void OnTime();
    void OnNumOfParty();
    void OnRefuse();

private:
    int *m_piChoice;
    QHBoxLayout *m_pMainLayout;
    void initGUI();
    QList<QPushButton*> m_qlBtnList;
    void createButtons();
    void createConnections();
};


