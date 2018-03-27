#include "stdafx.h"
#include "QAutoFontSizeLabel.h"

#include <QBoxLayout>
#include <QFrame>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QStyle>

using namespace std;

QRect QAutoFontSizeLabel::documentRect()
{
    QRect rect = contentsRect();
    int m = margin(); rect.adjust(m, m, -m, -m);
    layoutDirection();
    const int align
        = QStyle::visualAlignment(layoutDirection(), QLabel::alignment());
    int i = indent();
    if (i < 0 && frameWidth()) { // no indent, but we do have a frame
        m = fontMetrics().width(QLatin1Char('x')) / 2 - m;
    }
    if (m > 0) {
        if (align & Qt::AlignLeft) rect.setLeft(rect.left() + m);
        if (align & Qt::AlignRight) rect.setRight(rect.right() - m);
        if (align & Qt::AlignTop) rect.setTop(rect.top() + m);
        if (align & Qt::AlignBottom) rect.setBottom(rect.bottom() - m);
    }
    return rect;
}

void QAutoFontSizeLabel::layout()
{
    // get initial settings
    QString text = this->text();
    QRect rectLbl = documentRect(); // wrong: contentsRect();
    QFont font = this->font();
    int size = font.pointSize();
    QFontMetrics fontMetrics(font);
    QRect rect = fontMetrics.boundingRect(rectLbl,
        Qt::TextWordWrap, text);
    // decide whether to increase or decrease
    int step = rect.height() > rectLbl.height() ? -1 : 1;
    // iterate until text fits best into rectangle of label
    for (;;) {
        font.setPointSize(size + step);
        QFontMetrics fontMetrics(font);
        rect = fontMetrics.boundingRect(rectLbl,
            Qt::TextWordWrap, text);
        if (size <= 1) {
            qDebug() << "QAutoFontSizeLabel: font cannot be made smaller!" << endl;
            break;
        }
        if (step < 0) {
            size += step;
            if (rect.height() < rectLbl.height()) break;
        }
        else {
            if (rect.height() > rectLbl.height()) break;
            size += step;
        }
    }
    // apply result of iteration
    font.setPointSize(size);
    setFont(font);
}

void QAutoFontSizeLabel::resizeEvent(QResizeEvent *pQEvent)
{
    QLabel::resizeEvent(pQEvent);
    layout();
}