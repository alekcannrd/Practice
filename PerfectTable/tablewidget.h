#pragma once
#include <QTableWidget>

class TableWidget : public QTableWidget
{
    Q_OBJECT

public:
    explicit TableWidget(QWidget* pParent = nullptr);
};


