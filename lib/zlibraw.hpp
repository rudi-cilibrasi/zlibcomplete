#ifndef __ZLIBRAW_HPP
#define __ZLIBRAW_HPP

#include <zlibbase.hpp>

namespace zlibcomplete {

  class RawDeflater : public ZLibBaseCompressor {
public:
    RawDeflater(int level = 9, flush_parameter autoFlush = auto_flush, int windowBits = 15);
    ~RawDeflater(void);
    std::string deflate(const std::string& input);
    std::string finish(void);
  };

  class RawInflater {
public:
    RawInflater(int windowBits = 15);
    ~RawInflater(void);
    std::string inflate(const std::string& input);
  };

}

#endif
