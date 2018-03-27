#include "stdafx.h"
#include "DualModeCalculator.h"


DualModeCalculator::DualModeCalculator(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    InitialSetGUI();
    ConnectActions();
    InitialzeComponents();

    setStyleSheet(
        "QMainWindow {\n"
        "   background: #C0C0BF;\n"
        "}\n"
        "QToolButton {\n"
        "   font: 24px bond;\n"
        "   border-style: none;\n"
        "   border-radius: 4px;\n"
        "   background-color: #E0E0E0;\n"
        "}\n"
        "QToolButton:hover {\n"
        "   background-color: #B0B0B0;\n"
        "}\n"
        "QToolButton:pressed {\n"
        "   background-color: #A0A0A0;\n"
        "}\n"
        "QToolButton:disabled {\n"
        "   color: #909090;\n"
        "}\n"
        "QToolButton[number-button=\"true\"] {\n"
        "   font: 32px bond;\n"
        "   background-color: white; \n"
        "}\n"
        "QToolButton[icon-only=\"true\"] {\n"
        "   background-color: #00000000; \n"
        "}\n"
        "QToolButton[number-button=\"true\"]:hover {\n"
        "   background-color: #B0B0B0; \n"
        "}\n"
        "QToolButton[number-button=\"true\"]:pressed {\n"
        "   background-color: #A0A0A0; \n"
        "}\n"
        "QToolButton[number-button=\"true\"]:disabled {\n"
        "   color: #909090;\n"
        "}\n"
    );
}


void DualModeCalculator::resizeEvent(QResizeEvent * event)
{
    qDebug() << "resize" << event->size();
    AdjustFontSize();
}

void DualModeCalculator::keyPressEvent(QKeyEvent* event)
{
    // Get event modifiers key
    const Qt::KeyboardModifiers modifiers = event->modifiers();

    if (mode == StandardMode)
    {
        if ((event->key() == Qt::Key_0) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_0);
        }
        else if ((event->key() == Qt::Key_1) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_1);
        }
        else if ((event->key() == Qt::Key_1) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_1);
        }
        else if ((event->key() == Qt::Key_2) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_2);
        }
        else if ((event->key() == Qt::Key_3) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_3);
        }
        else if ((event->key() == Qt::Key_4) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_4);
        }
        else if ((event->key() == Qt::Key_5) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_5);
        }
        else if ((event->key() == Qt::Key_6) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_6);
        }
        else if ((event->key() == Qt::Key_7) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_7);
        }
        else if ((event->key() == Qt::Key_8) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_8);
        }
        else if ((event->key() == Qt::Key_9) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_9);
        }
        else if ((event->key() == Qt::Key_Plus) && (modifiers == Qt::ShiftModifier)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_Plus);
        }
        else if ((event->key() == Qt::Key_Minus) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_Minus);
        }
        else if ((event->key() == Qt::Key_Asterisk) && (modifiers == Qt::ShiftModifier)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_Mul);
        }
        else if ((event->key() == Qt::Key_Slash) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_Div);
        }
        else if (((event->key() == Qt::Key_Enter) || (event->key() == Qt::Key_Return)) 
            && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_Enter);
        }
        else if ((event->key() == Qt::Key_Backspace) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_Backspace);
        }
        else if ((event->key() == Qt::Key_Period) && (modifiers == Qt::NoButton)) {
            stdControlPanel->KeyboardActionHandler(StandardControlPanel::Std_Dot);
        }
    }
    else
    {
        if ((event->key() == Qt::Key_0) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_0);
        }
        else if ((event->key() == Qt::Key_1) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_1);
        }
        else if ((event->key() == Qt::Key_1) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_1);
        }
        else if ((event->key() == Qt::Key_2) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_2);
        }
        else if ((event->key() == Qt::Key_3) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_3);
        }
        else if ((event->key() == Qt::Key_4) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_4);
        }
        else if ((event->key() == Qt::Key_5) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_5);
        }
        else if ((event->key() == Qt::Key_6) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_6);
        }
        else if ((event->key() == Qt::Key_7) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_7);
        }
        else if ((event->key() == Qt::Key_8) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_8);
        }
        else if ((event->key() == Qt::Key_9) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_9);
        }
        else if ((event->key() == Qt::Key_Plus) && (modifiers == Qt::ShiftModifier)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_Plus);
        }
        else if ((event->key() == Qt::Key_Minus) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_Minus);
        }
        else if ((event->key() == Qt::Key_Asterisk) && (modifiers == Qt::ShiftModifier)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_Mul);
        }
        else if ((event->key() == Qt::Key_Slash) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_Div);
        }
        else if (((event->key() == Qt::Key_Enter) || (event->key() == Qt::Key_Return))
            && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_Enter);
        }
        else if ((event->key() == Qt::Key_Backspace) && (modifiers == Qt::NoButton)) {
            proControlPanel->KeyboardActionHandler(ProgrammerControlPanel::Pro_Backspace);
        }

    }

}

void DualModeCalculator::InitialSetGUI()
{
    mode = StandardMode;
    show_history = false;

    connect(ui.buttonSwitvhMode, &QToolButton::clicked, this,
        [=]() {
        mode = (mode == StandardMode) ? ProgrammerMode : StandardMode;
        InitialzeComponents();
        UpdateGUI();
    }
    );

    connect(ui.buttonDisplayHistory, &QToolButton::clicked, this,
        [=]() {
        show_history = !show_history;
        UpdateGUI();
    }
    );

    test_His = new QLabel(tr("History Display"));
    labelMode = new QAutoFontSizeLabel();
    labelNumberDisplay = new QAutoFontSizeLabel();
    hisView = new HistoryWidget;
    stdControlPanel = new StandardControlPanel;
    proControlPanel = new ProgrammerControlPanel;

    // replace UI components:

    // top bar - labelMode
    ui.labelMode->setVisible(false);
    ui.topStableBarLayout->replaceWidget(ui.labelMode, labelMode);
    ui.labelMode = labelMode;
    labelMode->setObjectName(QStringLiteral("labelMode"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    labelMode->setSizePolicy(sizePolicy);
    labelMode->setFixedSize(120, 48);
    labelMode->setAlignment(Qt::AlignCenter);

    ui.buttonDisplayHistory->setIcon(QIcon(":/DualModeCalculator/history"));
    ui.buttonDisplayHistory->setIconSize(QSize(45, 45));
    ui.buttonDisplayHistory->setProperty("icon-only", true);

    ui.buttonSwitvhMode->setIcon(QIcon(":/DualModeCalculator/switch"));
    ui.buttonSwitvhMode->setIconSize(QSize(45, 45));
    ui.buttonSwitvhMode->setProperty("icon-only", true);
    UpdateGUI();
}

void DualModeCalculator::ConnectActions()
{
    connect(stdControlPanel, &StandardControlPanel::UpdateNumberDisplay, this, [=](QString num)
    {
        ui.labelNumberDisplay->setText(num);
        UpdateGUI();
    });
    connect(proControlPanel, &ProgrammerControlPanel::UpdateNumberDisplay, this, [=](QString num)
    {
        ui.labelNumberDisplay->setText(num);
        UpdateGUI();
    });
    connect(stdControlPanel, &StandardControlPanel::UpdateNumberHistory, this, [=](QString num)
    {
        history.push_back(num);
    });
    connect(proControlPanel, &ProgrammerControlPanel::UpdateNumberHistory, this, [=](QString num)
    {
        history.push_back(num);
    });
}

void DualModeCalculator::InitialzeComponents()
{
    proControlPanel->init();
    stdControlPanel->init();
}

void DualModeCalculator::UpdateGUI()
{
    // clear main layout.
    QLayoutItem *child;
    while ((child = ui.mainWidget->takeAt(0)) != 0) {
        ui.mainWidget->removeItem(child);
    }
    test_His->setVisible(false);
    hisView->setVisible(false);
    stdControlPanel->setVisible(false);
    proControlPanel->setVisible(false);

    // switch main widget.
    if (show_history)
    {
        ui.mainWidget->addWidget(hisView);
        hisView->setVisible(true);
        hisView->init(history);
    }
    else
    {
        if (mode == StandardMode)
        {
            ui.mainWidget->addWidget(stdControlPanel);
            stdControlPanel->setVisible(true);
        }
        else
        {
            ui.mainWidget->addWidget(proControlPanel);
            proControlPanel->setVisible(true);
        }
    }

    // set mode label.
    if (mode == StandardMode)
    {
        ui.labelMode->setText(QStringLiteral("标准"));
    }
    else
    {
        ui.labelMode->setText(QStringLiteral("程序员"));
    }

    AdjustFontSize();
}

void DualModeCalculator::AdjustFontSize()
{
    // get initial settings
    QString text = ui.labelNumberDisplay->text();
    if (text.size() == 0)
        return;

    QFont font = ui.labelNumberDisplay->font();
    
    QRect rect = ui.labelNumberDisplay->contentsRect();
    int m = ui.labelNumberDisplay->margin(); rect.adjust(m, m, -m, -m);
    layoutDirection();
    const int align
        = QStyle::visualAlignment(layoutDirection(), ui.labelNumberDisplay->QLabel::alignment());
    int i = ui.labelNumberDisplay->indent();
    if (i < 0 && ui.labelNumberDisplay->frameWidth()) { // no indent, but we do have a frame
        m = fontMetrics().width(QLatin1Char('x')) / 2 - m;
    }
    if (m > 0) {
        if (align & Qt::AlignLeft) rect.setLeft(rect.left() + m);
        if (align & Qt::AlignRight) rect.setRight(rect.right() - m);
        if (align & Qt::AlignTop) rect.setTop(rect.top() + m);
        if (align & Qt::AlignBottom) rect.setBottom(rect.bottom() - m);
    }
    QRect widgetRect = rect;

    const float widgetWidth = ui.labelNumberDisplay->size().width();
    const float widgetHeight = ui.labelNumberDisplay->size().height();

    QRectF newFontSizeRect;
    float currentSize = font.pointSizeF() * 2;

    float step = currentSize / 2.0;
    const float FONT_PRECISION = 0.25f;

    /* If too small, increase step */
    if (step <= FONT_PRECISION) {
        step = FONT_PRECISION * 4.0;
    }

    float lastTestedSize = currentSize;

    float currentHeight = 0;
    float currentWidth = 0;

    /* Only stop when step is small enough and new size is smaller than QWidget */
    while (step>FONT_PRECISION || (currentHeight > widgetHeight) || (currentWidth > widgetWidth)) {
        /* Keep last tested value */
        lastTestedSize = currentSize;

        /* Test label with its font */
        font.setPointSizeF(currentSize);
        /* Use font metrics to test */
        QFontMetricsF fm(font);

        newFontSizeRect = fm.boundingRect(widgetRect, (ui.labelNumberDisplay->wordWrap() ? Qt::TextWordWrap : 0) | ui.labelNumberDisplay->alignment(), text);

        currentHeight = newFontSizeRect.height();
        currentWidth = newFontSizeRect.width();

        /* If new font size is too big, decrease it */
        if ((currentHeight > widgetHeight) || (currentWidth > widgetWidth)) {
            //qDebug() << "-- contentsRect()" << label->contentsRect() << "rect"<< label->rect() << " newFontSizeRect" << newFontSizeRect << "Tight" << text << currentSize;
            currentSize -= step;
            /* if step is small enough, keep it constant, so it converge to biggest font size */
            if (step>FONT_PRECISION) {
                step /= 2.0;
            }
            /* Do not allow negative size */
            if (currentSize <= 0) {
                break;
            }
        }
        /* If new font size is smaller than maximum possible size, increase it */
        else {
            currentSize += step;
        }
    }
    font.setPointSize(currentSize);
    ui.labelNumberDisplay->setFont(font);
}

