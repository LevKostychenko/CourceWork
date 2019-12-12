QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseException.cpp \
    CustomDatabase.cpp \
    DescriptionWindow.cpp \
    EditAnimeModalWindow.cpp \
    EditEducationalCartoonModalWindow.cpp \
    EditFilmModelWindow.cpp \
    FileException.cpp \
    FindLogic.cpp \
    InputException.cpp \
    InputLogic.cpp \
    VideoDBContext.cpp \
    VideoRepository.cpp \
    addnewobjectdialog.cpp \
    anime.cpp \
    cartoon.cpp \
    educational.cpp \
    filmblock.cpp \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    video.cpp

HEADERS += \
    ActionEnum.h \
    BaseException.h \
    CustomDatabase.h \
    DescriptionWindow.h \
    EditAnimeModalWindow.h \
    EditEducationalCartoonModalWindow.h \
    EditFilmModelWindow.h \
    ExceptionCodeEnum.h \
    FileException.h \
    FindLogic.h \
    InputException.h \
    InputLogic.h \
    List.h \
    VideoDBContext.h \
    VideoRepository.h \
    addnewobjectdialog.h \
    anime.h \
    cartoon.h \
    educational.h \
    filmblock.h \
    mainwindow.h \
    movie.h \
    video.h

FORMS += \
    DescriptionWindow.ui \
    EditAnimeModalWindow.ui \
    EditEducationalCartoonModalWindow.ui \
    EditFilmModelWindow.ui \
    addnewobjectdialog.ui \
    filmblock.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
