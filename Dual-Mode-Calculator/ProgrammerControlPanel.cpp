#include "stdafx.h"
#include "ProgrammerControlPanel.h"
#include <limits>

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

void ProgrammerControlPanel::init()
{
    number = last_number = 0;
    digit_int = 0;
    last_digit_int = 0;
    show_last = false;
    to_zeroize = false;
    in_sequence = false;
    stocked_action = Pro_Null;
    BaseSwitcherHandler(10);

    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void ProgrammerControlPanel::KeyboardActionHandler(ProAction act)
{
    switch (act) {
    case Pro_0: ui.toolButton_0->animateClick(); break;
    case Pro_1: ui.toolButton_1->animateClick(); break;
    case Pro_2: ui.toolButton_2->animateClick(); break;
    case Pro_3: ui.toolButton_3->animateClick(); break;
    case Pro_4: ui.toolButton_4->animateClick(); break;
    case Pro_5: ui.toolButton_5->animateClick(); break;
    case Pro_6: ui.toolButton_6->animateClick(); break;
    case Pro_7: ui.toolButton_7->animateClick(); break;
    case Pro_8: ui.toolButton_8->animateClick(); break;
    case Pro_9: ui.toolButton_9->animateClick(); break;
    case Pro_ClearAll: ui.toolButton_ClearAll->animateClick(); break;
    case Pro_Clear: ui.toolButton_Clear->animateClick(); break;
    case Pro_Backspace: ui.toolButton_Backspace->animateClick(); break;
    case Pro_Plus: ui.toolButton_Plus->animateClick(); break;
    case Pro_Minus: ui.toolButton_Minus->animateClick(); break;
    case Pro_Mul: ui.toolButton_Mul->animateClick(); break;
    case Pro_Div: ui.toolButton_Div->animateClick(); break;
    case Pro_Enter: ui.toolButton_Enter->animateClick(); break;
    case Pro_Null: break;
    default:;
    }
}

void ProgrammerControlPanel::ConfigButtons()
{
    // tag Number buttons.
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



    // set icons.
    std::vector<std::pair<QToolButton *, QString>> toolButtonIconSettings =
    {
        { ui.toolButton_Plus, "plus" },
        { ui.toolButton_Minus, "minus" },
        { ui.toolButton_Mul, "mul" },
        { ui.toolButton_Div, "div" },
        { ui.toolButton_Sign, "sign" },
        { ui.toolButton_Backspace, "backspace" },
        { ui.toolButton_Enter, "enter" },
        { ui.toolButton_Dot, "dot_disabled" },
    };

    for (auto &setting : toolButtonIconSettings)
    {
        auto &button = setting.first;
        const auto &icon_name = setting.second;
        button->setIcon(QIcon(":/DualModeCalculator/" + icon_name));
        button->setIconSize({ 80, 40 });
    }

    ui.toolButton_Dot->setDisabled(true);
}

void ProgrammerControlPanel::ConnectButtonActions()
{
    connect(ui.toolButton_0, &QToolButton::clicked, this, [=]() { NumberInputHandler(0); });
    connect(ui.toolButton_1, &QToolButton::clicked, this, [=]() { NumberInputHandler(1); });
    connect(ui.toolButton_2, &QToolButton::clicked, this, [=]() { NumberInputHandler(2); });
    connect(ui.toolButton_3, &QToolButton::clicked, this, [=]() { NumberInputHandler(3); });
    connect(ui.toolButton_4, &QToolButton::clicked, this, [=]() { NumberInputHandler(4); });
    connect(ui.toolButton_5, &QToolButton::clicked, this, [=]() { NumberInputHandler(5); });
    connect(ui.toolButton_6, &QToolButton::clicked, this, [=]() { NumberInputHandler(6); });
    connect(ui.toolButton_7, &QToolButton::clicked, this, [=]() { NumberInputHandler(7); });
    connect(ui.toolButton_8, &QToolButton::clicked, this, [=]() { NumberInputHandler(8); });
    connect(ui.toolButton_9, &QToolButton::clicked, this, [=]() { NumberInputHandler(9); });
    connect(ui.toolButton_A, &QToolButton::clicked, this, [=]() { NumberInputHandler(10); });
    connect(ui.toolButton_B, &QToolButton::clicked, this, [=]() { NumberInputHandler(11); });
    connect(ui.toolButton_C, &QToolButton::clicked, this, [=]() { NumberInputHandler(12); });
    connect(ui.toolButton_D, &QToolButton::clicked, this, [=]() { NumberInputHandler(13); });
    connect(ui.toolButton_E, &QToolButton::clicked, this, [=]() { NumberInputHandler(14); });
    connect(ui.toolButton_F, &QToolButton::clicked, this, [=]() { NumberInputHandler(15); });

    connect(ui.toolButton_Sign, &QToolButton::clicked, this, [=]() { SignOperatorInputHandler(); });


    connect(ui.toolButton_Plus, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Pro_Plus); });
    connect(ui.toolButton_Minus, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Pro_Minus); });
    connect(ui.toolButton_Mul, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Pro_Mul); });
    connect(ui.toolButton_Div, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Pro_Div); });
    connect(ui.toolButton_And, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Pro_And); });
    connect(ui.toolButton_Or, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Pro_Or); });
    connect(ui.toolButton_Xor, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Pro_Xor); });
    connect(ui.toolButton_Not, &QToolButton::clicked, this, [=]() { UniaryOperatorInputHandler(Pro_Not); });

    connect(ui.toolButton_Enter, &QToolButton::clicked, this, [=]() { EnterOperatorInputHandler(); });

    connect(ui.toolButton_Backspace, &QToolButton::clicked, this, [=]() { BackSpaceOperatorInputHandler(); });
    connect(ui.toolButton_Clear, &QToolButton::clicked, this, [=]() { ClearOperatorInputHandler(); });
    connect(ui.toolButton_ClearAll, &QToolButton::clicked, this, [=]() { ClearAllOperatorInputHandler(); });

    connect(ui.buttonBin, &QToolButton::clicked, this, [=]() { BaseSwitcherHandler(2); });
    connect(ui.buttonOct, &QToolButton::clicked, this, [=]() { BaseSwitcherHandler(8); });
    connect(ui.buttonDec, &QToolButton::clicked, this, [=]() { BaseSwitcherHandler(10); });
    connect(ui.buttonHex, &QToolButton::clicked, this, [=]() { BaseSwitcherHandler(16); });
}

void ProgrammerControlPanel::NumberInputHandler(unsigned num)
{
    if (to_zeroize)
        Zeroize();

    show_last = false;
    if (in_result)
    {
        stocked_action = Pro_Null;
    }

    if (isPrecisionLimitExceed(num))
        return;

    if (!(number == 0 && num == 0))
    {
        if (number >= 0)
            number = base * number + num;
        else
            number = base * number - num;
        digit_int++;
    }

    in_result = false;

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void ProgrammerControlPanel::UniaryOperatorInputHandler(ProAction act)
{
    if (show_last)
    {
        switch (act)
        {
        case Pro_Not:
            ConfirmNumber(~ static_cast<uint32_t>(last_number));
            break;
        default:
            break;
        }
    }
    else
    {
        switch (act)
        {
        case Pro_Not:
            number = ~static_cast<uint32_t>(number);
            break;
        default:
            break;
        }
        ExtractDigitsNumber();
    }

    to_zeroize = true;
    in_result = true;

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void ProgrammerControlPanel::BinaryOperatorInputHandler(ProAction act)
{
    qDebug() << "On bin op begin:";
    qDebug() << "stock_act = " << stocked_action;
    qDebug() << "last_num = " << last_number;
    qDebug() << "curr_num = " << number;

    if (stocked_action != Pro_Null)
    {
        if (in_sequence)
        {
            switch (stocked_action)
            {
            case Pro_And:
                ConfirmNumber(last_number & number);
                break;
            case Pro_Or:
                ConfirmNumber(last_number | number);
                break;
            case Pro_Xor:
                ConfirmNumber(last_number ^ number);
                break;
            case Pro_Plus:
                ConfirmNumber(last_number + number);
                break;
            case Pro_Minus:
                ConfirmNumber(last_number - number);
                break;
            case Pro_Mul:
                ConfirmNumber(last_number * number);
                break;
            case Pro_Div:
                if (number == 0)
                {
                    emit UpdateNumberDisplay(QStringLiteral("´íÎó£º³ıÊıÎªÁã"));
                    return;
                }
                ConfirmNumber(last_number / number);
                break;
            default:
                break;
            }
        }
        else
        {
            // do nothing.
        }
    }
    else
    {
        ConfirmNumber();
    }

    switch (act)
    {
    case Pro_Plus:
    case Pro_Minus:
    case Pro_Mul:
    case Pro_Div:
    case Pro_And:
    case Pro_Or:
    case Pro_Xor:
        stocked_action = act;
        break;
    default:
        break;
    }
    show_last = true;
    to_zeroize = true;
    in_sequence = true;
    in_result = false;

    qDebug() << "On bin op end:";
    qDebug() << "stock_act = " << stocked_action;
    qDebug() << "last_num = " << last_number;
    qDebug() << "curr_num = " << number;
    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void ProgrammerControlPanel::SignOperatorInputHandler()
{
    if (show_last)
        last_number = -last_number;
    else
        number = -number;

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void ProgrammerControlPanel::EnterOperatorInputHandler()
{
    qDebug() << "On enter begin:";
    qDebug() << "stock_act = " << stocked_action;
    qDebug() << "last_num = " << last_number;

    if (stocked_action != Pro_Null)
    {
        switch (stocked_action)
        {
        case Pro_And:
            ConfirmNumber(last_number & number);
            break;
        case Pro_Or:
            ConfirmNumber(last_number | number);
            break;
        case Pro_Xor:
            ConfirmNumber(last_number ^ number);
            break;
        case Pro_Plus:
            ConfirmNumber(last_number + number);
            break;
        case Pro_Minus:
            ConfirmNumber(last_number - number);
            break;
        case Pro_Mul:
            ConfirmNumber(last_number * number);
            break;
        case Pro_Div:
            if (number == 0)
            {
                emit UpdateNumberDisplay(QStringLiteral("´íÎó£º³ıÊıÎªÁã"));
                return;
            }
            ConfirmNumber(last_number / number);
            break;
        default:
            break;
        }
        show_last = true;
        to_zeroize = true;
    }
    in_sequence = false;
    in_result = true;

    qDebug() << "On enter end:";
    qDebug() << "stock_act = " << stocked_action;
    qDebug() << "last_num = " << last_number;
    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
    emit UpdateNumberHistory(GenerateNumberDisplay());
}

void ProgrammerControlPanel::ClearOperatorInputHandler()
{
    Zeroize();
}

void ProgrammerControlPanel::ClearAllOperatorInputHandler()
{
    init();
}

void ProgrammerControlPanel::BackSpaceOperatorInputHandler()
{
    if (number > base)
    {
        number = number / base;
    }
    else
        number = 0;

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void ProgrammerControlPanel::BaseSwitcherHandler(unsigned b)
{
    base = b;

    if (b == 2)
    {
        ui.toolButton_2->setDisabled(true);
        ui.toolButton_3->setDisabled(true);
        ui.toolButton_4->setDisabled(true);
        ui.toolButton_5->setDisabled(true);
        ui.toolButton_6->setDisabled(true);
        ui.toolButton_7->setDisabled(true);
        ui.toolButton_8->setDisabled(true);
        ui.toolButton_9->setDisabled(true);
        ui.toolButton_A->setDisabled(true);
        ui.toolButton_B->setDisabled(true);
        ui.toolButton_C->setDisabled(true);
        ui.toolButton_D->setDisabled(true);
        ui.toolButton_E->setDisabled(true);
        ui.toolButton_F->setDisabled(true);
    } 
    else if (b == 8)
    {
        ui.toolButton_2->setDisabled(false);
        ui.toolButton_3->setDisabled(false);
        ui.toolButton_4->setDisabled(false);
        ui.toolButton_5->setDisabled(false);
        ui.toolButton_6->setDisabled(false);
        ui.toolButton_7->setDisabled(false);
        ui.toolButton_8->setDisabled(true);
        ui.toolButton_9->setDisabled(true);
        ui.toolButton_A->setDisabled(true);
        ui.toolButton_B->setDisabled(true);
        ui.toolButton_C->setDisabled(true);
        ui.toolButton_D->setDisabled(true);
        ui.toolButton_E->setDisabled(true);
        ui.toolButton_F->setDisabled(true);
    }
    else if (b == 10)
    {
        ui.toolButton_2->setDisabled(false);
        ui.toolButton_3->setDisabled(false);
        ui.toolButton_4->setDisabled(false);
        ui.toolButton_5->setDisabled(false);
        ui.toolButton_6->setDisabled(false);
        ui.toolButton_7->setDisabled(false);
        ui.toolButton_8->setDisabled(false);
        ui.toolButton_9->setDisabled(false);
        ui.toolButton_A->setDisabled(true);
        ui.toolButton_B->setDisabled(true);
        ui.toolButton_C->setDisabled(true);
        ui.toolButton_D->setDisabled(true);
        ui.toolButton_E->setDisabled(true);
        ui.toolButton_F->setDisabled(true);
    }
    else if (b == 16)
    {
        ui.toolButton_2->setDisabled(false);
        ui.toolButton_3->setDisabled(false);
        ui.toolButton_4->setDisabled(false);
        ui.toolButton_5->setDisabled(false);
        ui.toolButton_6->setDisabled(false);
        ui.toolButton_7->setDisabled(false);
        ui.toolButton_8->setDisabled(false);
        ui.toolButton_9->setDisabled(false);
        ui.toolButton_A->setDisabled(false);
        ui.toolButton_B->setDisabled(false);
        ui.toolButton_C->setDisabled(false);
        ui.toolButton_D->setDisabled(false);
        ui.toolButton_E->setDisabled(false);
        ui.toolButton_F->setDisabled(false);
    }

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void ProgrammerControlPanel::ConfirmNumber()
{
    last_number = number;
    last_digit_int = digit_int;
}

void ProgrammerControlPanel::ConfirmNumber(int32_t n)
{
    last_number = n;
    ExtractDigitsNumber(n, last_digit_int);
}

void ProgrammerControlPanel::Zeroize()
{
    number = 0;
    digit_int = 0;
    to_zeroize = false;
}

bool ProgrammerControlPanel::isPrecisionLimitExceed(unsigned num)
{
    if (base == 10)
    {
        auto x = std::numeric_limits<int32_t>::max();
        return (x - num) / base < number;
    }
    else
    {
        auto x = std::numeric_limits<uint32_t>::max();
        return (x - num) / base < number;
    }
    return false;
}

void ProgrammerControlPanel::ExtractDigitsNumber()
{
}

void ProgrammerControlPanel::ExtractDigitsNumber(double n, unsigned& i)
{
}

QString ProgrammerControlPanel::NumberStringWithBase(int32_t n, unsigned base)
{
    if (base == 10)
    {
        return QString("%1").arg(n);
    }
    else if (base == 2)
    {
        uint32_t un = static_cast<uint32_t>(n);
        auto s = QString("%1").arg(un, 32, 2, QLatin1Char('0'));
        while(s.startsWith("0000") && s.size() > 4)
            s.remove(0, 4);
        return s;
    }
    else
    {
        uint32_t un = static_cast<uint32_t>(n);
        return QString("%1").arg(un, 0, base).toUpper();
    }
}

QString ProgrammerControlPanel::GenerateNumberDisplay()
{
    if (show_last)
    {
        ui.labelBin->setText(NumberStringWithBase(last_number, 2));
        ui.labelOct->setText(NumberStringWithBase(last_number, 8));
        ui.labelDec->setText(NumberStringWithBase(last_number, 10));
        ui.labelHex->setText(NumberStringWithBase(last_number, 16));
        return NumberStringWithBase(last_number, base);
    }
    else
    {
        ui.labelBin->setText(NumberStringWithBase(number, 2));
        ui.labelOct->setText(NumberStringWithBase(number, 8));
        ui.labelDec->setText(NumberStringWithBase(number, 10));
        ui.labelHex->setText(NumberStringWithBase(number, 16));
        return NumberStringWithBase(number, base);
    }
}
