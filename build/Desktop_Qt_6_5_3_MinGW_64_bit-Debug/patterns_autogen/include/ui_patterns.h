/********************************************************************************
** Form generated from reading UI file 'patterns.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATTERNS_H
#define UI_PATTERNS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_patterns
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *taskTable;
    QHBoxLayout *buttonLayout;
    QPushButton *addTaskButton;
    QPushButton *removeTaskButton;
    QPushButton *markCompleteButton;
    QPushButton *importTasksButton;
    QPushButton *saveTasksButton;
    QFormLayout *addTaskLayout;
    QLabel *taskNameLabel;
    QLineEdit *taskNameInput;
    QLabel *categoryLabel;
    QComboBox *categoryInput;
    QLabel *priorityLabel;
    QLabel *dueDateLabel;
    QDateEdit *dueDateInput;
    QComboBox *priorityInput;
    QLabel *saveFormatLabel;
    QComboBox *saveFormatInput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *patterns)
    {
        if (patterns->objectName().isEmpty())
            patterns->setObjectName("patterns");
        patterns->resize(800, 600);
        centralwidget = new QWidget(patterns);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        taskTable = new QTableView(centralwidget);
        taskTable->setObjectName("taskTable");

        verticalLayout->addWidget(taskTable);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        addTaskButton = new QPushButton(centralwidget);
        addTaskButton->setObjectName("addTaskButton");

        buttonLayout->addWidget(addTaskButton);

        removeTaskButton = new QPushButton(centralwidget);
        removeTaskButton->setObjectName("removeTaskButton");

        buttonLayout->addWidget(removeTaskButton);

        markCompleteButton = new QPushButton(centralwidget);
        markCompleteButton->setObjectName("markCompleteButton");

        buttonLayout->addWidget(markCompleteButton);

        importTasksButton = new QPushButton(centralwidget);
        importTasksButton->setObjectName("importTasksButton");

        buttonLayout->addWidget(importTasksButton);

        saveTasksButton = new QPushButton(centralwidget);
        saveTasksButton->setObjectName("saveTasksButton");

        buttonLayout->addWidget(saveTasksButton);


        verticalLayout->addLayout(buttonLayout);

        addTaskLayout = new QFormLayout();
        addTaskLayout->setObjectName("addTaskLayout");
        taskNameLabel = new QLabel(centralwidget);
        taskNameLabel->setObjectName("taskNameLabel");

        addTaskLayout->setWidget(0, QFormLayout::LabelRole, taskNameLabel);

        taskNameInput = new QLineEdit(centralwidget);
        taskNameInput->setObjectName("taskNameInput");

        addTaskLayout->setWidget(0, QFormLayout::FieldRole, taskNameInput);

        categoryLabel = new QLabel(centralwidget);
        categoryLabel->setObjectName("categoryLabel");

        addTaskLayout->setWidget(1, QFormLayout::LabelRole, categoryLabel);

        categoryInput = new QComboBox(centralwidget);
        categoryInput->addItem(QString());
        categoryInput->addItem(QString());
        categoryInput->addItem(QString());
        categoryInput->addItem(QString());
        categoryInput->addItem(QString());
        categoryInput->addItem(QString());
        categoryInput->addItem(QString());
        categoryInput->setObjectName("categoryInput");

        addTaskLayout->setWidget(1, QFormLayout::FieldRole, categoryInput);

        priorityLabel = new QLabel(centralwidget);
        priorityLabel->setObjectName("priorityLabel");

        addTaskLayout->setWidget(2, QFormLayout::LabelRole, priorityLabel);

        dueDateLabel = new QLabel(centralwidget);
        dueDateLabel->setObjectName("dueDateLabel");

        addTaskLayout->setWidget(3, QFormLayout::LabelRole, dueDateLabel);

        dueDateInput = new QDateEdit(centralwidget);
        dueDateInput->setObjectName("dueDateInput");
        dueDateInput->setCalendarPopup(true);

        addTaskLayout->setWidget(3, QFormLayout::FieldRole, dueDateInput);

        priorityInput = new QComboBox(centralwidget);
        priorityInput->addItem(QString());
        priorityInput->addItem(QString());
        priorityInput->addItem(QString());
        priorityInput->setObjectName("priorityInput");

        addTaskLayout->setWidget(2, QFormLayout::FieldRole, priorityInput);

        saveFormatLabel = new QLabel(centralwidget);
        saveFormatLabel->setObjectName("saveFormatLabel");

        addTaskLayout->setWidget(4, QFormLayout::LabelRole, saveFormatLabel);

        saveFormatInput = new QComboBox(centralwidget);
        saveFormatInput->addItem(QString());
        saveFormatInput->addItem(QString());
        saveFormatInput->setObjectName("saveFormatInput");

        addTaskLayout->setWidget(4, QFormLayout::FieldRole, saveFormatInput);


        verticalLayout->addLayout(addTaskLayout);

        patterns->setCentralWidget(centralwidget);
        menubar = new QMenuBar(patterns);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        patterns->setMenuBar(menubar);
        statusbar = new QStatusBar(patterns);
        statusbar->setObjectName("statusbar");
        patterns->setStatusBar(statusbar);

        retranslateUi(patterns);

        QMetaObject::connectSlotsByName(patterns);
    } // setupUi

    void retranslateUi(QMainWindow *patterns)
    {
        patterns->setWindowTitle(QCoreApplication::translate("patterns", "To-Do List", nullptr));
        taskTable->setProperty("horizontalHeaderLabels", QVariant(QStringList{
            QCoreApplication::translate("patterns", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr),
            QCoreApplication::translate("patterns", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr),
            QCoreApplication::translate("patterns", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202", nullptr),
            QCoreApplication::translate("patterns", "\320\241\321\200\320\276\320\272", nullptr),
            QCoreApplication::translate("patterns", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr)}));
        addTaskButton->setText(QCoreApplication::translate("patterns", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        removeTaskButton->setText(QCoreApplication::translate("patterns", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        markCompleteButton->setText(QCoreApplication::translate("patterns", "\320\236\321\202\320\274\320\265\321\202\320\270\321\202\321\214 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\275\320\276\320\271", nullptr));
        importTasksButton->setText(QCoreApplication::translate("patterns", "\320\230\320\274\320\277\320\276\321\200\321\202 \320\267\320\260\320\264\320\260\321\207", nullptr));
        saveTasksButton->setText(QCoreApplication::translate("patterns", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        taskNameLabel->setText(QCoreApplication::translate("patterns", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        categoryLabel->setText(QCoreApplication::translate("patterns", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", nullptr));
        categoryInput->setItemText(0, QCoreApplication::translate("patterns", "\320\264\320\276\320\274", nullptr));
        categoryInput->setItemText(1, QCoreApplication::translate("patterns", "\321\200\320\260\320\261\320\276\321\202\320\260", nullptr));
        categoryInput->setItemText(2, QCoreApplication::translate("patterns", "\321\201\320\265\320\274\321\214\321\217", nullptr));
        categoryInput->setItemText(3, QCoreApplication::translate("patterns", "\320\264\320\265\321\202\320\270", nullptr));
        categoryInput->setItemText(4, QCoreApplication::translate("patterns", "\321\200\320\276\320\264\320\270\321\202\320\265\320\273\320\270", nullptr));
        categoryInput->setItemText(5, QCoreApplication::translate("patterns", "\320\266\320\265\320\275\320\260", nullptr));
        categoryInput->setItemText(6, QCoreApplication::translate("patterns", "\320\274\321\203\320\266", nullptr));

        priorityLabel->setText(QCoreApplication::translate("patterns", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202:", nullptr));
        dueDateLabel->setText(QCoreApplication::translate("patterns", "\320\241\321\200\320\276\320\272 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\270\321\217:", nullptr));
        priorityInput->setItemText(0, QCoreApplication::translate("patterns", "\320\235\320\270\320\267\320\272\320\270\320\271", nullptr));
        priorityInput->setItemText(1, QCoreApplication::translate("patterns", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));
        priorityInput->setItemText(2, QCoreApplication::translate("patterns", "\320\222\321\213\321\201\320\276\320\272\320\270\320\271", nullptr));

        saveFormatLabel->setText(QCoreApplication::translate("patterns", "\320\244\320\276\321\200\320\274\320\260\321\202 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217:", nullptr));
        saveFormatInput->setItemText(0, QCoreApplication::translate("patterns", "JSON", nullptr));
        saveFormatInput->setItemText(1, QCoreApplication::translate("patterns", "CSV", nullptr));

    } // retranslateUi

};

namespace Ui {
    class patterns: public Ui_patterns {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATTERNS_H
