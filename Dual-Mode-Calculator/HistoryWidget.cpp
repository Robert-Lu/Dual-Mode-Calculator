#include "stdafx.h"
#include "HistoryWidget.h"

HistoryWidget::HistoryWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

HistoryWidget::~HistoryWidget()
{
}

void HistoryWidget::init(const std::vector<QString> &his)
{
    QLabel *label[4] = { ui.labelHis0, ui.labelHis1, ui.labelHis2, ui.labelHis3, };

    int index = 0;
    for (int i = his.size() - 1; i >= 0 && index < 4; --i)
    {
        label[index++]->setText(his[i]);
    }
    for (; index < 4; ++index)
    {
        label[index]->setText("");
    }
}
