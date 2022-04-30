#include <bits/stdc++.h>
#include <QDebug>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QComboBox>
#include <QListWidget>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDial>
#include <QStackedLayout>
#include "Color.h"
#include "Window4.h"
#include "Window5.h"

Window::Window (QWidget *parent)
  {
    setWindowTitle("My App");
//    auto *widget = new QLabel("Hello");

//    auto font = widget->font();
//    font.setPointSize(30);
//    widget->setFont(font);
//    widget->setAlignment(Qt::AlignmentFlag::AlignHCenter | Qt::AlignmentFlag::AlignVCenter);

//    widget->setPixmap(QPixmap("../otje.jpg"));
//    widget->setScaledContents(true);

//    auto *widget = new QCheckBox("This is a checkbox");
//    widget->setCheckState(Qt::CheckState::Checked);

//    connect(widget, &QCheckBox::stateChanged, this, show_state);

//    widget->stateChanged.connect(self.show_state)

//    auto *widget = new QComboBox();
//    auto *widget = new QListWidget();
//    widget->addItems({ "One", "Two", "Three" });
////    widget->setEditable(true);
//    widget->setInsertPolicy(QComboBox::InsertPolicy::InsertAlphabetically);
//    widget->setMaxCount(3);

//    connect(widget, &QListWidget::currentItemChanged, this, item_changed);
//    connect(widget, &QListWidget::currentTextChanged, this, text_changed);

//    widget = new QLineEdit();
//    widget->setInputMask("000.000.000.000;_");
//
//    widget->setMaxLength(10);
//    widget->setPlaceholderText("Enter your text");

    // widget->setReadOnly(True) // uncomment this to make readonly

//    connect(widget, &QLineEdit::returnPressed, this, return_pressed);



//    connect(widget, SIGNAL(returnPressed()), this, SLOT(return_pressed()));
//    connect(widget, &QLineEdit::selectionChanged, this, selection_changed);

//    connect(widget, &QLineEdit::returnPressed, [this] ()
//      {
//          return_pressed();
//      });
//    connect(widget, &QLineEdit::selectionChanged, [this] ()
//      {
//          selection_changed();
//      });
//    connect(widget, &QLineEdit::textChanged, this, text_changed);

//    widget.returnPressed.connect(self.return_pressed)
//    widget.selectionChanged.connect(self.selection_changed)
//    widget.textChanged.connect(self.text_changed)


//    auto *widget = new QSpinBox();
////    auto *widget = new QDoubleSpinBox();
//    widget->setMinimum(-10);
//    widget->setMaximum(3);
//    // widget->setRange(-10,3);
//    widget->setPrefix("$");
//    widget->setSuffix("c");
//    widget->setSingleStep(3); // Or e.g. 0.5 for QDoubleSpinBox
//    connect(widget, &QSpinBox::valueChanged, this, value_changed);
//    connect(widget, &QSpinBox::textChanged, this, value_changed_str);
//    widget.valueChanged.connect(self.value_changed)
//    widget.textChanged.connect(self.value_changed_str)

//    auto *widget = new QSlider(Qt::Orientation::Horizontal);
//    widget->setMinimum(-10);
//    widget->setMaximum(3);
//    //# Or: widget.setRange(-10,3)
//    widget->setSingleStep(3);

//    auto *widget = new QDial();
//    widget->setRange(-10, 100);
//    widget->setSingleStep(1);
//
//
//    connect(widget, &QSlider::valueChanged, this, value_changed);
//    connect(widget, &QSlider::sliderMoved, this, slider_position);
//    connect(widget, &QSlider::sliderPressed, this, slider_pressed);
//    connect(widget, &QSlider::sliderReleased, this, slider_released);






//    widget.valueChanged.connect(self.value_changed)
//    widget.sliderMoved.connect(self.slider_position)
//    widget.sliderPressed.connect(self.slider_pressed)
//    widget.sliderReleased.connect(self.slider_released)

//    auto *widget = new Color(this, "Red");

//    auto *layout = new QVBoxLayout();
//    layout->addWidget(new Color(this, "red"));
//    layout->addWidget(new Color(this, "green"));
//    layout->addWidget(new Color(this, "blue"));
//    auto *widget = new QWidget();
//    widget->setLayout(layout);

//    auto *layout1 = new QHBoxLayout();
//    auto *layout2 = new QVBoxLayout();
//    auto *layout3 = new QVBoxLayout();
//
//    layout2->addWidget(new Color(this, "red"));
//    layout2->addWidget(new Color(this, "yellow"));
//    layout2->addWidget(new Color(this, "purple"));
//
//    layout1->addLayout(layout2);
//
//    layout1->addWidget(new Color(this, "green"));
//    layout3->addWidget(new Color(this, "red"));
//    layout3->addWidget(new Color(this, "purple"));
//
//    layout1->addLayout(layout3);
//
//    layout1->setContentsMargins(0,0,0,0);
//    layout1->setSpacing(20);
//
//    auto *widget = new QWidget();
//    widget->setLayout(layout1);

//    auto *layout = new QGridLayout();
//    layout->addWidget(new Color(this, "red"), 0, 0);
//    layout->addWidget(new Color(this, "green"), 1, 0);
//    layout->addWidget(new Color(this, "blue"), 1, 1);
//    layout->addWidget(new Color(this, "purple"), 2, 1);
//    auto *widget = new QWidget();
//    widget->setLayout(layout);

//    auto *layout = new QStackedLayout();
//
//    layout->addWidget(new Color(this, "red"));
//    layout->addWidget(new Color(this, "green"));
//    layout->addWidget(new Color(this, "blue"));
//    layout->addWidget(new Color(this, "yellow"));
//
//    layout->setCurrentIndex(3);
//
//    auto *widget = new QWidget();
//    widget->setLayout(layout);


//    auto *pagelayout = new QVBoxLayout();
//    auto *button_layout = new QHBoxLayout();
//    stacklayout = new QStackedLayout();
//
//    pagelayout->addLayout(button_layout);
//    pagelayout->addLayout(stacklayout);
//
//    auto *btn1 = new QPushButton("red");
//    connect(btn1, &QPushButton::pressed, [this](){
//          activate_tab_1();
//    });
//    button_layout->addWidget(btn1);
//    stacklayout->addWidget(new Color("red"));
//
//    auto *btn2 = new QPushButton("green");
//    connect(btn2, &QPushButton::pressed, this, [this](){
//          activate_tab_2();
//      });
//    button_layout->addWidget(btn2);
//    stacklayout->addWidget(new Color("green"));
//
//    auto *btn3 = new QPushButton("yellow");
//    connect(btn3, &QPushButton::pressed, this, [this](){
//          activate_tab_3();
//      });
//    button_layout->addWidget(btn3);
//    stacklayout->addWidget(new Color("yellow"));
//
//    auto *widget = new QWidget();
//    widget->setLayout(pagelayout);
//    setCentralWidget(widget);


    auto *tabs = new QTabWidget();
    tabs->setTabPosition(QTabWidget::TabPosition::West);
    tabs->setMovable(true);
//    for n, color in enumerate(["red", "green", "blue", "yellow"]):

    std::vector<QString> colors { "Red", "Green", "Blue", "Yellow" };

    for (auto &color: colors)
      {
        tabs->addTab(new Color(color.toLower()), color);
      }

    setCentralWidget(tabs);

  }

void Window::index_changed (int index)
  {
    qDebug() << "index:" << index; // print(i)# i is an int
  }

void Window::text_changed (const QString &text)
  {
    qDebug() << "text:" << text;
  }

void Window::show_state (int state)
  {
    qDebug() << ( int(Qt::CheckState(state)) == int(Qt::CheckState::Checked) );
    qDebug() << state;
  }

void Window::item_changed (QListWidgetItem *current, QListWidgetItem *previous)
  {
    qDebug() << "current:" << current->text();

    if (previous)
      {
        qDebug() << "previous:" << previous->text();
      }
  }

void Window::return_pressed ()
  {
    qDebug() << "Return pressed";
    widget->setText("BOOM!");
  }

void Window::selection_changed ()
  {
    qDebug() << "selection_changed:" << widget->selectedText();
  }

void Window::value_changed (int value)
  {
    qDebug() << "value:" << value;
  }

void Window::value_changed_str (const QString &text_value)
  {
    qDebug() << "value_string:" << text_value;
  }

void Window::slider_position (int position)
  {
    qDebug() << "Position: " << position;
  }

void Window::slider_pressed ()
  {
    qDebug() << "Pressed!";
  }

void Window::slider_released ()
  {
    qDebug() << "Released";
  }

void Window::activate_tab_1 ()
  {
    stacklayout->setCurrentIndex(0);
  }

void Window::activate_tab_2 ()
  {
    stacklayout->setCurrentIndex(1);
  }

void Window::activate_tab_3 ()
  {
    stacklayout->setCurrentIndex(2);
  }

Window::~Window ()
= default;

