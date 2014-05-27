dnl hello world extension

PHP_ARG_WITH(hello, for hello world support,
[  --enable-hello   Exclude iconv support], yes)

if test "$PHP_HELLO" != "no"; then
    PHP_NEW_EXTENSION(hello, hello.c, $ext_shared)
fi