/********************************************************************************
** Form generated from reading UI file 'DualModeCalculator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUALMODECALCULATOR_H
#define UI_DUALMODECALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DualModeCalculatorClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *topStableBarLayout;
    QToolButton *buttonSwitvhMode;
    QLabel *labelMode;
    QSpacerItem *horizontalSpacer_Top;
    QToolButton *buttonDisplayHistory;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *labelNumberDisplay;
    QVBoxLayout *mainWidget;

    void setupUi(QMainWindow *DualModeCalculatorClass)
    {
        if (DualModeCalculatorClass->objectName().isEmpty())
            DualModeCalculatorClass->setObjectName(QStringLiteral("DualModeCalculatorClass"));
        DualModeCalculatorClass->resize(450, 700);
        DualModeCalculatorClass->setMinimumSize(QSize(450, 700));
        centralWidget = new QWidget(DualModeCalculatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        topStableBarLayout = new QHBoxLayout();
        topStableBarLayout->setSpacing(6);
        topStableBarLayout->setObjectName(QStringLiteral("topStableBarLayout"));
        buttonSwitvhMode = new QToolButton(centralWidget);
        buttonSwitvhMode->setObjectName(QStringLiteral("buttonSwitvhMode"));
        buttonSwitvhMode->setMinimumSize(QSize(60, 60));

        topStableBarLayout->addWidget(buttonSwitvhMode);

        labelMode = new QLabel(centralWidget);
        labelMode->setObjectName(QStringLiteral("labelMode"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelMode->sizePolicy().hasHeightForWidth());
        labelMode->setSizePolicy(sizePolicy);
        labelMode->setMinimumSize(QSize(120, 60));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        labelMode->setFont(font);
        labelMode->setAlignment(Qt::AlignCenter);

        topStableBarLayout->addWidget(labelMode);

        horizontalSpacer_Top = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topStableBarLayout->addItem(horizontalSpacer_Top);

        buttonDisplayHistory = new QToolButton(centralWidget);
        buttonDisplayHistory->setObjectName(QStringLiteral("buttonDisplayHistory"));
        sizePolicy.setHeightForWidth(buttonDisplayHistory->sizePolicy().hasHeightForWidth());
        buttonDisplayHistory->setSizePolicy(sizePolicy);
        buttonDisplayHistory->setMinimumSize(QSize(60, 60));

        topStableBarLayout->addWidget(buttonDisplayHistory);


        verticalLayout_3->addLayout(topStableBarLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelNumberDisplay = new QLabel(centralWidget);
        labelNumberDisplay->setObjectName(QStringLiteral("labelNumberDisplay"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelNumberDisplay->sizePolicy().hasHeightForWidth());
        labelNumberDisplay->setSizePolicy(sizePolicy1);
        labelNumberDisplay->setMinimumSize(QSize(240, 80));
        labelNumberDisplay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelNumberDisplay);

        horizontalLayout->setStretch(0, 1);

        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        mainWidget = new QVBoxLayout();
        mainWidget->setSpacing(6);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));

        verticalLayout_3->addLayout(mainWidget);

        verticalLayout_3->setStretch(1, 2);
        verticalLayout_3->setStretch(2, 8);
        DualModeCalculatorClass->setCentralWidget(centralWidget);

        retranslateUi(DualModeCalculatorClass);

        QMetaObject::connectSlotsByName(DualModeCalculatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *DualModeCalculatorClass)
    {
        DualModeCalculatorClass->setWindowTitle(QApplication::translate("DualModeCalculatorClass", "DualModeCalculator", 0));
        buttonSwitvhMode->setText(QApplication::translate("DualModeCalculatorClass", "Swi", 0));
        labelMode->setText(QApplication::translate("DualModeCalculatorClass", "Mode", 0));
        buttonDisplayHistory->setText(QApplication::translate("DualModeCalculatorClass", "His", 0));
        buttonDisplayHistory->setShortcut(QApplication::translate("DualModeCalculatorClass", "H", 0));
        labelNumberDisplay->setText(QApplication::translate("DualModeCalculatorClass", "Number Display ", 0));
    } // retranslateUi

};

namespace Ui {
    class DualModeCalculatorClass: public Ui_DualModeCalculatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUALMODECALCULATOR_H
