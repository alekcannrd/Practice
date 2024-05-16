#pragma once
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QComboBox>
#include <QList>
#include <QLabel>
#include <QHBoxLayout>
class SortMenu: public QDialog
{
    Q_OBJECT
public:
    SortMenu(int *pChoice, QDialog *parent = nullptr);
private slots:
//    void OnArticle();
//    void OnName();
//    void OnCost();
//    void OnPrice();
//    void OnDefinition();
//    void OnRemain();
//    void OnTime();
//    void OnNumOfParty();
    void OnAccept()
    {

        *m_piChoice = m_pVectorBox->currentIndex()*8+m_pFieldBox->currentIndex();
        close();
    }
    void OnRefuse();

private:
    int *m_piChoice;
    QComboBox* m_pVectorBox;
    QComboBox* m_pFieldBox;
    QVBoxLayout *m_pMainLayout;
    void initGUI();
    QList<QPushButton*> m_qlBtnList;
    void createButtons();
    void createConnections();
};


