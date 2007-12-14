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

#include "php_inotifytools.h"

#if HAVE_INOTIFYTOOLS

/* #include <sys/inotify.h> */
/* {{{ inotifytools_functions[] */
function_entry inotifytools_functions[] = {
	PHP_FE(inotifytools_initialize, inotifytools_initialize_arg_info)
	PHP_FE(inotifytools_error  , inotifytools_error_arg_info)
	PHP_FE(inotifytools_event_to_str, inotifytools_event_to_str_arg_info)
	PHP_FE(inotifytools_watch_recursively, inotifytools_watch_recursively_arg_info)
	PHP_FE(inotifytools_next_event, inotifytools_next_event_arg_info)
	{ NULL, NULL, NULL }
};
/* }}} */


/* {{{ inotifytools_module_entry
 */
zend_module_entry inotifytools_module_entry = {
	STANDARD_MODULE_HEADER,
	"inotifytools",
	inotifytools_functions,
	PHP_MINIT(inotifytools),     /* Replace with NULL if there is nothing to do at php startup   */ 
	PHP_MSHUTDOWN(inotifytools), /* Replace with NULL if there is nothing to do at php shutdown  */
	PHP_RINIT(inotifytools),     /* Replace with NULL if there is nothing to do at request start */
	PHP_RSHUTDOWN(inotifytools), /* Replace with NULL if there is nothing to do at request end   */
	PHP_MINFO(inotifytools),
	"0.1", 
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_INOTIFYTOOLS
ZEND_GET_MODULE(inotifytools)
#endif


/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(inotifytools)
{
	REGISTER_LONG_CONSTANT("IN_ACCESS", IN_ACCESS, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_ATTRIB", IN_ATTRIB, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_CLOSE_WRITE", IN_CLOSE_WRITE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_CLOSE_NOWRITE", IN_CLOSE_NOWRITE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_CLOSE", IN_CLOSE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_CREATE", IN_CREATE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_DELETE", IN_DELETE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_DELETE_SELF", IN_DELETE_SELF, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_MODIFY", IN_MODIFY, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_MOVE_SELF", IN_MOVE_SELF, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_MOVED_FROM", IN_MOVED_FROM, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_MOVED_TO", IN_MOVED_TO, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_MOVE", IN_MOVE, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_OPEN", IN_OPEN, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_DONT_FOLLOW", IN_DONT_FOLLOW, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_MASK_ADD", IN_MASK_ADD, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_ONESHOT", IN_ONESHOT, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_ONLYDIR", IN_ONLYDIR, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_IGNORED", IN_IGNORED, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_ISDIR", IN_ISDIR, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_Q_OVERFLOW", IN_Q_OVERFLOW, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_UNMOUNT", IN_UNMOUNT, CONST_PERSISTENT | CONST_CS);
	REGISTER_LONG_CONSTANT("IN_ALL_EVENTS", IN_ALL_EVENTS, CONST_PERSISTENT | CONST_CS);

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MSHUTDOWN_FUNCTION */
PHP_MSHUTDOWN_FUNCTION(inotifytools)
{

	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(inotifytools)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_RSHUTDOWN_FUNCTION */
PHP_RSHUTDOWN_FUNCTION(inotifytools)
{
	/* add your stuff here */

	return SUCCESS;
}
/* }}} */


/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(inotifytools)
{
	php_info_print_box_start(0);
	php_printf("<p>libinotifytools wrapper</p>\n");
	php_printf("<p>Version 0.1stable (2007-11-29)</p>\n");
	php_printf("<p><b>Authors:</b></p>\n");
	php_printf("<p>Du Song &lt;freewizard@gmail.com&gt; (developer)</p>\n");
	php_info_print_box_end();
	/* add your stuff here */

}
/* }}} */


/* {{{ proto bool inotifytools_initialize()
   */
PHP_FUNCTION(inotifytools_initialize)
{



	if (ZEND_NUM_ARGS()>0)  {
		WRONG_PARAM_COUNT;
	}


	do {
		RETURN_BOOL(inotifytools_initialize());
	} while (0);
}
/* }}} inotifytools_initialize */


/* {{{ proto int inotifytools_error()
   */
PHP_FUNCTION(inotifytools_error)
{



	if (ZEND_NUM_ARGS()>0)  {
		WRONG_PARAM_COUNT;
	}


	do {
		RETURN_LONG(inotifytools_error());
	} while (0);
}
/* }}} inotifytools_error */


/* {{{ proto string inotifytools_event_to_str(int event)
   */
PHP_FUNCTION(inotifytools_event_to_str)
{

	long event = 0;



	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &event) == FAILURE) {
		return;
	}

	do {
		RETURN_STRING(inotifytools_event_to_str(event), 1);
	} while (0);
}
/* }}} inotifytools_event_to_str */


/* {{{ proto int inotifytools_watch_recursively(string path, int event)
   */
PHP_FUNCTION(inotifytools_watch_recursively)
{

	const char * path = NULL;
	int path_len = 0;
	long event = 0;



	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sl", &path, &path_len, &event) == FAILURE) {
		return;
	}

	do {
		RETURN_LONG(inotifytools_watch_recursively(path, event));
	} while (0);
}
/* }}} inotifytools_watch_recursively */


/* {{{ proto mixed inotifytools_next_event(int timeout)
   */
PHP_FUNCTION(inotifytools_next_event)
{

	long timeout = 0;



	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &timeout) == FAILURE) {
		return;
	}

	do {
		struct inotify_event *ev;
		ev = inotifytools_next_event(timeout);
		if (!ev) RETURN_NULL();
		array_init(return_value);
		add_assoc_long(return_value, "wd", ev->wd);
		add_assoc_long(return_value, "mask", ev->mask);
		add_assoc_long(return_value, "cookie", ev->cookie);
		add_assoc_stringl(return_value, "name", ev->name, ev->len, 1);
		add_assoc_long(return_value, "wd", ev->wd);
	} while (0);
}
/* }}} inotifytools_next_event */

#endif /* HAVE_INOTIFYTOOLS */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
