QT += core gui
QT += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Diagram.cpp \
    Item.cpp \
    List.cpp \
    addmenu.cpp \
    changem.cpp \
    doubtmenu.cpp \
    filteredtable.cpp \
    filtermenu.cpp \
    main.cpp \
    mainwindow.cpp \
    mychangemenu.cpp \
    sortmenu.cpp \
    tablewidget.cpp

HEADERS += \
    Constants.h \
    Item.h \
    List.h \
    addmenu.h \
    changem.h \
    diagram.h \
    doubtmenu.h \
    filteredtable.h \
    filtermenu.h \
    mainwindow.h \
    mychangemenu.h \
    sortmenu.h \
    tablewidget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
