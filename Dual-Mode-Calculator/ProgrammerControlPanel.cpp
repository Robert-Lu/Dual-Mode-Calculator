#include "stdafx.h"
#include "ProgrammerControlPanel.h"

ProgrammerControlPanel::ProgrammerControlPanel(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    ConfigButtons();
    ConnectButtonActions();
}

ProgrammerControlPanel::~ProgrammerControlPanel()
{
}

void ProgrammerControlPanel::KeyboardActionHandler(ProAction act)
{
}

void ProgrammerControlPanel::ConfigButtons()
{
}

void ProgrammerControlPanel::ConnectButtonActions()
{
}

void ProgrammerControlPanel::NumberInputHandler(unsigned)
{
}

void ProgrammerControlPanel::UniaryOperatorInputHandler(ProAction act)
{
}

void ProgrammerControlPanel::BinaryOperatorInputHandler(ProAction act)
{
}

void ProgrammerControlPanel::SignOperatorInputHandler()
{
}

void ProgrammerControlPanel::EnterOperatorInputHandler()
{
}

void ProgrammerControlPanel::ClearOperatorInputHandler()
{
}

void ProgrammerControlPanel::ClearAllOperatorInputHandler()
{
}

void ProgrammerControlPanel::BackSpaceOperatorInputHandler()
{
}

void ProgrammerControlPanel::ConfirmNumber()
{
}

void ProgrammerControlPanel::ConfirmNumber(double n)
{
}

void ProgrammerControlPanel::Zeroize()
{
}

bool ProgrammerControlPanel::isPrecisionLimitExceed()
{
}

QString ProgrammerControlPanel::GenerateNumberDisplay()
{
}
