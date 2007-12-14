dnl
dnl $ Id: $
dnl

PHP_ARG_WITH(inotifytools, whether inotifytools is available,[  --with-inotifytools[=DIR] With inotifytools support])


if test "$PHP_INOTIFYTOOLS" != "no"; then


  if test -r "$PHP_INOTIFYTOOLS/include/inotifytools/inotifytools.h"; then
	PHP_INOTIFYTOOLS_DIR="$PHP_INOTIFYTOOLS"
  else
	AC_MSG_CHECKING(for inotifytools in default path)
	for i in /usr /usr/local; do
	  if test -r "$i/include/inotifytools/inotifytools.h"; then
		PHP_INOTIFYTOOLS_DIR=$i
		AC_MSG_RESULT(found in $i)
		break
	  fi
	done
	if test "x" = "x$PHP_INOTIFYTOOLS_DIR"; then
	  AC_MSG_ERROR(not found)
	fi
  fi

  PHP_ADD_INCLUDE($PHP_INOTIFYTOOLS_DIR/include)

  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_INOTIFYTOOLS"
  AC_CHECK_HEADER([inotifytools/inotifytools.h], [], AC_MSG_ERROR('inotifytools/inotifytools.h' header not found))
  AC_CHECK_HEADER([inotifytools/inotify.h], [], AC_MSG_ERROR('inotifytools/inotify.h' header not found))
  PHP_SUBST(INOTIFYTOOLS_SHARED_LIBADD)

  PHP_ADD_LIBRARY_WITH_PATH(inotifytools, $PHP_INOTIFYTOOLS_DIR/lib, INOTIFYTOOLS_SHARED_LIBADD)
  export CPPFLAGS="$OLD_CPPFLAGS"

  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_INOTIFYTOOLS"

  AC_MSG_CHECKING(PHP version)
  AC_TRY_COMPILE([#include <php_version.h>], [
#if PHP_VERSION_ID < 40000
#error  this extension requires at least PHP version 4.0.0
#endif
],
[AC_MSG_RESULT(ok)],
[AC_MSG_ERROR([need at least PHP 4.0.0])])

  export CPPFLAGS="$OLD_CPPFLAGS"


  PHP_SUBST(INOTIFYTOOLS_SHARED_LIBADD)
  AC_DEFINE(HAVE_INOTIFYTOOLS, 1, [ ])

  PHP_NEW_EXTENSION(inotifytools, inotifytools.c , $ext_shared)

fi

