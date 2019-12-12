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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditAnimeModalWindow
{
public:
    QWidget *widget;
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
        widget = new QWidget(EditAnimeModalWindow);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 481, 341));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        genreEdit = new QLineEdit(widget);
        genreEdit->setObjectName(QStringLiteral("genreEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, genreEdit);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        voiceActingEdit = new QLineEdit(widget);
        voiceActingEdit->setObjectName(QStringLiteral("voiceActingEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, voiceActingEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, nameEdit);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        descriptionEdit = new QTextEdit(widget);
        descriptionEdit->setObjectName(QStringLiteral("descriptionEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, descriptionEdit);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        dateEdit = new QLineEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, dateEdit);

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
        save->setText(QApplication::translate("EditAnimeModalWindow", "Save changes", Q_NULLPTR));
        cancel->setText(QApplication::translate("EditAnimeModalWindow", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditAnimeModalWindow: public Ui_EditAnimeModalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITANIMEMODALWINDOW_H
