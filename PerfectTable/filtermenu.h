#pragma once
#include <QComboBox>
#include <QPushButton>
#include <QDialog>
#include <QList>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QString>
#include <QLabel>


class FilterMenu: public QDialog
{
    Q_OBJECT
public:
    FilterMenu(int *choice,QString* text,QDialog *parent = nullptr);
private slots:
    void OnAccept();//слот "принять"
    void OnRefuse();//слот "отмена"
private:
    void initGUI();//инициализация интерфейса
    void createButtons();//создание кнопок
    void createLines();//создание полей ввода
    void createConnections();//создание связей между кнопками и слотами
    QString* m_pText;
    QVBoxLayout *m_pMainLayout;//макет окна
    QPushButton* m_pAcceptBtn;//кнопка "принять"
    QPushButton* m_pRefuseBtn;//кнопка "отмена"
    QLineEdit* m_pLineEdit;//окно ввода
    QComboBox* m_pComboBox;//выпадающий список
    int *m_piChoice;//выбранное поле для поиска
};
