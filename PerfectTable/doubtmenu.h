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
    void OnAccept();//слот "принять"
    void OnRefuse();//слот "отмена"

private:
    bool* m_pbAccepted;
    QPushButton* m_pAcceptBtn;//кнопка "принять"
    QPushButton* m_pRefuseBtn;//кнопка "отмена"
    QHBoxLayout* m_pMainLayout;//макет окна
    void initGUI();//инициализация интерфейса
    void createButtons();//создание кнопок
    void createConnections();//создание связей между кнопками и слотами
};

