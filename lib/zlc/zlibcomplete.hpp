#ifndef __ZLIBCOMPLETE_HPP
#define __ZLIBCOMPLETE_HPP

#include <string>

#include <zlib.h>

#if ZLIB_VERNUM < 0x1230
#error "Please upgrade your zlib library for security."
#endif

#ifdef __GNUC__

         #define CURRENT_GCC_VERSION (__GNUC__ * 10000 \
                                + __GNUC_MINOR__ * 100 \
                                + __GNUC_PATCHLEVEL__)
#if CURRENT_GCC_VERSION < 40800
#error "Please use g++ version 4.8 or later."
#endif

#endif

#include <zlc/gzipcomplete.hpp>
#include <zlc/zlibmisc.hpp>
#include <zlc/zlibraw.hpp>

#endif
