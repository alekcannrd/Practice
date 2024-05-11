#pragma once
#include <QDialog>
#include "List.h"
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
class DeleteMenu : public QDialog
{
    Q_OBJECT
public:
    DeleteMenu(List* list,QDialog *parent = nullptr);
private slots:
    OnAccept()
    {

    }
    OnRefuse(){}
private:
    List* m_pList;
    QLineEdit* m_pIdLine;
    QPushButton* m_pAcceptBtn;
    QPushButton* m_pRefuseBtn;
    void initGUI();
    void createLines();
    void createButtons();
    void createConnections();
};


