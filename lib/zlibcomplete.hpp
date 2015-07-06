#ifndef __ZLIBCOMPLETE_HPP
#define __ZLIBCOMPLETE_HPP

#include <string>

#include <zlib.h>

#if ZLIB_VERNUM < 0x1230
#error "Please upgrade your zlib library for security."
#endif

#include <gzipcomplete.hpp>
#include <zlibmisc.hpp>
#include <zlibraw.hpp>

#endif
