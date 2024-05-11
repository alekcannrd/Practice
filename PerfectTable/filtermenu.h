#pragma once
#include <QComboBox>
#include <QPushButton>
#include <QDialog>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QString>


class FilterMenu: public QDialog
{
    Q_OBJECT
public:
    FilterMenu(int *choice,QString* text,QDialog *parent = nullptr);
private slots:
    void OnAccept();
    void OnRefuse();
private:
    void initGUI();
    void createButtons();
    void createLines();
    void createConnections();
    QString* m_pText;
    QVBoxLayout *m_pMainLayout;
    QPushButton* m_pAcceptBtn;
    QPushButton* m_pRefuseBtn;
    QLineEdit* m_pLineEdit;
    QComboBox* m_pComboBox;
    int *m_piChoice;
};
