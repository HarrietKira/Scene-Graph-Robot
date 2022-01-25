/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "mygl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    MyGL *mygl;
    QTreeWidget *treeWidget;
    QDoubleSpinBox *txSpinBox;
    QDoubleSpinBox *tySpinBox;
    QDoubleSpinBox *rSpinBox;
    QLabel *txLabel;
    QLabel *tyLabel;
    QLabel *rLabel;
    QDoubleSpinBox *sxSpinBox;
    QLabel *sxLabel;
    QDoubleSpinBox *sySpinBox;
    QLabel *syLabel;
    QPushButton *geomSetButton;
    QPushButton *tNodeAddButton;
    QPushButton *rNodeAddButton;
    QPushButton *sNodeAddButton;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QLabel *label;
    QFrame *line_4;
    QFrame *line_5;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 640);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QString::fromUtf8("mygl"));
        mygl->setGeometry(QRect(11, 11, 618, 592));
        mygl->setAutoFillBackground(true);
        treeWidget = new QTreeWidget(centralWidget);
        QBrush brush(QColor(1, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        __qtreewidgetitem->setForeground(0, brush);
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(640, 310, 301, 291));
        QFont font;
        font.setFamilies({QString::fromUtf8("Chalkboard")});
        font.setBold(true);
        treeWidget->setFont(font);
        txSpinBox = new QDoubleSpinBox(centralWidget);
        txSpinBox->setObjectName(QString::fromUtf8("txSpinBox"));
        txSpinBox->setGeometry(QRect(730, 20, 62, 22));
        txSpinBox->setFont(font);
        txSpinBox->setMinimum(-10.000000000000000);
        txSpinBox->setMaximum(10.000000000000000);
        txSpinBox->setSingleStep(0.100000000000000);
        tySpinBox = new QDoubleSpinBox(centralWidget);
        tySpinBox->setObjectName(QString::fromUtf8("tySpinBox"));
        tySpinBox->setGeometry(QRect(730, 50, 62, 22));
        tySpinBox->setFont(font);
        tySpinBox->setMinimum(-10.000000000000000);
        tySpinBox->setMaximum(10.000000000000000);
        tySpinBox->setSingleStep(0.100000000000000);
        rSpinBox = new QDoubleSpinBox(centralWidget);
        rSpinBox->setObjectName(QString::fromUtf8("rSpinBox"));
        rSpinBox->setGeometry(QRect(730, 110, 62, 22));
        rSpinBox->setFont(font);
        rSpinBox->setMinimum(-180.000000000000000);
        rSpinBox->setMaximum(180.000000000000000);
        rSpinBox->setSingleStep(1.000000000000000);
        txLabel = new QLabel(centralWidget);
        txLabel->setObjectName(QString::fromUtf8("txLabel"));
        txLabel->setGeometry(QRect(640, 20, 71, 16));
        txLabel->setFont(font);
        tyLabel = new QLabel(centralWidget);
        tyLabel->setObjectName(QString::fromUtf8("tyLabel"));
        tyLabel->setGeometry(QRect(640, 50, 71, 16));
        tyLabel->setFont(font);
        rLabel = new QLabel(centralWidget);
        rLabel->setObjectName(QString::fromUtf8("rLabel"));
        rLabel->setGeometry(QRect(640, 110, 61, 16));
        rLabel->setFont(font);
        sxSpinBox = new QDoubleSpinBox(centralWidget);
        sxSpinBox->setObjectName(QString::fromUtf8("sxSpinBox"));
        sxSpinBox->setGeometry(QRect(730, 180, 62, 22));
        sxSpinBox->setFont(font);
        sxSpinBox->setMinimum(-5.000000000000000);
        sxSpinBox->setMaximum(5.000000000000000);
        sxSpinBox->setSingleStep(0.100000000000000);
        sxLabel = new QLabel(centralWidget);
        sxLabel->setObjectName(QString::fromUtf8("sxLabel"));
        sxLabel->setGeometry(QRect(640, 180, 61, 16));
        sxLabel->setFont(font);
        sySpinBox = new QDoubleSpinBox(centralWidget);
        sySpinBox->setObjectName(QString::fromUtf8("sySpinBox"));
        sySpinBox->setGeometry(QRect(730, 210, 62, 22));
        sySpinBox->setFont(font);
        sySpinBox->setMinimum(-5.000000000000000);
        sySpinBox->setMaximum(5.000000000000000);
        sySpinBox->setSingleStep(0.100000000000000);
        syLabel = new QLabel(centralWidget);
        syLabel->setObjectName(QString::fromUtf8("syLabel"));
        syLabel->setGeometry(QRect(640, 210, 61, 16));
        syLabel->setFont(font);
        geomSetButton = new QPushButton(centralWidget);
        geomSetButton->setObjectName(QString::fromUtf8("geomSetButton"));
        geomSetButton->setGeometry(QRect(810, 260, 131, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Chalkboard")});
        font1.setPointSize(13);
        font1.setBold(true);
        geomSetButton->setFont(font1);
        tNodeAddButton = new QPushButton(centralWidget);
        tNodeAddButton->setObjectName(QString::fromUtf8("tNodeAddButton"));
        tNodeAddButton->setGeometry(QRect(810, 40, 131, 31));
        tNodeAddButton->setFont(font1);
        rNodeAddButton = new QPushButton(centralWidget);
        rNodeAddButton->setObjectName(QString::fromUtf8("rNodeAddButton"));
        rNodeAddButton->setGeometry(QRect(810, 110, 131, 31));
        rNodeAddButton->setFont(font1);
        sNodeAddButton = new QPushButton(centralWidget);
        sNodeAddButton->setObjectName(QString::fromUtf8("sNodeAddButton"));
        sNodeAddButton->setGeometry(QRect(810, 190, 131, 31));
        sNodeAddButton->setFont(font1);
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(640, 80, 301, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(640, 150, 301, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(640, 240, 301, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 270, 221, 16));
        label->setFont(font1);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(637, 290, 301, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(637, 0, 301, 20));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 952, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Scene Graph", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        txLabel->setText(QCoreApplication::translate("MainWindow", "Translate X", nullptr));
        tyLabel->setText(QCoreApplication::translate("MainWindow", "Translate Y", nullptr));
        rLabel->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        sxLabel->setText(QCoreApplication::translate("MainWindow", "Scale X", nullptr));
        syLabel->setText(QCoreApplication::translate("MainWindow", "Scale Y", nullptr));
        geomSetButton->setText(QCoreApplication::translate("MainWindow", "Set Geometry", nullptr));
        tNodeAddButton->setText(QCoreApplication::translate("MainWindow", "Add Translate Node", nullptr));
        rNodeAddButton->setText(QCoreApplication::translate("MainWindow", "Add Rotate Node", nullptr));
        sNodeAddButton->setText(QCoreApplication::translate("MainWindow", "Add Scale Node", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Add Geometry shape ", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
