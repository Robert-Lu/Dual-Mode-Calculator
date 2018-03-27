/********************************************************************************
** Form generated from reading UI file 'ProgrammerControlPanel.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRAMMERCONTROLPANEL_H
#define UI_PROGRAMMERCONTROLPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProgrammerControlPanel
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *radixDisplayLayout;
    QGridLayout *gridLayout;
    QToolButton *buttonOct;
    QToolButton *buttonHex;
    QToolButton *buttonBin;
    QToolButton *buttonDec;
    QLabel *labelHex;
    QLabel *labelDec;
    QLabel *labelOct;
    QLabel *labelBin;
    QGridLayout *mainGridLayout;
    QToolButton *toolButton_And;
    QToolButton *toolButton_A;
    QToolButton *toolButton_Not;
    QToolButton *toolButton_Xor;
    QToolButton *toolButton_Or;
    QToolButton *toolButton_Backspace;
    QToolButton *toolButton_B;
    QToolButton *toolButton_ClearAll;
    QToolButton *toolButton_Clear;
    QToolButton *toolButton_Div;
    QToolButton *toolButton_C;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_Mul;
    QToolButton *toolButton_4;
    QToolButton *toolButton_D;
    QToolButton *toolButton_5;
    QToolButton *toolButton_Minus;
    QToolButton *toolButton_6;
    QToolButton *toolButton_E;
    QToolButton *toolButton_1;
    QToolButton *toolButton_Plus;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_F;
    QToolButton *toolButton_0;
    QToolButton *toolButton_Sign;
    QToolButton *toolButton_Dot;
    QToolButton *toolButton_Enter;
    QToolButton *toolButton_7;

    void setupUi(QWidget *ProgrammerControlPanel)
    {
        if (ProgrammerControlPanel->objectName().isEmpty())
            ProgrammerControlPanel->setObjectName(QStringLiteral("ProgrammerControlPanel"));
        ProgrammerControlPanel->resize(280, 277);
        verticalLayout_2 = new QVBoxLayout(ProgrammerControlPanel);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radixDisplayLayout = new QHBoxLayout();
        radixDisplayLayout->setSpacing(6);
        radixDisplayLayout->setObjectName(QStringLiteral("radixDisplayLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setVerticalSpacing(0);
        buttonOct = new QToolButton(ProgrammerControlPanel);
        buttonOct->setObjectName(QStringLiteral("buttonOct"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonOct->sizePolicy().hasHeightForWidth());
        buttonOct->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonOct, 2, 0, 1, 1);

        buttonHex = new QToolButton(ProgrammerControlPanel);
        buttonHex->setObjectName(QStringLiteral("buttonHex"));
        sizePolicy.setHeightForWidth(buttonHex->sizePolicy().hasHeightForWidth());
        buttonHex->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonHex, 0, 0, 1, 1);

        buttonBin = new QToolButton(ProgrammerControlPanel);
        buttonBin->setObjectName(QStringLiteral("buttonBin"));
        sizePolicy.setHeightForWidth(buttonBin->sizePolicy().hasHeightForWidth());
        buttonBin->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonBin, 3, 0, 1, 1);

        buttonDec = new QToolButton(ProgrammerControlPanel);
        buttonDec->setObjectName(QStringLiteral("buttonDec"));
        sizePolicy.setHeightForWidth(buttonDec->sizePolicy().hasHeightForWidth());
        buttonDec->setSizePolicy(sizePolicy);

        gridLayout->addWidget(buttonDec, 1, 0, 1, 1);

        labelHex = new QLabel(ProgrammerControlPanel);
        labelHex->setObjectName(QStringLiteral("labelHex"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelHex->sizePolicy().hasHeightForWidth());
        labelHex->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelHex, 0, 1, 1, 1);

        labelDec = new QLabel(ProgrammerControlPanel);
        labelDec->setObjectName(QStringLiteral("labelDec"));
        sizePolicy1.setHeightForWidth(labelDec->sizePolicy().hasHeightForWidth());
        labelDec->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelDec, 1, 1, 1, 1);

        labelOct = new QLabel(ProgrammerControlPanel);
        labelOct->setObjectName(QStringLiteral("labelOct"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelOct->sizePolicy().hasHeightForWidth());
        labelOct->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(labelOct, 2, 1, 1, 1);

        labelBin = new QLabel(ProgrammerControlPanel);
        labelBin->setObjectName(QStringLiteral("labelBin"));
        sizePolicy2.setHeightForWidth(labelBin->sizePolicy().hasHeightForWidth());
        labelBin->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(labelBin, 3, 1, 1, 1);


        radixDisplayLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(radixDisplayLayout);

        mainGridLayout = new QGridLayout();
        mainGridLayout->setSpacing(6);
        mainGridLayout->setObjectName(QStringLiteral("mainGridLayout"));
        toolButton_And = new QToolButton(ProgrammerControlPanel);
        toolButton_And->setObjectName(QStringLiteral("toolButton_And"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(toolButton_And->sizePolicy().hasHeightForWidth());
        toolButton_And->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_And, 0, 4, 1, 1);

        toolButton_A = new QToolButton(ProgrammerControlPanel);
        toolButton_A->setObjectName(QStringLiteral("toolButton_A"));
        sizePolicy3.setHeightForWidth(toolButton_A->sizePolicy().hasHeightForWidth());
        toolButton_A->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_A, 0, 0, 1, 1);

        toolButton_Not = new QToolButton(ProgrammerControlPanel);
        toolButton_Not->setObjectName(QStringLiteral("toolButton_Not"));
        sizePolicy3.setHeightForWidth(toolButton_Not->sizePolicy().hasHeightForWidth());
        toolButton_Not->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Not, 0, 3, 1, 1);

        toolButton_Xor = new QToolButton(ProgrammerControlPanel);
        toolButton_Xor->setObjectName(QStringLiteral("toolButton_Xor"));
        sizePolicy3.setHeightForWidth(toolButton_Xor->sizePolicy().hasHeightForWidth());
        toolButton_Xor->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Xor, 0, 2, 1, 1);

        toolButton_Or = new QToolButton(ProgrammerControlPanel);
        toolButton_Or->setObjectName(QStringLiteral("toolButton_Or"));
        sizePolicy3.setHeightForWidth(toolButton_Or->sizePolicy().hasHeightForWidth());
        toolButton_Or->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Or, 0, 1, 1, 1);

        toolButton_Backspace = new QToolButton(ProgrammerControlPanel);
        toolButton_Backspace->setObjectName(QStringLiteral("toolButton_Backspace"));
        sizePolicy3.setHeightForWidth(toolButton_Backspace->sizePolicy().hasHeightForWidth());
        toolButton_Backspace->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Backspace, 1, 3, 1, 1);

        toolButton_B = new QToolButton(ProgrammerControlPanel);
        toolButton_B->setObjectName(QStringLiteral("toolButton_B"));
        sizePolicy3.setHeightForWidth(toolButton_B->sizePolicy().hasHeightForWidth());
        toolButton_B->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_B, 1, 0, 1, 1);

        toolButton_ClearAll = new QToolButton(ProgrammerControlPanel);
        toolButton_ClearAll->setObjectName(QStringLiteral("toolButton_ClearAll"));
        sizePolicy3.setHeightForWidth(toolButton_ClearAll->sizePolicy().hasHeightForWidth());
        toolButton_ClearAll->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_ClearAll, 1, 1, 1, 1);

        toolButton_Clear = new QToolButton(ProgrammerControlPanel);
        toolButton_Clear->setObjectName(QStringLiteral("toolButton_Clear"));
        sizePolicy3.setHeightForWidth(toolButton_Clear->sizePolicy().hasHeightForWidth());
        toolButton_Clear->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Clear, 1, 2, 1, 1);

        toolButton_Div = new QToolButton(ProgrammerControlPanel);
        toolButton_Div->setObjectName(QStringLiteral("toolButton_Div"));
        sizePolicy3.setHeightForWidth(toolButton_Div->sizePolicy().hasHeightForWidth());
        toolButton_Div->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Div, 1, 4, 1, 1);

        toolButton_C = new QToolButton(ProgrammerControlPanel);
        toolButton_C->setObjectName(QStringLiteral("toolButton_C"));
        sizePolicy3.setHeightForWidth(toolButton_C->sizePolicy().hasHeightForWidth());
        toolButton_C->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_C, 2, 0, 1, 1);

        toolButton_8 = new QToolButton(ProgrammerControlPanel);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        sizePolicy3.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_8, 2, 2, 1, 1);

        toolButton_9 = new QToolButton(ProgrammerControlPanel);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        sizePolicy3.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_9, 2, 3, 1, 1);

        toolButton_Mul = new QToolButton(ProgrammerControlPanel);
        toolButton_Mul->setObjectName(QStringLiteral("toolButton_Mul"));
        sizePolicy3.setHeightForWidth(toolButton_Mul->sizePolicy().hasHeightForWidth());
        toolButton_Mul->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Mul, 2, 4, 1, 1);

        toolButton_4 = new QToolButton(ProgrammerControlPanel);
        toolButton_4->setObjectName(QStringLiteral("toolButton_4"));
        sizePolicy3.setHeightForWidth(toolButton_4->sizePolicy().hasHeightForWidth());
        toolButton_4->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_4, 3, 1, 1, 1);

        toolButton_D = new QToolButton(ProgrammerControlPanel);
        toolButton_D->setObjectName(QStringLiteral("toolButton_D"));
        sizePolicy3.setHeightForWidth(toolButton_D->sizePolicy().hasHeightForWidth());
        toolButton_D->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_D, 3, 0, 1, 1);

        toolButton_5 = new QToolButton(ProgrammerControlPanel);
        toolButton_5->setObjectName(QStringLiteral("toolButton_5"));
        sizePolicy3.setHeightForWidth(toolButton_5->sizePolicy().hasHeightForWidth());
        toolButton_5->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_5, 3, 2, 1, 1);

        toolButton_Minus = new QToolButton(ProgrammerControlPanel);
        toolButton_Minus->setObjectName(QStringLiteral("toolButton_Minus"));
        sizePolicy3.setHeightForWidth(toolButton_Minus->sizePolicy().hasHeightForWidth());
        toolButton_Minus->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Minus, 3, 4, 1, 1);

        toolButton_6 = new QToolButton(ProgrammerControlPanel);
        toolButton_6->setObjectName(QStringLiteral("toolButton_6"));
        sizePolicy3.setHeightForWidth(toolButton_6->sizePolicy().hasHeightForWidth());
        toolButton_6->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_6, 3, 3, 1, 1);

        toolButton_E = new QToolButton(ProgrammerControlPanel);
        toolButton_E->setObjectName(QStringLiteral("toolButton_E"));
        sizePolicy3.setHeightForWidth(toolButton_E->sizePolicy().hasHeightForWidth());
        toolButton_E->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_E, 4, 0, 1, 1);

        toolButton_1 = new QToolButton(ProgrammerControlPanel);
        toolButton_1->setObjectName(QStringLiteral("toolButton_1"));
        sizePolicy3.setHeightForWidth(toolButton_1->sizePolicy().hasHeightForWidth());
        toolButton_1->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_1, 4, 1, 1, 1);

        toolButton_Plus = new QToolButton(ProgrammerControlPanel);
        toolButton_Plus->setObjectName(QStringLiteral("toolButton_Plus"));
        sizePolicy3.setHeightForWidth(toolButton_Plus->sizePolicy().hasHeightForWidth());
        toolButton_Plus->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Plus, 4, 4, 1, 1);

        toolButton_2 = new QToolButton(ProgrammerControlPanel);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy3.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_2, 4, 2, 1, 1);

        toolButton_3 = new QToolButton(ProgrammerControlPanel);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy3.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_3, 4, 3, 1, 1);

        toolButton_F = new QToolButton(ProgrammerControlPanel);
        toolButton_F->setObjectName(QStringLiteral("toolButton_F"));
        sizePolicy3.setHeightForWidth(toolButton_F->sizePolicy().hasHeightForWidth());
        toolButton_F->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_F, 5, 0, 1, 1);

        toolButton_0 = new QToolButton(ProgrammerControlPanel);
        toolButton_0->setObjectName(QStringLiteral("toolButton_0"));
        sizePolicy3.setHeightForWidth(toolButton_0->sizePolicy().hasHeightForWidth());
        toolButton_0->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_0, 5, 2, 1, 1);

        toolButton_Sign = new QToolButton(ProgrammerControlPanel);
        toolButton_Sign->setObjectName(QStringLiteral("toolButton_Sign"));
        sizePolicy3.setHeightForWidth(toolButton_Sign->sizePolicy().hasHeightForWidth());
        toolButton_Sign->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Sign, 5, 1, 1, 1);

        toolButton_Dot = new QToolButton(ProgrammerControlPanel);
        toolButton_Dot->setObjectName(QStringLiteral("toolButton_Dot"));
        sizePolicy3.setHeightForWidth(toolButton_Dot->sizePolicy().hasHeightForWidth());
        toolButton_Dot->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Dot, 5, 3, 1, 1);

        toolButton_Enter = new QToolButton(ProgrammerControlPanel);
        toolButton_Enter->setObjectName(QStringLiteral("toolButton_Enter"));
        sizePolicy3.setHeightForWidth(toolButton_Enter->sizePolicy().hasHeightForWidth());
        toolButton_Enter->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_Enter, 5, 4, 1, 1);

        toolButton_7 = new QToolButton(ProgrammerControlPanel);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        sizePolicy3.setHeightForWidth(toolButton_7->sizePolicy().hasHeightForWidth());
        toolButton_7->setSizePolicy(sizePolicy3);

        mainGridLayout->addWidget(toolButton_7, 2, 1, 1, 1);


        verticalLayout_2->addLayout(mainGridLayout);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);

        retranslateUi(ProgrammerControlPanel);

        QMetaObject::connectSlotsByName(ProgrammerControlPanel);
    } // setupUi

    void retranslateUi(QWidget *ProgrammerControlPanel)
    {
        ProgrammerControlPanel->setWindowTitle(QApplication::translate("ProgrammerControlPanel", "ProgrammerControlPanel", 0));
        buttonOct->setText(QApplication::translate("ProgrammerControlPanel", "OCT", 0));
        buttonHex->setText(QApplication::translate("ProgrammerControlPanel", "HEX", 0));
        buttonBin->setText(QApplication::translate("ProgrammerControlPanel", "BIN", 0));
        buttonDec->setText(QApplication::translate("ProgrammerControlPanel", "DEC", 0));
        labelHex->setText(QApplication::translate("ProgrammerControlPanel", "0", 0));
        labelDec->setText(QApplication::translate("ProgrammerControlPanel", "0", 0));
        labelOct->setText(QApplication::translate("ProgrammerControlPanel", "0", 0));
        labelBin->setText(QApplication::translate("ProgrammerControlPanel", "0", 0));
        toolButton_And->setText(QApplication::translate("ProgrammerControlPanel", "And", 0));
        toolButton_A->setText(QApplication::translate("ProgrammerControlPanel", "A", 0));
        toolButton_Not->setText(QApplication::translate("ProgrammerControlPanel", "Not", 0));
        toolButton_Xor->setText(QApplication::translate("ProgrammerControlPanel", "Xor", 0));
        toolButton_Or->setText(QApplication::translate("ProgrammerControlPanel", "Or", 0));
        toolButton_Backspace->setText(QApplication::translate("ProgrammerControlPanel", "back", 0));
        toolButton_B->setText(QApplication::translate("ProgrammerControlPanel", "B", 0));
        toolButton_ClearAll->setText(QApplication::translate("ProgrammerControlPanel", "CA", 0));
        toolButton_Clear->setText(QApplication::translate("ProgrammerControlPanel", "C", 0));
        toolButton_Div->setText(QApplication::translate("ProgrammerControlPanel", "/", 0));
        toolButton_C->setText(QApplication::translate("ProgrammerControlPanel", "C", 0));
        toolButton_8->setText(QApplication::translate("ProgrammerControlPanel", "8", 0));
        toolButton_9->setText(QApplication::translate("ProgrammerControlPanel", "9", 0));
        toolButton_Mul->setText(QApplication::translate("ProgrammerControlPanel", "X", 0));
        toolButton_4->setText(QApplication::translate("ProgrammerControlPanel", "4", 0));
        toolButton_D->setText(QApplication::translate("ProgrammerControlPanel", "D", 0));
        toolButton_5->setText(QApplication::translate("ProgrammerControlPanel", "5", 0));
        toolButton_Minus->setText(QApplication::translate("ProgrammerControlPanel", "-", 0));
        toolButton_6->setText(QApplication::translate("ProgrammerControlPanel", "6", 0));
        toolButton_E->setText(QApplication::translate("ProgrammerControlPanel", "E", 0));
        toolButton_1->setText(QApplication::translate("ProgrammerControlPanel", "1", 0));
        toolButton_Plus->setText(QApplication::translate("ProgrammerControlPanel", "+", 0));
        toolButton_2->setText(QApplication::translate("ProgrammerControlPanel", "2", 0));
        toolButton_3->setText(QApplication::translate("ProgrammerControlPanel", "3", 0));
        toolButton_F->setText(QApplication::translate("ProgrammerControlPanel", "F", 0));
        toolButton_0->setText(QApplication::translate("ProgrammerControlPanel", "0", 0));
        toolButton_Sign->setText(QApplication::translate("ProgrammerControlPanel", "+/-", 0));
        toolButton_Dot->setText(QApplication::translate("ProgrammerControlPanel", ".", 0));
        toolButton_Enter->setText(QApplication::translate("ProgrammerControlPanel", "=", 0));
        toolButton_7->setText(QApplication::translate("ProgrammerControlPanel", "7", 0));
    } // retranslateUi

};

namespace Ui {
    class ProgrammerControlPanel: public Ui_ProgrammerControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRAMMERCONTROLPANEL_H
