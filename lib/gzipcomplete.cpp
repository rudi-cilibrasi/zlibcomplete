#include <zlibcomplete.hpp>
#include <exception>
#include <zlib.h>
#include <string.h>
#include <iostream>

namespace zlibcomplete {

GZipCompressor::GZipCompressor(int level, flush_parameter autoFlush,
                               int windowBits) :
  ZLibBaseCompressor(level, autoFlush, windowBits + 16) {
}

std::string GZipCompressor::compress(const std::string& input) {
  return baseCompress(input);
}

std::string GZipCompressor::finish(void) {
  return baseFinish();
}

GZipDecompressor::GZipDecompressor(void) : ZLibBaseDecompressor(15+16) {
}

GZipDecompressor::~GZipDecompressor(void) {
}

std::string GZipDecompressor::decompress(const std::string& input) {
  return baseDecompress(input);
}

} // namespace zlib_complete
