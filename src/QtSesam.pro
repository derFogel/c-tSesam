TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    pbkdf2.cpp \
    clipboard.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    pbkdf2.hpp \
    clipboard.hpp

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += openssl
