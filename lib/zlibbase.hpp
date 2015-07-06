#ifndef __ZLIBBASE_HPP
#define __ZLIBBASE_HPP

#define ZLIB_COMPLETE_CHUNK 16384

#include <zlib.h>

namespace zlibcomplete {

  enum flush_parameter { no_flush = 0, auto_flush = 1 };

  class ZLibBaseCompressor {
    char in_[ZLIB_COMPLETE_CHUNK];
    char out_[ZLIB_COMPLETE_CHUNK];
    bool autoFlush_;
    z_stream strm_;
protected:
    ZLibBaseCompressor(int level, flush_parameter autoFlush, int windowBits);
    ~ZLibBaseCompressor(void);
    std::string baseCompress(const std::string& input);
    std::string baseFinish(void);
  };

  class ZLibBaseDecompressor {
    char in_[ZLIB_COMPLETE_CHUNK];
    char out_[ZLIB_COMPLETE_CHUNK];
    z_stream strm_;
protected:
    ZLibBaseDecompressor(int windowBits);
    ~ZLibBaseDecompressor(void);
    std::string baseDecompress(const std::string& input);
  };

}

#endif
