#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DualModeCalculator.h"
#include "QAutoFontSizeLabel.h"
#include "StandardControlPanel.h"
#include "ProgrammerControlPanel.h"

class DualModeCalculator : public QMainWindow
{
    Q_OBJECT

public:
    DualModeCalculator(QWidget *parent = Q_NULLPTR);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::DualModeCalculatorClass ui;

    void InitialSetGUI();
    void ConnectActions();
    void InitialzeComponents();
    void UpdateGUI();
    void AdjustFontSize();

    enum Mode
    {
        StandardMode, ProgrammerMode
    };
    Mode mode;
    bool show_history;

    // test
    QLabel *test_Std, *test_Pro, *test_His;

    QAutoFontSizeLabel *labelMode, *labelNumberDisplay;
    StandardControlPanel *stdControlPanel;
    ProgrammerControlPanel *proControlPanel;
};
