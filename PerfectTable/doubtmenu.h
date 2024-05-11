#pragma once
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
class DoubtMenu : public QDialog
{
    Q_OBJECT
public:
    DoubtMenu(bool *accepted,QDialog *parent = nullptr);

private slots:
    void OnAccept();
    void OnRefuse();

private:
    bool* m_pbAccepted;
    QPushButton* m_pAcceptBtn;
    QPushButton* m_pRefuseBtn;
    QHBoxLayout* m_pMainLayout;
    void initGUI();
    void createButtons();
    void createConnections();
};

