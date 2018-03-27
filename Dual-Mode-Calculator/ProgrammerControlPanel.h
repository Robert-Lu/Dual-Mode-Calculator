#pragma once

#include <QWidget>
#include "ui_ProgrammerControlPanel.h"

class ProgrammerControlPanel : public QWidget
{
    Q_OBJECT

public:
    ProgrammerControlPanel(QWidget *parent = Q_NULLPTR);
    ~ProgrammerControlPanel();

private:
    Ui::ProgrammerControlPanel ui;
};
