#include <zlc/zlibcomplete.hpp>
#include <exception>
#include <zlib.h>
#include <string.h>
#include <iostream>

namespace zlibcomplete {

RawDeflater::RawDeflater(int level, flush_parameter autoFlush,
                               int windowBits) :
  ZLibBaseCompressor(level, autoFlush, -windowBits) {
}

std::string RawDeflater::deflate(const std::string& input) {
  return baseCompress(input);
}

std::string RawDeflater::finish(void) {
  return baseFinish();
}

RawDeflater::~RawDeflater(void) {
}

RawInflater::RawInflater(int window_bits) : ZLibBaseDecompressor(-window_bits) {
}

RawInflater::~RawInflater(void) {
}

std::string RawInflater::inflate(const std::string& input) {
  return baseDecompress(input);
}

} // namespace zlib_complete
