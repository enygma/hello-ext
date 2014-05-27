#include "php_hello.h"
#include "ext/standard/info.h"

PHP_MINFO_FUNCTION(hello) {
    php_info_print_table_start();
    php_info_print_table_header(2, "Uriparser Library Bindings", "enabled");
    php_info_print_table_row(2, "Extension Version", PHP_HELLO_VERSION);
    php_info_print_table_end();
}

static const zend_function_entry hello_functions[] = {
    ZEND_FE_END
};

zend_module_entry hello_module_entry = {
    STANDARD_MODULE_HEADER,
    PHP_HELLO_EXTNAME,
    hello_functions,
    NULL,
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