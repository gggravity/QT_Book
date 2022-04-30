#include <bits/stdc++.h>
#include <QApplication>
#include <QPalette>
#include <QLabel>
#include <QPushButton>
#include <QStyle>

using namespace std;

int main (int argc, char *argv[])
try
  {
    QApplication app(argc, argv);
//    QApplication::setStyle("Fusion");

//    auto palette = QPalette();
//    palette.setColor(QPalette::ColorRole::Window, QColor(0, 128, 255));
//    palette.setColor(QPalette::ColorRole::WindowText, Qt::GlobalColor::white);
//    QApplication::setPalette(palette);

    auto darkPalette = QPalette();
    darkPalette.setColor(QPalette::ColorRole::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ColorRole::WindowText, Qt::GlobalColor::white);
    darkPalette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::WindowText, QColor(127, 127, 127));
    darkPalette.setColor(QPalette::ColorRole::Base, QColor(42, 42, 42));
    darkPalette.setColor(QPalette::ColorRole::AlternateBase, QColor(66, 66, 66));
    darkPalette.setColor(QPalette::ColorRole::ToolTipBase, Qt::GlobalColor::white);
    darkPalette.setColor(QPalette::ColorRole::ToolTipText, Qt::GlobalColor::white);
    darkPalette.setColor(QPalette::ColorRole::Text, Qt::GlobalColor::white);
    darkPalette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Text, QColor(127, 127, 127));
    darkPalette.setColor(QPalette::ColorRole::Dark, QColor(35, 35, 35));
    darkPalette.setColor(QPalette::ColorRole::Shadow, QColor(20, 20, 20));
    darkPalette.setColor(QPalette::ColorRole::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ColorRole::ButtonText, Qt::GlobalColor::white);

    darkPalette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::ButtonText, QColor(127, 127, 127));
    darkPalette.setColor(QPalette::ColorRole::BrightText, Qt::GlobalColor::red);
    darkPalette.setColor(QPalette::ColorRole::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::ColorRole::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::Highlight, QColor(80, 80, 80));
    darkPalette.setColor(QPalette::ColorRole::HighlightedText, Qt::GlobalColor::white);
    darkPalette.setColor(QPalette::ColorGroup::Disabled, QPalette::ColorRole::HighlightedText, QColor(127, 127, 127));
//    QApplication::setPalette(darkPalette);

    auto window = QLabel("Palette Test");

    auto button = QPushButton("My Button");
    auto style = button.style(); // Get the QStyle object from the widget.
    auto icon = style->standardIcon(style->SP_ArrowBack);
    button.setIcon(icon);
    button.show();

    window.resize(800, 600);
    window.show();

    return QApplication::exec();
  }
catch (exception &e)
  {
    cerr << "Error: " << e.what() << endl;
  }


