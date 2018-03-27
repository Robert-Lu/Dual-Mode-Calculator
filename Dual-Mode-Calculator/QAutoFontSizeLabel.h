#pragma once

#include <QLabel>

class QAutoFontSizeLabel : public QLabel {

    Q_OBJECT

public:
    void layout();
    QRect documentRect(); // borrowed from QLabelPrivate
protected:
    virtual void resizeEvent(QResizeEvent *pQEvent);
};