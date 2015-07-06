#ifndef __ZLIBMISC_HPP
#define __ZLIBMISC_HPP

#include <zlibbase.hpp>

namespace zlibcomplete {

  class ZLibCompressor : public ZLibBaseCompressor {
    ZLibCompressor(int level = 9, flush_parameter autoFlush = auto_flush, int windowBits = 15);
    ~ZLibCompressor(void);
    std::string compress(const std::string& input);
    std::string finish(void);
  };

  class ZLibDecompressor : public ZLibBaseDecompressor {
    ZLibDecompressor(void);
    ~ZLibDecompressor(void);
    std::string decompress(const std::string& input);
  };

}

#endif

