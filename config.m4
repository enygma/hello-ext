dnl hello world extension

PHP_ARG_WITH(hello, for hello world support,
[  --enable-hello   Include hello support], yes)

CFLAGS="$CFLAGS -arch i386 -arch x86_64 -mmacosx-version-min=10.5"

if test "$PHP_HELLO" != "no"; then
    PHP_NEW_EXTENSION(hello, hello.c, $ext_shared)
fi