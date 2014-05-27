dnl hello world extension

PHP_ARG_ENABLE(hello, for hello world support,
[  --enable-hello   Include hello support], yes)

if test "$PHP_HELLO" != "no"; then
    PHP_NEW_EXTENSION(hello, hello.c, $ext_shared)
fi