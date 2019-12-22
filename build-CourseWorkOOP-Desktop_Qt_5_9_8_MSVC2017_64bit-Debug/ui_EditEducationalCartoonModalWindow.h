/********************************************************************************
** Form generated from reading UI file 'EditEducationalCartoonModalWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITEDUCATIONALCARTOONMODALWINDOW_H
#define UI_EDITEDUCATIONALCARTOONMODALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditEducationalCartoonModalWindow
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *educationalThemeEdit;
    QLabel *label_2;
    QLineEdit *voiceActingEdit;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QLabel *label_4;
    QTextEdit *descriptionEdit;
    QLabel *label_5;
    QLineEdit *dateEdit;
    QRadioButton *rate1;
    QRadioButton *rate2;
    QRadioButton *rate5;
    QRadioButton *rate4;
    QRadioButton *rate3;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *save;
    QPushButton *cancel;

    void setupUi(QDialog *EditEducationalCartoonModalWindow)
    {
        if (EditEducationalCartoonModalWindow->objectName().isEmpty())
            EditEducationalCartoonModalWindow->setObjectName(QStringLiteral("EditEducationalCartoonModalWindow"));
        EditEducationalCartoonModalWindow->resize(455, 409);
        formLayoutWidget = new QWidget(EditEducationalCartoonModalWindow);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 439, 347));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        educationalThemeEdit = new QLineEdit(formLayoutWidget);
        educationalThemeEdit->setObjectName(QStringLiteral("educationalThemeEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, educationalThemeEdit);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        voiceActingEdit = new QLineEdit(formLayoutWidget);
        voiceActingEdit->setObjectName(QStringLiteral("voiceActingEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, voiceActingEdit);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, nameEdit);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        descriptionEdit = new QTextEdit(formLayoutWidget);
        descriptionEdit->setObjectName(QStringLiteral("descriptionEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, descriptionEdit);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        dateEdit = new QLineEdit(formLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, dateEdit);

        rate1 = new QRadioButton(formLayoutWidget);
        rate1->setObjectName(QStringLiteral("rate1"));

        formLayout->setWidget(6, QFormLayout::FieldRole, rate1);

        rate2 = new QRadioButton(formLayoutWidget);
        rate2->setObjectName(QStringLiteral("rate2"));

        formLayout->setWidget(7, QFormLayout::FieldRole, rate2);

        rate5 = new QRadioButton(formLayoutWidget);
        rate5->setObjectName(QStringLiteral("rate5"));

        formLayout->setWidget(10, QFormLayout::FieldRole, rate5);

        rate4 = new QRadioButton(formLayoutWidget);
        rate4->setObjectName(QStringLiteral("rate4"));

        formLayout->setWidget(9, QFormLayout::FieldRole, rate4);

        rate3 = new QRadioButton(formLayoutWidget);
        rate3->setObjectName(QStringLiteral("rate3"));

        formLayout->setWidget(8, QFormLayout::FieldRole, rate3);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        horizontalLayoutWidget = new QWidget(EditEducationalCartoonModalWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 370, 441, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        save = new QPushButton(horizontalLayoutWidget);
        save->setObjectName(QStringLiteral("save"));

        horizontalLayout->addWidget(save);

        cancel = new QPushButton(horizontalLayoutWidget);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout->addWidget(cancel);


        retranslateUi(EditEducationalCartoonModalWindow);

        QMetaObject::connectSlotsByName(EditEducationalCartoonModalWindow);
    } // setupUi

    void retranslateUi(QDialog *EditEducationalCartoonModalWindow)
    {
        EditEducationalCartoonModalWindow->setWindowTitle(QApplication::translate("EditEducationalCartoonModalWindow", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Educational theme", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Voice acting", Q_NULLPTR));
        label_3->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Name", Q_NULLPTR));
        label_4->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Description", Q_NULLPTR));
        label_5->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Creating date", Q_NULLPTR));
        rate1->setText(QApplication::translate("EditEducationalCartoonModalWindow", "1", Q_NULLPTR));
        rate2->setText(QApplication::translate("EditEducationalCartoonModalWindow", "2", Q_NULLPTR));
        rate5->setText(QApplication::translate("EditEducationalCartoonModalWindow", "5", Q_NULLPTR));
        rate4->setText(QApplication::translate("EditEducationalCartoonModalWindow", "4", Q_NULLPTR));
        rate3->setText(QApplication::translate("EditEducationalCartoonModalWindow", "3", Q_NULLPTR));
        label_6->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Rate", Q_NULLPTR));
        save->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Save changes", Q_NULLPTR));
        cancel->setText(QApplication::translate("EditEducationalCartoonModalWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditEducationalCartoonModalWindow: public Ui_EditEducationalCartoonModalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITEDUCATIONALCARTOONMODALWINDOW_H
