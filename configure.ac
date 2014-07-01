#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([magee], [1.0], [donald.cory.harvey@gmail.com])
AC_CONFIG_SRCDIR([getops.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC_C99
AC_PROG_CPP
AC_LANG([C]) 

# Checks for libraries.

# Checks for header files.
C_HEADER_STDC 
AC_CHECK_HEADERS([stdio.h limits.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([strchr])

AC_CONFIG_FILES([Makefile
                 src/bin/Makefile
                 tempStore/Makefile])
AC_OUTPUT
