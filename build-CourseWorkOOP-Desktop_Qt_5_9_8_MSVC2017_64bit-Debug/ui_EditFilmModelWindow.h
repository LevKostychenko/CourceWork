/********************************************************************************
** Form generated from reading UI file 'EditFilmModelWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITFILMMODELWINDOW_H
#define UI_EDITFILMMODELWINDOW_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditFilmModelWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *save;
    QPushButton *cancel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *castEdit;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QLabel *label_4;
    QTextEdit *descriptionEdit;
    QLabel *label_5;
    QLineEdit *dateEdit;

    void setupUi(QDialog *EditFilmModelWindow)
    {
        if (EditFilmModelWindow->objectName().isEmpty())
            EditFilmModelWindow->setObjectName(QStringLiteral("EditFilmModelWindow"));
        EditFilmModelWindow->resize(461, 365);
        horizontalLayoutWidget = new QWidget(EditFilmModelWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 330, 441, 31));
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

        formLayoutWidget = new QWidget(EditFilmModelWindow);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 439, 309));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        castEdit = new QLineEdit(formLayoutWidget);
        castEdit->setObjectName(QStringLiteral("castEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, castEdit);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, nameEdit);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        descriptionEdit = new QTextEdit(formLayoutWidget);
        descriptionEdit->setObjectName(QStringLiteral("descriptionEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, descriptionEdit);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        dateEdit = new QLineEdit(formLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, dateEdit);


        retranslateUi(EditFilmModelWindow);

        QMetaObject::connectSlotsByName(EditFilmModelWindow);
    } // setupUi

    void retranslateUi(QDialog *EditFilmModelWindow)
    {
        EditFilmModelWindow->setWindowTitle(QApplication::translate("EditFilmModelWindow", "Dialog", Q_NULLPTR));
        save->setText(QApplication::translate("EditFilmModelWindow", "Save changes", Q_NULLPTR));
        cancel->setText(QApplication::translate("EditFilmModelWindow", "Cancel", Q_NULLPTR));
        label_2->setText(QApplication::translate("EditFilmModelWindow", "Cast", Q_NULLPTR));
        label_3->setText(QApplication::translate("EditFilmModelWindow", "Name", Q_NULLPTR));
        label_4->setText(QApplication::translate("EditFilmModelWindow", "Description", Q_NULLPTR));
        label_5->setText(QApplication::translate("EditFilmModelWindow", "Creating date", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EditFilmModelWindow: public Ui_EditFilmModelWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITFILMMODELWINDOW_H
