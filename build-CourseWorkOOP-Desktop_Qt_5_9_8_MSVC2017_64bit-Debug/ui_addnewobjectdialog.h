/********************************************************************************
** Form generated from reading UI file 'addnewobjectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWOBJECTDIALOG_H
#define UI_ADDNEWOBJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddNewObjectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QLabel *setNameLabel;
    QLineEdit *setNameTextEdit;
    QLabel *setCategoryLabel;
    QComboBox *setCategoryComboBox;
    QLabel *setSescriptionLabel;
    QTextEdit *setDescriptionTextEdit;
    QLabel *penFileExplorerLabel;
    QPushButton *openFileExplorerPushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *imageContainer;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *addMoviePushButton;
    QPushButton *cancelPushButton;

    void setupUi(QDialog *AddNewObjectDialog)
    {
        if (AddNewObjectDialog->objectName().isEmpty())
            AddNewObjectDialog->setObjectName(QStringLiteral("AddNewObjectDialog"));
        AddNewObjectDialog->resize(670, 439);
        verticalLayout = new QVBoxLayout(AddNewObjectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(AddNewObjectDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("font-size:50px;\n"
""));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        setNameLabel = new QLabel(AddNewObjectDialog);
        setNameLabel->setObjectName(QStringLiteral("setNameLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, setNameLabel);

        setNameTextEdit = new QLineEdit(AddNewObjectDialog);
        setNameTextEdit->setObjectName(QStringLiteral("setNameTextEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, setNameTextEdit);

        setCategoryLabel = new QLabel(AddNewObjectDialog);
        setCategoryLabel->setObjectName(QStringLiteral("setCategoryLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, setCategoryLabel);

        setCategoryComboBox = new QComboBox(AddNewObjectDialog);
        setCategoryComboBox->setObjectName(QStringLiteral("setCategoryComboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, setCategoryComboBox);

        setSescriptionLabel = new QLabel(AddNewObjectDialog);
        setSescriptionLabel->setObjectName(QStringLiteral("setSescriptionLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, setSescriptionLabel);

        setDescriptionTextEdit = new QTextEdit(AddNewObjectDialog);
        setDescriptionTextEdit->setObjectName(QStringLiteral("setDescriptionTextEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, setDescriptionTextEdit);

        penFileExplorerLabel = new QLabel(AddNewObjectDialog);
        penFileExplorerLabel->setObjectName(QStringLiteral("penFileExplorerLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, penFileExplorerLabel);

        openFileExplorerPushButton = new QPushButton(AddNewObjectDialog);
        openFileExplorerPushButton->setObjectName(QStringLiteral("openFileExplorerPushButton"));

        formLayout->setWidget(4, QFormLayout::FieldRole, openFileExplorerPushButton);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        imageContainer = new QLabel(AddNewObjectDialog);
        imageContainer->setObjectName(QStringLiteral("imageContainer"));

        horizontalLayout_2->addWidget(imageContainer);

        label = new QLabel(AddNewObjectDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        addMoviePushButton = new QPushButton(AddNewObjectDialog);
        addMoviePushButton->setObjectName(QStringLiteral("addMoviePushButton"));

        horizontalLayout->addWidget(addMoviePushButton);

        cancelPushButton = new QPushButton(AddNewObjectDialog);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));

        horizontalLayout->addWidget(cancelPushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(AddNewObjectDialog);

        QMetaObject::connectSlotsByName(AddNewObjectDialog);
    } // setupUi

    void retranslateUi(QDialog *AddNewObjectDialog)
    {
        AddNewObjectDialog->setWindowTitle(QApplication::translate("AddNewObjectDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("AddNewObjectDialog", "Film editor", Q_NULLPTR));
        setNameLabel->setText(QApplication::translate("AddNewObjectDialog", "Name", Q_NULLPTR));
        setCategoryLabel->setText(QApplication::translate("AddNewObjectDialog", "Category", Q_NULLPTR));
        setSescriptionLabel->setText(QApplication::translate("AddNewObjectDialog", "Description", Q_NULLPTR));
        penFileExplorerLabel->setText(QApplication::translate("AddNewObjectDialog", "Select image", Q_NULLPTR));
        openFileExplorerPushButton->setText(QApplication::translate("AddNewObjectDialog", "Search image", Q_NULLPTR));
        imageContainer->setText(QString());
        label->setText(QString());
        addMoviePushButton->setText(QApplication::translate("AddNewObjectDialog", "Add movie", Q_NULLPTR));
        cancelPushButton->setText(QApplication::translate("AddNewObjectDialog", "Cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AddNewObjectDialog: public Ui_AddNewObjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWOBJECTDIALOG_H
