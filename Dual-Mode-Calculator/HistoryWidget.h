#pragma once

#include <QWidget>
#include "ui_HistoryWidget.h"

class HistoryWidget : public QWidget
{
    Q_OBJECT

public:
    HistoryWidget(QWidget *parent = Q_NULLPTR);
    ~HistoryWidget();
    void init(const std::vector<QString> &);

private:
    Ui::HistoryWidget ui;
};
