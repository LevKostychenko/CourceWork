/********************************************************************************
** Form generated from reading UI file 'filmblock.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILMBLOCK_H
#define UI_FILMBLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilmBlock
{
public:

    void setupUi(QWidget *FilmBlock)
    {
        if (FilmBlock->objectName().isEmpty())
            FilmBlock->setObjectName(QStringLiteral("FilmBlock"));
        FilmBlock->resize(345, 148);

        retranslateUi(FilmBlock);

        QMetaObject::connectSlotsByName(FilmBlock);
    } // setupUi

    void retranslateUi(QWidget *FilmBlock)
    {
        FilmBlock->setWindowTitle(QApplication::translate("FilmBlock", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FilmBlock: public Ui_FilmBlock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILMBLOCK_H
