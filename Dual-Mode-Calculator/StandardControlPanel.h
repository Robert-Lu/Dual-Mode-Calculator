#pragma once

#include <QWidget>
#include "ui_StandardControlPanel.h"

class StandardControlPanel : public QWidget
{
    Q_OBJECT

public:
    StandardControlPanel(QWidget *parent = Q_NULLPTR);
    ~StandardControlPanel();
    void init();

    enum StdAction
    {
        Std_0, Std_1, Std_2, Std_3, Std_4, Std_5, Std_6, Std_7, Std_8, Std_9, 
        Std_Percent, Std_Sqrt, Std_Sqr, Std_Rep, Std_ClearAll, Std_Clear, 
        Std_Backspace, Std_Plus, Std_Minus, Std_Mul, Std_Div, Std_Sign, Std_Dot, Std_Enter,
        Std_Null
    };

signals:
    void UpdateNumberDisplay(QString);

private:
    Ui::StandardControlPanel ui;

    double number, last_number;
    unsigned int digit_int, digit_float;
    unsigned int last_digit_int, last_digit_float;
    bool floating_dot_enabled, last_floating_dot_enabled, show_last, to_zeroize, in_sequence, in_result;
    StdAction stocked_action;

    void ConfigButtons();
    void ConnectButtonActions();
    
    void NumberInputHandler(unsigned int);
    void FloatingPointInputHandler();
    void UniaryOperatorInputHandler(StdAction act);
    void BinaryOperatorInputHandler(StdAction act);
    void SignOperatorInputHandler();
    void EnterOperatorInputHandler();
    void ClearOperatorInputHandler();
    void ClearAllOperatorInputHandler();
    void BackSpaceOperatorInputHandler();
    void ConfirmNumber();
    void ConfirmNumber(double n);
    void Zeroize();

    bool isPrecisionLimitExceed();
    void ExtractDigitsNumber();
    static void ExtractDigitsNumber(double n, unsigned &i, unsigned &f, bool &fe);
    QString GenerateNumberDisplay();
};
