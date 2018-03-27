#include "ArithmeticQuiz.hpp"

ArithmeticQuiz::ArithmeticQuiz(QWidget *parent = Q_NULLPTR) :QWidget(parent)
{
    timer = new QTimer(this);
    ui.setupUi(this);
    ConnectButtonActions();
}

ArithmeticQuiz::~ArithmeticQuiz()
{
}

// game procedure
void ArithmeticQuiz::start_game()
{
    display = QString("Press Enter to begin");
    emit UpdateDisplay(display);
    // to-do: flickering text
    score = 0;
    state = State::Start;
}

void ArithmeticQuiz::count_down(int secs)
{
    if (secs <= 0)
    {
        state = State::Problem;
        generate_problem();
        return;
    }
    else
    {
        state = State::Countdown;
        QTimer::singleShot(1000, this, std::bind(&ArithmeticQuiz::count_down, this, secs - 1));
    }
}

void ArithmeticQuiz::end_game()
{
    display = QString("Good job! You've earned %1 points!").arg(score);
    emit UpdateDisplay(display);
    state = State::End;
}

void ArithmeticQuiz::generate_problem()
{
    static char ops[] = {'+', '-', '*', '/'};
    quint32 rand_num = QRandomGenerator::global()->generate();

    uint32_t op = rand_num & 3;
    rand_num >>= 2;

    uint32_t x, y;
    if (op > 1)
    {
        // mult, div
        x = rand_num & 31;
        y = (rand_num / 32) & 31;
    } 
    else
    {
        x = rand_num & 63;
        y = (rand_num / 64) & 63;
    }

    uint32_t ans;
    // set answer
    switch (op)
    {
        case 0: ans = x + y; break;
        case 1: if (x < y)
                    std::swap(x, y);
                ans = x - y; break;
        case 2: ans = x * y; break;
        default: ++x; ++y;
                ans = x * y;
                std::swap(x, ans);
    }
    answer = std::to_string(ans);
    display = QString("%1 %2 %3 = ").arg(x).arg(ops[op]).arg(y);

    state = State::Problem;
    emit UpdateDisplay(display);
}

// handler
void ArithmeticQuiz::connect_button_actions()
{
    connect(ui.toolButton_0, &QToolButton::clicked, this, [=]() { number_input(0); });
    connect(ui.toolButton_1, &QToolButton::clicked, this, [=]() { number_input(1); });
    connect(ui.toolButton_2, &QToolButton::clicked, this, [=]() { number_input(2); });
    connect(ui.toolButton_3, &QToolButton::clicked, this, [=]() { number_input(3); });
    connect(ui.toolButton_4, &QToolButton::clicked, this, [=]() { number_input(4); });
    connect(ui.toolButton_5, &QToolButton::clicked, this, [=]() { number_input(5); });
    connect(ui.toolButton_6, &QToolButton::clicked, this, [=]() { number_input(6); });
    connect(ui.toolButton_7, &QToolButton::clicked, this, [=]() { number_input(7); });
    connect(ui.toolButton_8, &QToolButton::clicked, this, [=]() { number_input(8); });
    connect(ui.toolButton_9, &QToolButton::clicked, this, [=]() { number_input(9); });
}

void ArithmeticQuiz::keyPressEvent(QKeyEvent *ev)
{
    switch (state)
    {
        case State::Problem: 
            if (ev->key() <= Qt::Key_9 && ev->key() >= Qt::Key_0)
                number_input(ev->key() - Qt::Key_0);
            break;
        case State::Start:  
            if (ev->key() == Qt::Key_Enter)
                count_down();
            break;
        case State::End:
            start_game();
            break;
        default:
            break;
    }
}

void number_input(unsigned num)
{
    if (answer.empty())
    {
        qDebug() << "Empty Answer!\n";
        return;
    }

    if (num + '0' == answer[0])
    {
        answer.erase(0, 1);
    }
    else
    {
        // wrong answer
          QTimer::singleShot(3000, this, &ArithmeticQuiz::end_game);
    }

    display += '0' + num;
    emit UpdateDisplay(display);
    // right answer
    if (answer.empty())
    {
        score++;
        generate_problem();
    }
}