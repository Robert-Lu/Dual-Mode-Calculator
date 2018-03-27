#include "stdafx.h"
#include "ProgrammerControlPanel.h"

ProgrammerControlPanel::ProgrammerControlPanel(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    ui.toolButton_0->setProperty("number-button", true);
    ui.toolButton_1->setProperty("number-button", true);
    ui.toolButton_2->setProperty("number-button", true);
    ui.toolButton_3->setProperty("number-button", true);
    ui.toolButton_4->setProperty("number-button", true);
    ui.toolButton_5->setProperty("number-button", true);
    ui.toolButton_6->setProperty("number-button", true);
    ui.toolButton_7->setProperty("number-button", true);
    ui.toolButton_8->setProperty("number-button", true);
    ui.toolButton_9->setProperty("number-button", true);
    ui.toolButton_A->setProperty("number-button", true);
    ui.toolButton_B->setProperty("number-button", true);
    ui.toolButton_C->setProperty("number-button", true);
    ui.toolButton_D->setProperty("number-button", true);
    ui.toolButton_E->setProperty("number-button", true);
    ui.toolButton_F->setProperty("number-button", true);
}

ProgrammerControlPanel::~ProgrammerControlPanel()
{
}
