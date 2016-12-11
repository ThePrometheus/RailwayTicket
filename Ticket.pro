QT += core
QT += gui
QT += widgets

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
    elderticket.cpp \
    seat.cpp \
    wagon.cpp \
    route.cpp \
    train.cpp \
    stops.cpp \
    station.cpp \
    bahn.cpp \
    passenger.cpp \
    routedb.cpp \
    findroutewindow.cpp

HEADERS += \
    ticket.h \
    fullticket.h \
    studentticket.h \
    ticketfordisabled.h \
    elderticket.h \
    passenger.h \
    seat.h \
    wagon.h \
    route.h \
    train.h \
    stops.h \
    station.h \
    bahn.h \
    routedb.h \
    findroutewindow.h
