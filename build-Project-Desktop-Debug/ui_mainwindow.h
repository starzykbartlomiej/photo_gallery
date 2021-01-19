/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFilters;
    QAction *actionAlbums;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_picture;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listImages;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbRotate;
    QPushButton *pbBack;
    QPushButton *pbSlideShow;
    QPushButton *pbNext;
    QPushButton *pbExit;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(935, 536);
        actionFilters = new QAction(MainWindow);
        actionFilters->setObjectName(QStringLiteral("actionFilters"));
        actionAlbums = new QAction(MainWindow);
        actionAlbums->setObjectName(QStringLiteral("actionAlbums"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_1 = new QWidget();
        page_1->setObjectName(QStringLiteral("page_1"));
        verticalLayout_2 = new QVBoxLayout(page_1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_picture = new QLabel(page_1);
        label_picture->setObjectName(QStringLiteral("label_picture"));

        verticalLayout_2->addWidget(label_picture);

        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_3 = new QVBoxLayout(page_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listImages = new QListWidget(page_2);
        listImages->setObjectName(QStringLiteral("listImages"));

        verticalLayout_3->addWidget(listImages);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pbRotate = new QPushButton(centralwidget);
        pbRotate->setObjectName(QStringLiteral("pbRotate"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbRotate->sizePolicy().hasHeightForWidth());
        pbRotate->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbRotate);

        pbBack = new QPushButton(centralwidget);
        pbBack->setObjectName(QStringLiteral("pbBack"));
        sizePolicy1.setHeightForWidth(pbBack->sizePolicy().hasHeightForWidth());
        pbBack->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbBack);

        pbSlideShow = new QPushButton(centralwidget);
        pbSlideShow->setObjectName(QStringLiteral("pbSlideShow"));
        sizePolicy1.setHeightForWidth(pbSlideShow->sizePolicy().hasHeightForWidth());
        pbSlideShow->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbSlideShow);

        pbNext = new QPushButton(centralwidget);
        pbNext->setObjectName(QStringLiteral("pbNext"));
        sizePolicy1.setHeightForWidth(pbNext->sizePolicy().hasHeightForWidth());
        pbNext->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbNext);

        pbExit = new QPushButton(centralwidget);
        pbExit->setObjectName(QStringLiteral("pbExit"));
        sizePolicy1.setHeightForWidth(pbExit->sizePolicy().hasHeightForWidth());
        pbExit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbExit);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 935, 20));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionFilters);
        menuOptions->addAction(actionAlbums);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionFilters->setText(QApplication::translate("MainWindow", "Filters", Q_NULLPTR));
        actionAlbums->setText(QApplication::translate("MainWindow", "Albums", Q_NULLPTR));
        label_picture->setText(QString());
        pbRotate->setText(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
        pbBack->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        pbSlideShow->setText(QApplication::translate("MainWindow", "Slide show", Q_NULLPTR));
        pbNext->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        pbExit->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
