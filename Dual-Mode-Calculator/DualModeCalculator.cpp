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
        "   color: gray;\n"
        "}\n"
        "QToolButton[number-button=\"true\"] {\n"
        "   background-color: white; \n"
        "}\n"
        "QToolButton[number-button=\"true\"]:hover {\n"
        "   background-color: #B0B0B0; \n"
        "}\n"
        "QToolButton[number-button=\"true\"]:pressed {\n"
        "   background-color: #A0A0A0; \n"
        "}\n"
        "QToolButton[number-button=\"true\"]:disabled {\n"
        "   color: gray;\n"
        "}\n"
    );

    qDebug() << "after init" << ui.labelNumberDisplay->size();;

}


void DualModeCalculator::resizeEvent(QResizeEvent * event)
{
    qDebug() << "resize" << event->size();
    AdjustFontSize();
}

void DualModeCalculator::InitialSetGUI()
{
    mode = StandardMode;
    show_history = false;

    connect(ui.buttonSwitvhMode, &QToolButton::clicked, this,
        [=]() {
        mode = (mode == StandardMode) ? ProgrammerMode : StandardMode;
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
    stdControlPanel = new StandardControlPanel;
    proControlPanel = new ProgrammerControlPanel;

    // replace UI components:

    // top bar - labelMode
    ui.labelMode->setVisible(false);
    ui.topStableBarLayout->replaceWidget(ui.labelMode, labelMode);
    ui.labelMode = labelMode;
    labelMode->setObjectName(QStringLiteral("labelMode"));
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(labelMode->sizePolicy().hasHeightForWidth());
    labelMode->setSizePolicy(sizePolicy);
    labelMode->setMinimumSize(QSize(50, 45));
    labelMode->setAlignment(Qt::AlignCenter);

    UpdateGUI();
}

void DualModeCalculator::ConnectActions()
{
    connect(stdControlPanel, &StandardControlPanel::UpdateNumberDisplay, this, [=](QString num)
    {
        ui.labelNumberDisplay->setText(num);
        UpdateGUI();
    });
}

void DualModeCalculator::InitialzeComponents()
{
    stdControlPanel->init();
    //proControlPanel->init();
}

void DualModeCalculator::UpdateGUI()
{
    // clear main layout.
    QLayoutItem *child;
    while ((child = ui.mainWidget->takeAt(0)) != 0) {
        ui.mainWidget->removeItem(child);
    }
    test_His->setVisible(false);
    stdControlPanel->setVisible(false);
    proControlPanel->setVisible(false);
    //ui.labelNumberDisplay->setFrameStyle(QLabel::Raised | QLabel::Box);

    // switch main widget.
    if (show_history)
    {
        ui.mainWidget->addWidget(test_His);
        test_His->setVisible(true);
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

