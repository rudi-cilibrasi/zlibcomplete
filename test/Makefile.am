bin_PROGRAMS = cppzltest

EXTRA_DIST = runrubytests runtests

cppzltest_SOURCES = cppzltest.cpp
cppzltest_CPPFLAGS= -I../lib
cppzltest_LDFLAGS=-L../lib
cppzltest_LDADD = -lzlibcomplete
cppzltest_DEPENDENCIES = ../lib/libzlibcomplete.la

