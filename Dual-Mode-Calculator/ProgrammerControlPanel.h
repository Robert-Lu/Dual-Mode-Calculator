#pragma once

#include <QWidget>
#include "ui_ProgrammerControlPanel.h"

class ProgrammerControlPanel : public QWidget
{
    Q_OBJECT

public:
    ProgrammerControlPanel(QWidget *parent = Q_NULLPTR);
    ~ProgrammerControlPanel();
    void init();

    enum ProAction
    {
        Pro_0, Pro_1, Pro_2, Pro_3, Pro_4, Pro_5, Pro_6, Pro_7, Pro_8, Pro_9,
        Pro_Percent, Pro_Sqrt, Pro_Sqr, Pro_Rep, Pro_ClearAll, Pro_Clear,
        Pro_Backspace, Pro_Plus, Pro_Minus, Pro_Mul, Pro_Div, Pro_Sign, Pro_Dot, Pro_Enter,
        Pro_Null
    };
    void KeyboardActionHandler(ProAction act);

signals:
    void UpdateNumberDisplay(QString);

private:
    Ui::ProgrammerControlPanel ui;

    double number, last_number;
    unsigned int digit_int;
    unsigned int last_digit_int;
    bool show_last, to_zeroize, in_sequence, in_result;
    ProAction stocked_action;

    void ConfigButtons();
    void ConnectButtonActions();

    void NumberInputHandler(unsigned int);
    void UniaryOperatorInputHandler(ProAction act);
    void BinaryOperatorInputHandler(ProAction act);
    void SignOperatorInputHandler();
    void EnterOperatorInputHandler();
    void ClearOperatorInputHandler();
    void ClearAllOperatorInputHandler();
    void BackSpaceOperatorInputHandler();
    void ConfirmNumber();
    void ConfirmNumber(double n);
    void Zeroize();

    bool isPrecisionLimitExceed();
    QString GenerateNumberDisplay();
};
