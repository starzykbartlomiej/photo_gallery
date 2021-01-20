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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFilters;
    QAction *actionAlbums;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QStackedWidget *stackedWidget_2;
    QWidget *page_0_front;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_images;
    QVBoxLayout *verticalLayout_6;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_picture;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listImages;
    QWidget *tab_albums;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbRotate;
    QPushButton *pbBack;
    QPushButton *pbSlidesShow;
    QPushButton *pbNext;
    QPushButton *pbExit;
    QSpacerItem *horizontalSpacer;
    QWidget *page_1_front;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbFullScreenExit;
    QSpacerItem *horizontalSpacer_3;
    QLabel *labelSlide;
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
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        stackedWidget_2 = new QStackedWidget(centralwidget);
        stackedWidget_2->setObjectName(QStringLiteral("stackedWidget_2"));
        page_0_front = new QWidget();
        page_0_front->setObjectName(QStringLiteral("page_0_front"));
        verticalLayout = new QVBoxLayout(page_0_front);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(page_0_front);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab_images = new QWidget();
        tab_images->setObjectName(QStringLiteral("tab_images"));
        verticalLayout_6 = new QVBoxLayout(tab_images);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        stackedWidget = new QStackedWidget(tab_images);
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
        listImages->setMovement(QListView::Static);

        verticalLayout_3->addWidget(listImages);

        stackedWidget->addWidget(page_2);

        verticalLayout_6->addWidget(stackedWidget);

        tabWidget->addTab(tab_images, QString());
        tab_albums = new QWidget();
        tab_albums->setObjectName(QStringLiteral("tab_albums"));
        tabWidget->addTab(tab_albums, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pbRotate = new QPushButton(page_0_front);
        pbRotate->setObjectName(QStringLiteral("pbRotate"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbRotate->sizePolicy().hasHeightForWidth());
        pbRotate->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbRotate);

        pbBack = new QPushButton(page_0_front);
        pbBack->setObjectName(QStringLiteral("pbBack"));
        sizePolicy1.setHeightForWidth(pbBack->sizePolicy().hasHeightForWidth());
        pbBack->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbBack);

        pbSlidesShow = new QPushButton(page_0_front);
        pbSlidesShow->setObjectName(QStringLiteral("pbSlidesShow"));
        sizePolicy1.setHeightForWidth(pbSlidesShow->sizePolicy().hasHeightForWidth());
        pbSlidesShow->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbSlidesShow);

        pbNext = new QPushButton(page_0_front);
        pbNext->setObjectName(QStringLiteral("pbNext"));
        sizePolicy1.setHeightForWidth(pbNext->sizePolicy().hasHeightForWidth());
        pbNext->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbNext);

        pbExit = new QPushButton(page_0_front);
        pbExit->setObjectName(QStringLiteral("pbExit"));
        sizePolicy1.setHeightForWidth(pbExit->sizePolicy().hasHeightForWidth());
        pbExit->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pbExit);

        horizontalSpacer = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget_2->addWidget(page_0_front);
        page_1_front = new QWidget();
        page_1_front->setObjectName(QStringLiteral("page_1_front"));
        verticalLayout_5 = new QVBoxLayout(page_1_front);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pbFullScreenExit = new QPushButton(page_1_front);
        pbFullScreenExit->setObjectName(QStringLiteral("pbFullScreenExit"));

        horizontalLayout_2->addWidget(pbFullScreenExit);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_2);

        labelSlide = new QLabel(page_1_front);
        labelSlide->setObjectName(QStringLiteral("labelSlide"));

        verticalLayout_5->addWidget(labelSlide);

        verticalLayout_5->setStretch(1, 10);
        stackedWidget_2->addWidget(page_1_front);

        verticalLayout_4->addWidget(stackedWidget_2);

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

        retranslateUi(MainWindow);

        stackedWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Photo Gallery", Q_NULLPTR));
        actionFilters->setText(QApplication::translate("MainWindow", "Filters", Q_NULLPTR));
        actionAlbums->setText(QApplication::translate("MainWindow", "Albums", Q_NULLPTR));
        label_picture->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_images), QApplication::translate("MainWindow", "Images", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_albums), QApplication::translate("MainWindow", "Albums", Q_NULLPTR));
        pbRotate->setText(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
        pbBack->setText(QApplication::translate("MainWindow", "<", Q_NULLPTR));
        pbSlidesShow->setText(QApplication::translate("MainWindow", "Slides show", Q_NULLPTR));
        pbNext->setText(QApplication::translate("MainWindow", ">", Q_NULLPTR));
        pbExit->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        pbFullScreenExit->setText(QApplication::translate("MainWindow", "x", Q_NULLPTR));
        labelSlide->setText(QString());
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
