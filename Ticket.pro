QT += core
QT -= gui

CONFIG += c++11

TARGET = Ticket
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    fullticket.cpp \
    studentticket.cpp \
    ticketfordisabled.cpp \
    ticket.cpp \
    elderticket.cpp

HEADERS += \
    ticket.h \
    fullticket.h \
    studentticket.h \
    ticketfordisabled.h \
    elderticket.h
