/********************************************************************************
** Form generated from reading UI file 'StandardControlPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STANDARDCONTROLPANEL_H
#define UI_STANDARDCONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StandardControlPanel
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *mainGridLayout;
    QToolButton *toolButton_Percent;
    QToolButton *toolButton_Sqr;
    QToolButton *toolButton_Sqrt;
    QToolButton *toolButton_Rep;
    QToolButton *toolButton_Clear;
    QToolButton *toolButton_Backspace;
    QToolButton *toolButton_7;
    QToolButton *toolButton_Div;
    QToolButton *toolButton_ClearAll;
    QToolButton *toolButton_5;
    QToolButton *toolButton_4;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_Mul;
    QToolButton *toolButton_3;
    QToolButton *toolButton_6;
    QToolButton *toolButton_2;
    QToolButton *toolButton_1;
    QToolButton *toolButton_Plus;
    QToolButton *toolButton_0;
    QToolButton *toolButton_Sign;
    QToolButton *toolButton_Dot;
    QToolButton *toolButton_Enter;
    QToolButton *toolButton_Minus;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *StandardControlPanel)
    {
        if (StandardControlPanel->objectName().isEmpty())
            StandardControlPanel->setObjectName(QStringLiteral("StandardControlPanel"));
        StandardControlPanel->resize(272, 329);
        verticalLayout = new QVBoxLayout(StandardControlPanel);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        mainGridLayout = new QGridLayout();
        mainGridLayout->setSpacing(6);
        mainGridLayout->setObjectName(QStringLiteral("mainGridLayout"));
        toolButton_Percent = new QToolButton(StandardControlPanel);
        toolButton_Percent->setObjectName(QStringLiteral("toolButton_Percent"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton_Percent->sizePolicy().hasHeightForWidth());
        toolButton_Percent->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Percent, 1, 0, 1, 1);

        toolButton_Sqr = new QToolButton(StandardControlPanel);
        toolButton_Sqr->setObjectName(QStringLiteral("toolButton_Sqr"));
        sizePolicy.setHeightForWidth(toolButton_Sqr->sizePolicy().hasHeightForWidth());
        toolButton_Sqr->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Sqr, 1, 2, 1, 1);

        toolButton_Sqrt = new QToolButton(StandardControlPanel);
        toolButton_Sqrt->setObjectName(QStringLiteral("toolButton_Sqrt"));
        sizePolicy.setHeightForWidth(toolButton_Sqrt->sizePolicy().hasHeightForWidth());
        toolButton_Sqrt->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Sqrt, 1, 1, 1, 1);

        toolButton_Rep = new QToolButton(StandardControlPanel);
        toolButton_Rep->setObjectName(QStringLiteral("toolButton_Rep"));
        sizePolicy.setHeightForWidth(toolButton_Rep->sizePolicy().hasHeightForWidth());
        toolButton_Rep->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Rep, 1, 3, 1, 1);

        toolButton_Clear = new QToolButton(StandardControlPanel);
        toolButton_Clear->setObjectName(QStringLiteral("toolButton_Clear"));
        sizePolicy.setHeightForWidth(toolButton_Clear->sizePolicy().hasHeightForWidth());
        toolButton_Clear->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Clear, 2, 1, 1, 1);

        toolButton_Backspace = new QToolButton(StandardControlPanel);
        toolButton_Backspace->setObjectName(QStringLiteral("toolButton_Backspace"));
        sizePolicy.setHeightForWidth(toolButton_Backspace->sizePolicy().hasHeightForWidth());
        toolButton_Backspace->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Backspace, 2, 2, 1, 1);

        toolButton_7 = new QToolButton(StandardControlPanel);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        sizePolicy.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_7, 3, 0, 1, 1);

        toolButton_Div = new QToolButton(StandardControlPanel);
        toolButton_Div->setObjectName(QStringLiteral("toolButton_Div"));
        sizePolicy.setHeightForWidth(toolButton_Div->sizePolicy().hasHeightForWidth());
        toolButton_Div->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Div, 2, 3, 1, 1);

        toolButton_ClearAll = new QToolButton(StandardControlPanel);
        toolButton_ClearAll->setObjectName(QStringLiteral("toolButton_ClearAll"));
        sizePolicy.setHeightForWidth(toolButton_ClearAll->sizePolicy().hasHeightForWidth());
        toolButton_ClearAll->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_ClearAll, 2, 0, 1, 1);

        toolButton_5 = new QToolButton(StandardControlPanel);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        sizePolicy.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_5, 4, 1, 1, 1);

        toolButton_4 = new QToolButton(StandardControlPanel);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        sizePolicy.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_4, 4, 0, 1, 1);

        toolButton_8 = new QToolButton(StandardControlPanel);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        sizePolicy.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_8, 3, 1, 1, 1);

        toolButton_9 = new QToolButton(StandardControlPanel);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        sizePolicy.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_9, 3, 2, 1, 1);

        toolButton_Mul = new QToolButton(StandardControlPanel);
        toolButton_Mul->setObjectName(QStringLiteral("toolButton_Mul"));
        sizePolicy.setHeightForWidth(toolButton_Mul->sizePolicy().hasHeightForWidth());
        toolButton_Mul->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Mul, 3, 3, 1, 1);

        toolButton_3 = new QToolButton(StandardControlPanel);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_3, 5, 2, 1, 1);

        toolButton_6 = new QToolButton(StandardControlPanel);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        sizePolicy.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_6, 4, 2, 1, 1);

        toolButton_2 = new QToolButton(StandardControlPanel);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_2, 5, 1, 1, 1);

        toolButton_1 = new QToolButton(StandardControlPanel);
        toolButton_1->setObjectName(QStringLiteral("toolButton_1"));
        sizePolicy.setHeightForWidth(toolButton_1->sizePolicy().hasHeightForWidth());
        toolButton_1->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_1, 5, 0, 1, 1);

        toolButton_Plus = new QToolButton(StandardControlPanel);
        toolButton_Plus->setObjectName(QStringLiteral("toolButton_Plus"));
        sizePolicy.setHeightForWidth(toolButton_Plus->sizePolicy().hasHeightForWidth());
        toolButton_Plus->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Plus, 5, 3, 1, 1);

        toolButton_0 = new QToolButton(StandardControlPanel);
        toolButton_0->setObjectName(QStringLiteral("toolButton_0"));
        sizePolicy.setHeightForWidth(toolButton_0->sizePolicy().hasHeightForWidth());
        toolButton_0->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_0, 6, 1, 1, 1);

        toolButton_Sign = new QToolButton(StandardControlPanel);
        toolButton_Sign->setObjectName(QStringLiteral("toolButton_Sign"));
        sizePolicy.setHeightForWidth(toolButton_Sign->sizePolicy().hasHeightForWidth());
        toolButton_Sign->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Sign, 6, 0, 1, 1);

        toolButton_Dot = new QToolButton(StandardControlPanel);
        toolButton_Dot->setObjectName(QStringLiteral("toolButton_Dot"));
        sizePolicy.setHeightForWidth(toolButton_Dot->sizePolicy().hasHeightForWidth());
        toolButton_Dot->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Dot, 6, 2, 1, 1);

        toolButton_Enter = new QToolButton(StandardControlPanel);
        toolButton_Enter->setObjectName(QStringLiteral("toolButton_Enter"));
        sizePolicy.setHeightForWidth(toolButton_Enter->sizePolicy().hasHeightForWidth());
        toolButton_Enter->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Enter, 6, 3, 1, 1);

        toolButton_Minus = new QToolButton(StandardControlPanel);
        toolButton_Minus->setObjectName(QStringLiteral("toolButton_Minus"));
        sizePolicy.setHeightForWidth(toolButton_Minus->sizePolicy().hasHeightForWidth());
        toolButton_Minus->setSizePolicy(sizePolicy);

        mainGridLayout->addWidget(toolButton_Minus, 4, 3, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainGridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        mainGridLayout->setRowStretch(0, 1);
        mainGridLayout->setRowStretch(1, 2);
        mainGridLayout->setRowStretch(2, 2);
        mainGridLayout->setRowStretch(3, 2);
        mainGridLayout->setRowStretch(4, 2);
        mainGridLayout->setRowStretch(5, 2);
        mainGridLayout->setRowStretch(6, 2);

        verticalLayout->addLayout(mainGridLayout);


        retranslateUi(StandardControlPanel);

        QMetaObject::connectSlotsByName(StandardControlPanel);
    } // setupUi

    void retranslateUi(QWidget *StandardControlPanel)
    {
        StandardControlPanel->setWindowTitle(QApplication::translate("StandardControlPanel", "StandardControlPanel", 0));
        toolButton_Percent->setText(QApplication::translate("StandardControlPanel", "%", 0));
        toolButton_Sqr->setText(QApplication::translate("StandardControlPanel", "x^2", 0));
        toolButton_Sqrt->setText(QApplication::translate("StandardControlPanel", "sqrt", 0));
        toolButton_Rep->setText(QApplication::translate("StandardControlPanel", "1/x", 0));
        toolButton_Clear->setText(QApplication::translate("StandardControlPanel", "C", 0));
        toolButton_Backspace->setText(QApplication::translate("StandardControlPanel", "back", 0));
        toolButton_7->setText(QApplication::translate("StandardControlPanel", "7", 0));
        toolButton_Div->setText(QApplication::translate("StandardControlPanel", "/", 0));
        toolButton_ClearAll->setText(QApplication::translate("StandardControlPanel", "CA", 0));
        toolButton_5->setText(QApplication::translate("StandardControlPanel", "5", 0));
        toolButton_4->setText(QApplication::translate("StandardControlPanel", "4", 0));
        toolButton_8->setText(QApplication::translate("StandardControlPanel", "8", 0));
        toolButton_9->setText(QApplication::translate("StandardControlPanel", "9", 0));
        toolButton_Mul->setText(QApplication::translate("StandardControlPanel", "X", 0));
        toolButton_3->setText(QApplication::translate("StandardControlPanel", "3", 0));
        toolButton_6->setText(QApplication::translate("StandardControlPanel", "6", 0));
        toolButton_2->setText(QApplication::translate("StandardControlPanel", "2", 0));
        toolButton_1->setText(QApplication::translate("StandardControlPanel", "1", 0));
        toolButton_Plus->setText(QApplication::translate("StandardControlPanel", "+", 0));
        toolButton_0->setText(QApplication::translate("StandardControlPanel", "0", 0));
        toolButton_Sign->setText(QApplication::translate("StandardControlPanel", "+/-", 0));
        toolButton_Dot->setText(QApplication::translate("StandardControlPanel", ".", 0));
        toolButton_Enter->setText(QApplication::translate("StandardControlPanel", "=", 0));
        toolButton_Minus->setText(QApplication::translate("StandardControlPanel", "-", 0));
    } // retranslateUi

};

namespace Ui {
    class StandardControlPanel: public Ui_StandardControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STANDARDCONTROLPANEL_H
