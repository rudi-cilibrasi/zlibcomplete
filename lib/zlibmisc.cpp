#include <zlibcomplete.hpp>
#include <exception>
#include <zlib.h>
#include <string.h>
#include <iostream>

namespace zlibcomplete {

ZLibCompressor::ZLibCompressor(int level, flush_parameter autoFlush,
                               int windowBits) :
  ZLibBaseCompressor(level, autoFlush, windowBits) {
}

std::string ZLibCompressor::compress(const std::string& input) {
  return baseCompress(input);
}

std::string ZLibCompressor::finish(void) {
  return baseFinish();
}

ZLibDecompressor::ZLibDecompressor(void) : ZLibBaseDecompressor(15) {
}

ZLibDecompressor::~ZLibDecompressor(void) {
}

std::string ZLibDecompressor::decompress(const std::string& input) {
  return baseDecompress(input);
}

} // namespace zlib_complete
