TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    custom_dictionary.h \
    dictionary.h \
    custom_not_found_exception.h \
    not_found_exception.h
