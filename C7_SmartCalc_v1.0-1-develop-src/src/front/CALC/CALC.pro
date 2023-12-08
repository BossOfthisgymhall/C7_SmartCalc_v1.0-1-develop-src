QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ../../back/connect_front_in_back.c \
    ../../back/s21_artihmetic.c \
    ../../back/s21_error_proccesing.c \
    ../../back/s21_parser.c \
    ../../back/s21_rpn_processing.c \
    ../../back/s21_stack.c \
    qcustomplot.cpp

HEADERS += \
    mainwindow.h \
    ../../s21_smart_calc.h \
    qcustomplot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
