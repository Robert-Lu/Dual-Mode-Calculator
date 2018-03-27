#include "stdafx.h"
#include "StandardControlPanel.h"
#include <vector>
#include <QString>

#define DECIMAL_LIMIT 13

StandardControlPanel::StandardControlPanel(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    ConfigButtons();
    ConnectButtonActions();
}

StandardControlPanel::~StandardControlPanel()
{
}

void StandardControlPanel::init()
{
    number = last_number = 0.0;
    digit_int = digit_float = 0;
    floating_dot_enabled = false;
    last_digit_int = last_digit_float = 0;
    last_floating_dot_enabled = false;
    show_last = false;
    to_zeroize = false;
    in_sequence = false;
    stocked_action = Std_Null;

    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void StandardControlPanel::ConfigButtons()
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

    // set icons.
    std::vector<std::pair<QToolButton *, QString>> toolButtonIconSettings =
    {
        { ui.toolButton_Percent, "percent" },
        { ui.toolButton_Sqrt, "sqrt" },
        { ui.toolButton_Sqr, "sqr" },
        { ui.toolButton_Rep, "rep" },
        { ui.toolButton_Plus, "plus" },
        { ui.toolButton_Minus, "minus" },
        { ui.toolButton_Mul, "mul" },
        { ui.toolButton_Div, "div" },
        { ui.toolButton_Sign, "sign" },
    };

    for (auto &setting : toolButtonIconSettings)
    {
        auto &button = setting.first;
        const auto &icon_name = setting.second;
        button->setIcon(QIcon(":/DualModeCalculator/" + icon_name));
        button->setIconSize({ 80, 40 });
    }
}

void StandardControlPanel::ConnectButtonActions()
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

    connect(ui.toolButton_Dot, &QToolButton::clicked, this, [=]() { FloatingPointInputHandler(); });
    connect(ui.toolButton_Sign, &QToolButton::clicked, this, [=]() { SignOperatorInputHandler(); });

    connect(ui.toolButton_Percent, &QToolButton::clicked, this, [=]() { UniaryOperatorInputHandler(Std_Percent); });
    connect(ui.toolButton_Sqrt, &QToolButton::clicked, this, [=]() { UniaryOperatorInputHandler(Std_Sqrt); });
    connect(ui.toolButton_Sqr, &QToolButton::clicked, this, [=]() { UniaryOperatorInputHandler(Std_Sqr); });
    connect(ui.toolButton_Rep, &QToolButton::clicked, this, [=]() { UniaryOperatorInputHandler(Std_Rep); });

    connect(ui.toolButton_Plus, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Std_Plus); });
    connect(ui.toolButton_Minus, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Std_Minus); });
    connect(ui.toolButton_Mul, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Std_Mul); });
    connect(ui.toolButton_Div, &QToolButton::clicked, this, [=]() { BinaryOperatorInputHandler(Std_Div); });

    connect(ui.toolButton_Enter, &QToolButton::clicked, this, [=]() { EnterOperatorInputHandler(); });

    connect(ui.toolButton_Backspace, &QToolButton::clicked, this, [=]() { BackSpaceOperatorInputHandler(); });
    connect(ui.toolButton_Clear, &QToolButton::clicked, this, [=]() { ClearOperatorInputHandler(); });
    connect(ui.toolButton_ClearAll, &QToolButton::clicked, this, [=]() { ClearAllOperatorInputHandler(); });

}

void StandardControlPanel::NumberInputHandler(unsigned num)
{
    if (to_zeroize)
        Zeroize();

    show_last = false;
    if (in_result)
    {
        stocked_action = Std_Null;
    }

    if (isPrecisionLimitExceed())
        return;
    if (!floating_dot_enabled)
    {
        if (!(number == 0.0 && num == 0))
        {
            if (number >= 0)
                number = 10 * number + num;
            else
                number = 10 * number - num;
            digit_int++;
        }
    }
    else
    {
        if (number >= 0)
            number += std::pow(0.1, digit_float + 1) * num;
        else
            number -= std::pow(0.1, digit_float + 1) * num;

        digit_float++;
    }
    in_result = false;

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void StandardControlPanel::FloatingPointInputHandler()
{
    if (to_zeroize)
        Zeroize();

    if (in_result)
    {
        stocked_action = Std_Null;
    }

    show_last = false;
    if (floating_dot_enabled)
        return;

    floating_dot_enabled = true;
    in_result = false;

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void StandardControlPanel::UniaryOperatorInputHandler(const StdAction act)
{
    if (show_last)
    {
        switch (act)
        {
        case Std_Percent:
            last_number /= 100;
            break;
        case Std_Sqrt:
            last_number = std::sqrt(last_number);
            break;
        case Std_Sqr:
            last_number = std::pow(last_number, 2.0);
            break;
        case Std_Rep:
            if (last_number == 0.0)
                ;//TODO
            last_number = 1 / last_number;
            break;
        default:
            break;
        }

    }
    else
    {
        switch (act)
        {
        case Std_Percent:
            number /= 100;
            break;
        case Std_Sqrt:
            number = std::sqrt(number);
            break;
        case Std_Sqr:
            number = std::pow(number, 2.0);
            break;
        case Std_Rep:
            if (number == 0.0)
                ;//TODO
            number = 1 / number;
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

void StandardControlPanel::BinaryOperatorInputHandler(StdAction act)
{
    qDebug() << "On bin op begin:";
    qDebug() << "stock_act = " << stocked_action;
    qDebug() << "last_num = " << last_number;
    qDebug() << "curr_num = " << number;

    if (stocked_action != Std_Null)
    {
        if (in_sequence)
        {
            switch (stocked_action)
            {
            case Std_Plus:
                ConfirmNumber(last_number + number);
                break;
            case Std_Minus:
                ConfirmNumber(last_number - number);
                break;
            case Std_Mul:
                ConfirmNumber(last_number * number);
                break;
            case Std_Div:
                if (number == 0)
                    ; //TODO
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
    case Std_Plus:
    case Std_Minus:
    case Std_Mul:
    case Std_Div:
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

void StandardControlPanel::SignOperatorInputHandler()
{
    if (show_last)
        last_number = -last_number;
    else
        number = -number;

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void StandardControlPanel::EnterOperatorInputHandler()
{
    qDebug() << "On enter begin:";
    qDebug() << "stock_act = " << stocked_action;
    qDebug() << "last_num = " << last_number;

    if (stocked_action != Std_Null)
    {
        switch (stocked_action)
        {
        case Std_Plus:
            ConfirmNumber(last_number + number);
            break;
        case Std_Minus:
            ConfirmNumber(last_number - number);
            break;
        case Std_Mul:
            ConfirmNumber(last_number * number);
            break;
        case Std_Div:
            if (number == 0)
                ; //TODO
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
}

void StandardControlPanel::ClearOperatorInputHandler()
{
    Zeroize();
}

void StandardControlPanel::ClearAllOperatorInputHandler()
{
    init();
}

void StandardControlPanel::BackSpaceOperatorInputHandler()
{
    if (!floating_dot_enabled)
    {
        if (digit_int > 1)
            number = (double)((int)number / 10);
        else
            number = 0;
        if (digit_int > 0)
            digit_int--;
    }
    else
    {
        if (digit_float == 0)
            floating_dot_enabled = false;
        else
        {
            double delta = pow(10, -(int)digit_float);
            if (number > 0)
                number -= delta;
            else
                number += delta;
            digit_float--;
        }
    }

    qDebug() << "Text = " << GenerateNumberDisplay();
    emit UpdateNumberDisplay(GenerateNumberDisplay());
}

void StandardControlPanel::ConfirmNumber()
{
    last_number = number;
    last_digit_float = digit_float;
    last_digit_int = digit_int;
    last_floating_dot_enabled = floating_dot_enabled;
}

void StandardControlPanel::ConfirmNumber(double n)
{
    last_number = n;
    ExtractDigitsNumber(n, last_digit_int, last_digit_float, last_floating_dot_enabled);
}

void StandardControlPanel::Zeroize()
{
    number = 0.0;
    digit_int = digit_float = 0;
    floating_dot_enabled = false;
    to_zeroize = false;
}

bool StandardControlPanel::isPrecisionLimitExceed()
{
    return digit_int + digit_float >= DECIMAL_LIMIT;
}

void StandardControlPanel::ExtractDigitsNumber()
{
    double n = number;
    n = abs(n);

    unsigned i = 0, f = 0;
    double ni;
    double nf = modf(n, &ni);

    while (ni > 0.95)
    {
        i++;
        ni /= 10;
    }

    QString digits_str = QString("%1").arg(nf, 0, 'f', 12);
    while (digits_str.size() > 0 && (digits_str[0] == '0'))
        digits_str.remove(0, 1);
    while (digits_str.size() > 0 && (digits_str[0] == '.'))
        digits_str.remove(0, 1);
    while (digits_str.size() > 0 && (digits_str[digits_str.size() - 1] == '0'))
        digits_str.remove(digits_str.size() - 1, 1);
    f = digits_str.size();
    if (i + f > DECIMAL_LIMIT)
        f = DECIMAL_LIMIT - i;

    digit_int = i;
    digit_float = f;
    floating_dot_enabled = f > 0;
}

void StandardControlPanel::ExtractDigitsNumber(double n, unsigned& i, unsigned& f, bool& fe)
{
    n = abs(n);

    i = 0, f = 0;
    double ni;
    double nf = modf(n, &ni);

    while (ni > 0.95)
    {
        i++;
        ni /= 10;
    }

    QString digits_str = QString("%1").arg(nf, 0, 'f', 12);
    while (digits_str.size() > 0 && (digits_str[0] == '0'))
        digits_str.remove(0, 1);
    while (digits_str.size() > 0 && (digits_str[0] == '.'))
        digits_str.remove(0, 1);
    while (digits_str.size() > 0 && (digits_str[digits_str.size() - 1] == '0'))
        digits_str.remove(digits_str.size() - 1, 1);
    f = digits_str.size();
    if (i > DECIMAL_LIMIT)
        f = 0;
    else if (i + f > DECIMAL_LIMIT)
        f = DECIMAL_LIMIT - i;

    fe = f > 0;
}

QString StandardControlPanel::GenerateNumberDisplay()
{
    if (show_last)
    {
        if (last_number > pow(10, DECIMAL_LIMIT + 2))
            return QStringLiteral("错误：超出数位限制");
        if (last_floating_dot_enabled == false)
        {
            if (last_digit_int == 0)
                return "0";
            else
                return QString("%1").arg(last_number, 0, 'f', 0);
        }
        else
        {
            if (last_digit_float == 0)
                return QString("%1").arg(last_number, 0, 'f', 0) + ".";
            else
                return QString("%1").arg(last_number, 0, 'f', last_digit_float);
        }
    }
    else
    {
        if (number > pow(10, DECIMAL_LIMIT + 2))
            return QStringLiteral("错误：超出数位限制");
        if (floating_dot_enabled == false)
        {
            if (digit_int == 0)
                return "0";
            else
                return QString("%1").arg(number, 0, 'f', 0);
        }
        else
        {
            if (digit_float == 0)
                return QString("%1").arg(number, 0, 'f', 0) + ".";
            else
                return QString("%1").arg(number, 0, 'f', digit_float);
        }
    }
}
