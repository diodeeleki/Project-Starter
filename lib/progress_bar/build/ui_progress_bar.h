/********************************************************************************
** Form generated from reading UI file 'progress_bar.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESS_BAR_H
#define UI_PROGRESS_BAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_progress_bar_ui
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *plainTextEdit;
    QProgressBar *progressBar;

    void setupUi(QWidget *progress_bar_ui)
    {
        if (progress_bar_ui->objectName().isEmpty())
            progress_bar_ui->setObjectName(QString::fromUtf8("progress_bar_ui"));
        progress_bar_ui->resize(400, 300);
        horizontalLayout = new QHBoxLayout(progress_bar_ui);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(progress_bar_ui);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setReadOnly(true);

        verticalLayout->addWidget(plainTextEdit);

        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        horizontalLayout->addWidget(groupBox);


        retranslateUi(progress_bar_ui);

        QMetaObject::connectSlotsByName(progress_bar_ui);
    } // setupUi

    void retranslateUi(QWidget *progress_bar_ui)
    {
        progress_bar_ui->setWindowTitle(QApplication::translate("progress_bar_ui", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("progress_bar_ui", "\351\200\262\346\215\227\347\212\266\346\263\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class progress_bar_ui: public Ui_progress_bar_ui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESS_BAR_H
