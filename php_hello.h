#ifndef PHP_HELLO_H
#define PHP_HELLO_H

#define PHP_HELLO_VERSION "1.0"
#define PHP_HELLO_EXTNAME "hello"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#include "php.h"

extern zend_module_entry hello_module_entry;
#define phpext_hello_ptr &hello_module_entry

#endif