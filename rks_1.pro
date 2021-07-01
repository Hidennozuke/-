QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QMAKE_LFLAGS += -static
QTPLUGIN += QPSQL
DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fileadd.cpp \
    fileedit.cpp \
    main.cpp \
    mainwindow.cpp \
    useradd.cpp \
    useredit.cpp


HEADERS += \
    connection.h \
    fileadd.h \
    fileedit.h \
    mainwindow.h \
    useradd.h \
    useredit.h

FORMS += \
    fileadd.ui \
    fileedit.ui \
    mainwindow.ui \
    useradd.ui \
    useredit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
