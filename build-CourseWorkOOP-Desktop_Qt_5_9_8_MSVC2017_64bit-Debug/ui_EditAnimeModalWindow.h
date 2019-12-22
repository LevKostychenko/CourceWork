/********************************************************************************
** Form generated from reading UI file 'EditAnimeModalWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITANIMEMODALWINDOW_H
#define UI_EDITANIMEMODALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_EditAnimeModalWindow
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *genreEdit;
    QLabel *label_2;
    QLineEdit *voiceActingEdit;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QLabel *label_4;
    QTextEdit *descriptionEdit;
    QLabel *label_5;
    QLineEdit *dateEdit;
    QRadioButton *rate5;
    QRadioButton *rate1;
    QRadioButton *rate2;
    QRadioButton *rate3;
    QRadioButton *rate4;
    QLabel *label_6;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *save;
    QPushButton *cancel;

    void setupUi(QWidget *EditAnimeModalWindow)
    {
        if (EditAnimeModalWindow->objectName().isEmpty())
            EditAnimeModalWindow->setObjectName(QStringLiteral("EditAnimeModalWindow"));
        EditAnimeModalWindow->resize(503, 402);
        layoutWidget = new QWidget(EditAnimeModalWindow);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 481, 347));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        genreEdit = new QLineEdit(layoutWidget);
        genreEdit->setObjectName(QStringLiteral("genreEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, genreEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        voiceActingEdit = new QLineEdit(layoutWidget);
        voiceActingEdit->setObjectName(QStringLiteral("voiceActingEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, voiceActingEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, nameEdit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        descriptionEdit = new QTextEdit(layoutWidget);
        descriptionEdit->setObjectName(QStringLiteral("descriptionEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, descriptionEdit);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        dateEdit = new QLineEdit(layoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, dateEdit);

        rate5 = new QRadioButton(layoutWidget);
        rate5->setObjectName(QStringLiteral("rate5"));

        formLayout->setWidget(10, QFormLayout::FieldRole, rate5);

        rate1 = new QRadioButton(layoutWidget);
        rate1->setObjectName(QStringLiteral("rate1"));

        formLayout->setWidget(6, QFormLayout::FieldRole, rate1);

        rate2 = new QRadioButton(layoutWidget);
        rate2->setObjectName(QStringLiteral("rate2"));

        formLayout->setWidget(7, QFormLayout::FieldRole, rate2);

        rate3 = new QRadioButton(layoutWidget);
        rate3->setObjectName(QStringLiteral("rate3"));

        formLayout->setWidget(8, QFormLayout::FieldRole, rate3);

        rate4 = new QRadioButton(layoutWidget);
        rate4->setObjectName(QStringLiteral("rate4"));

        formLayout->setWidget(9, QFormLayout::FieldRole, rate4);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        horizontalLayoutWidget = new QWidget(EditAnimeModalWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 360, 481, 30));
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


        retranslateUi(EditAnimeModalWindow);

        QMetaObject::connectSlotsByName(EditAnimeModalWindow);
    } // setupUi

    void retranslateUi(QWidget *EditAnimeModalWindow)
    {
        EditAnimeModalWindow->setWindowTitle(QApplication::translate("EditAnimeModalWindow", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("EditAnimeModalWindow", "Genre", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditAnimeModalWindow", "Voice acting", Q_NULLPTR));
        label_3->setText(QApplication::translate("EditAnimeModalWindow", "Name", Q_NULLPTR));
        label_4->setText(QApplication::translate("EditAnimeModalWindow", "Description", Q_NULLPTR));
        label_5->setText(QApplication::translate("EditAnimeModalWindow", "Creating date", Q_NULLPTR));
        rate5->setText(QApplication::translate("EditAnimeModalWindow", "5", Q_NULLPTR));
        rate1->setText(QApplication::translate("EditAnimeModalWindow", "1", Q_NULLPTR));
        rate2->setText(QApplication::translate("EditAnimeModalWindow", "2", Q_NULLPTR));
        rate3->setText(QApplication::translate("EditAnimeModalWindow", "3", Q_NULLPTR));
        rate4->setText(QApplication::translate("EditAnimeModalWindow", "4", Q_NULLPTR));
        label_6->setText(QApplication::translate("EditAnimeModalWindow", "Rate", Q_NULLPTR));
        save->setText(QApplication::translate("EditAnimeModalWindow", "Save changes", Q_NULLPTR));
        cancel->setText(QApplication::translate("EditAnimeModalWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditAnimeModalWindow: public Ui_EditAnimeModalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITANIMEMODALWINDOW_H
