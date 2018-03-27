#include "stdafx.h"
#include "DualModeCalculator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    // HDS supporting, requires Qt >= 5.6
#if (QT_VERSION >=QT_VERSION_CHECK(5, 6, 0))
    //QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    // Set font
    QFont font("Microsoft YaHei");
    font.setStyleStrategy(QFont::NoAntialias);
    font.setStyleHint(QFont::Helvetica);
    QApplication::setFont(font);

    QApplication a(argc, argv);
    DualModeCalculator w;
    w.show();
    return a.exec();
}
