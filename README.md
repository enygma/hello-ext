hello-ext
=========

sample php extension

Here's how I built it:

1. Cloned the repo under a post-compiled PHP in `ext/`
2. Ensured that the `phpize` I was working with was the right one (from the PHP I just compiled, check the `$PATH`)
3. Ran: `make clean; phpize --clean; phpize; ./configure --with-php-config=/path/to/bin/php-config; make; make install`
4. Added the following to the `php.ini`:

```
[hello]
extension="/Users/ccornutt/work/php-extension/php/lib/php/extensions/no-debug-non-zts-20100525/hello.so"
```