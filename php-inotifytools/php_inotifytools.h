/*
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Du Song <freewizard@gmail.com>                              |
   +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#ifndef PHP_INOTIFYTOOLS_H
#define PHP_INOTIFYTOOLS_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#ifdef HAVE_INOTIFYTOOLS

#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#ifdef  __cplusplus
} // extern "C" 
#endif
#include <inotifytools/inotifytools.h>
#include <inotifytools/inotify.h>
#ifdef  __cplusplus
extern "C" {
#endif

extern zend_module_entry inotifytools_module_entry;
#define phpext_inotifytools_ptr &inotifytools_module_entry

#ifdef PHP_WIN32
#define PHP_INOTIFYTOOLS_API __declspec(dllexport)
#else
#define PHP_INOTIFYTOOLS_API
#endif

PHP_MINIT_FUNCTION(inotifytools);
PHP_MSHUTDOWN_FUNCTION(inotifytools);
PHP_RINIT_FUNCTION(inotifytools);
PHP_RSHUTDOWN_FUNCTION(inotifytools);
PHP_MINFO_FUNCTION(inotifytools);

#ifdef ZTS
#include "TSRM.h"
#endif

#define FREE_RESOURCE(resource) zend_list_delete(Z_LVAL_P(resource))

#define PROP_GET_LONG(name)    Z_LVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_LONG(name, l) zend_update_property_long(_this_ce, _this_zval, #name, strlen(#name), l TSRMLS_CC)

#define PROP_GET_DOUBLE(name)    Z_DVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_DOUBLE(name, d) zend_update_property_double(_this_ce, _this_zval, #name, strlen(#name), d TSRMLS_CC)

#define PROP_GET_STRING(name)    Z_STRVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_GET_STRLEN(name)    Z_STRLEN_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_STRING(name, s) zend_update_property_string(_this_ce, _this_zval, #name, strlen(#name), s TSRMLS_CC)
#define PROP_SET_STRINGL(name, s, l) zend_update_property_string(_this_ce, _this_zval, #name, strlen(#name), s, l TSRMLS_CC)


PHP_FUNCTION(inotifytools_initialize);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(inotifytools_initialize_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define inotifytools_initialize_arg_info NULL
#endif

PHP_FUNCTION(inotifytools_error);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(inotifytools_error_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 0)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define inotifytools_error_arg_info NULL
#endif

PHP_FUNCTION(inotifytools_event_to_str);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(inotifytools_event_to_str_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define inotifytools_event_to_str_arg_info NULL
#endif

PHP_FUNCTION(inotifytools_watch_recursively);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(inotifytools_watch_recursively_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 2)
  ZEND_ARG_INFO(0, path)
  ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define inotifytools_watch_recursively_arg_info NULL
#endif

PHP_FUNCTION(inotifytools_next_event);
#if (PHP_MAJOR_VERSION >= 5)
ZEND_BEGIN_ARG_INFO_EX(inotifytools_next_event_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()
#else /* PHP 4.x */
#define inotifytools_next_event_arg_info NULL
#endif

#ifdef  __cplusplus
} // extern "C" 
#endif

#endif /* PHP_HAVE_INOTIFYTOOLS */

#endif /* PHP_INOTIFYTOOLS_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
