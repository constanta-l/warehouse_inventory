QT       += core gui sql pdf pdfwidgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets



CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addproductdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    paginationmanager.cpp \
    readonlyitemdelegate.cpp

HEADERS += \
    addproductdialog.h \
    mainwindow.h \
    paginationmanager.h \
    readonlyitemdelegate.h

FORMS += \
    mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../Resources/Resources.qrc
