QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    insertionsort.cpp \
    main.cpp \
    mainwindow.cpp \
    selectionsort.cpp \
    sort.cpp \
    sortfactory.cpp \
    transaction.cpp \
    transactionhandler.cpp \
    transactionlist.cpp

HEADERS += \
    insertionsort.h \
    mainwindow.h \
    selectionsort.h \
    sort.h \
    sortfactory.h \
    transaction.h \
    transactionhandler.h \
    transactionlist.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
