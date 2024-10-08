QT += quick concurrent

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cgsunitshandler.cpp \
        customhashtable.cpp \
        fpsunitshandler.cpp \
        main.cpp \
        mksunitshandler.cpp \
        randomvaluesgenerator.cpp \
        unitsfactory.cpp \
        unitshandler.cpp \
        vectorimplementation.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include("./QtSuperMacros/QtSuperMacros.pri")

HEADERS += \
    cgsunitshandler.h \
    customhashtable.h \
    fpsunitshandler.h \
    mksunitshandler.h \
    randomvaluesgenerator.h \
    unitsfactory.h \
    unitshandler.h \
    vectorimplementation.h
