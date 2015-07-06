#ifndef __GZIPCOMPLETE_HPP
#define __GZIPCOMPLETE_HPP

#include <zlibbase.hpp>

namespace zlibcomplete {

  class GZipCompressor : public ZLibBaseCompressor {
public:
    GZipCompressor(int level = 9, flush_parameter autoFlush = auto_flush, int windowBits = 15);
    std::string compress(const std::string& input);
    std::string finish(void);
  };

  class GZipDecompressor : public ZLibBaseDecompressor {
public:
    GZipDecompressor(void);
    ~GZipDecompressor(void);
    std::string decompress(const std::string& input);
  };

}

#endif
