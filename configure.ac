#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([zlibcomplete], [1.0.2], [cilibrar@alumni.caltech.edu])
AM_INIT_AUTOMAKE
LT_INIT
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([lib/zlibtop.cpp])
AC_CONFIG_HEADERS([lib/config.h])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.
AC_CHECK_LIB(z, deflate)

AC_CHECK_HEADER(zlib.h)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CONFIG_FILES([Makefile examples/Makefile test/Makefile lib/Makefile])

AC_OUTPUT
