#include "php_hello.h"
#include "ext/standard/info.h"

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO(arginfo_hello, 0)
    ZEND_ARG_INFO(0, fname)
ZEND_END_ARG_INFO()
/* }}} */

PHP_MINIT_FUNCTION(hello)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(hello)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "Extension Version", PHP_HELLO_VERSION);
    php_info_print_table_end();
}

/* {{{ proto string howdy(string name)
   Return a "howdy" string with the name included */
PHP_FUNCTION(howdy)
{
    char *fname;
    /* char buffer[20]; */

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &fname) == FAILURE) {
        return;
    }

    /* snprintf(buffer, sizeof(buffer), "%s", buffer);
    RETURN_STRING(buffer, 1); */
    RETURN_STRING("test y'all\n", 1);
}
/* }}} */

static const zend_function_entry hello_functions[] = {
    PHP_FE(howdy, arginfo_hello)
    PHP_FE_END
};

zend_module_entry hello_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_HELLO_EXTNAME,
    hello_functions,
    PHP_MINIT(hello),
    NULL,
    NULL,
    NULL,
    PHP_MINFO(hello),
    PHP_HELLO_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HELLO
ZEND_GET_MODULE(hello)
#endif