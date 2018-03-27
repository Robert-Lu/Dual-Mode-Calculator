#pragma once

#include <QWidget>
#include <QString>
#include <string>
#include "ui_ArithmeticQuiz.h"
//QRandomGenerator
#include <QRandomGenerator>
#include <algorithm>

class ArithmeticQuiz : public QWidget
{
    Q_OBJECT

public:
    ArithmeticQuiz(QWidget *parent = Q_NULLPTR);
    ~ArithmeticQuiz();
    void init();

    enum StdAction
    {
        Std_0, Std_1, Std_2, Std_3, Std_4, Std_5, Std_6, Std_7, Std_8, Std_9
    };

    enum class State
    {
        Start, Countdown, Problem, End
    }
signals:
    // display a QString in the field
    void UpdateDisplay(QString);

private:
    Ui::ArithmeticQuiz ui;
    // current state
    State state;
    // the timer used to countdown
    QTimer *timer;
    // countdown only used in the beginning
    int countdown;
    // the string to display
    QString display;
    // the correct answer to the problem
    std::string answer;
    // count of the problems answered
    int score;

    // game procedure
    void start_game();
    void count_down(int secs);
    void generate_problem();
    void end_game();

    // routine
    void connect_button_actions();

    // handler
    void number_input(unsigned);
    void keyPressEvent(QKeyEvent*);
};
