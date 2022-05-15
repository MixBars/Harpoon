/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralwidget;
    QListView *lvDir;
    QPushButton *pushButton;
    QTextEdit *settings;
    QPushButton *saveBackup;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *currentConf;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QTextEdit *settings_2;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1824, 652);
        QIcon icon;
        icon.addFile(QString::fromUtf8("pics/2332239.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1.000000000000000);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lvDir = new QListView(centralwidget);
        lvDir->setObjectName(QString::fromUtf8("lvDir"));
        lvDir->setGeometry(QRect(10, 30, 256, 541));
        lvDir->setInputMethodHints(Qt::ImhNone);
        lvDir->setEditTriggers(QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(270, 580, 165, 25));
        settings = new QTextEdit(centralwidget);
        settings->setObjectName(QString::fromUtf8("settings"));
        settings->setGeometry(QRect(270, 30, 761, 541));
        saveBackup = new QPushButton(centralwidget);
        saveBackup->setObjectName(QString::fromUtf8("saveBackup"));
        saveBackup->setGeometry(QRect(470, 580, 111, 25));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(620, 580, 177, 25));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(830, 580, 175, 25));
        currentConf = new QLabel(centralwidget);
        currentConf->setObjectName(QString::fromUtf8("currentConf"));
        currentConf->setGeometry(QRect(450, 10, 271, 17));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 10, 109, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 10, 157, 17));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(1040, 6, 231, 20));
        settings_2 = new QTextEdit(centralwidget);
        settings_2->setObjectName(QString::fromUtf8("settings_2"));
        settings_2->setEnabled(false);
        settings_2->setGeometry(QRect(1040, 30, 761, 541));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1824, 19));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Harpoon", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\320\271...", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\270\321\200\320\265\320\272\321\202\320\276\321\200\320\270\321\216 \320\264\320\273\321\217 \321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\321\205 \321\204\320\260\320\271\320\273\320\276\320\262...", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        saveBackup->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \320\261\321\215\320\272\320\260\320\277", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\270\320\267 \320\261\321\215\320\272\320\260\320\277\320\260", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\270\321\201\321\205\320\276\320\264\320\275\321\213\320\271", nullptr));
        currentConf->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\321\217 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\321\213\320\271 \320\261\321\215\320\272\320\260\320\277", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\275\321\213\320\271 \320\270\321\201\321\205\320\276\320\264\320\275\320\270\320\272", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
