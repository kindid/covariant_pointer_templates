QT -= core
QT -= gui

TARGET = ptr_cov_4

CONFIG += c++11

CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    sanitise.cpp

HEADERS += \
    ptr.h \
    object.h \
    sanitise.h \
    isa.h \
    bool.h \
    inherits.h \
    conditional.h \
    type_list.h \
    raw_type.h

DISTFILES += \
    scratch.txt
