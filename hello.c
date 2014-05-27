#include "php_hello.h"
#include "ext/standard/info.h"

ZEND_BEGIN_ARG_INFO(hello_version_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

PHP_FUNCTION(howdy)
{
    RETURN_STRING("Howdy y'all\n", 1);
}

PHP_MINIT_FUNCTION(hello)
{
    // nothing to see
    return SUCCESS;
}

PHP_MINFO_FUNCTION(hello)
{
    php_info_print_table_start();
    php_info_print_table_row(2, "Extension Version", PHP_HELLO_VERSION);
    php_info_print_table_end();
}

static const zend_function_entry hello_functions[] = {
    PHP_FE(howdy, hello_version_args)
    ZEND_FE_END
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