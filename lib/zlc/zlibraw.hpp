#ifndef __ZLIBRAW_HPP
#define __ZLIBRAW_HPP

/**
 * @file   zlc/zlibraw.hpp
 * @Author Rudi Cilibrasi (cilibrar@alumni.caltech.edu)
 * @date   July 8, 2015
 * @brief  ZLib compression wrapper for C++ using RAII
 *
 * This file implements a ZLib wrapper for the ZLib library in C++.  It
 * supports all standard options including compression level, flush mode,
 * and window_bits.  This file uses raw (no header) streams.
 */

#include <zlc/zlibbase.hpp>

namespace zlibcomplete {

/**
  * @brief Raw ZLib compression class using std::string for input and output.
  *
  * Implements raw zlib compression using std::string for input and output.
  * To use, simply call compress() zero or more times and then call finish().
  * This class does not write a header, so it is necessary to match up the
  * window_bits parameter for the inflate and deflate methods.
  * This class implements
  * <a href="https://www.ietf.org/rfc/rfc1951.txt">RFC 1951.</a>
  */
  class RawDeflater : public ZLibBaseCompressor {
public:
/**
  * Accepts the standard three parameters for compression constructors.
  * @param level Compression level 1-9, defaulting to 9, the best compression.
  * @param flush_parameter Flush mode, either auto_flush or no_flush,
  *   defaulting to auto_flush mode.
  * @param window_bits Size of history window between 8 and 15, defaulting
  *   to 15.  It is important to pass the same number to the RawInflater
  *   constructor.
  */
    RawDeflater(int level = 9, flush_parameter autoFlush = auto_flush, int windowBits = 15);
    ~RawDeflater(void);
/**
  * @brief Compresses data.  Uses std::string for input and output.
  *
  * Accepts a std::string of any size containing data to compress.  Returns
  * as much raw zlib compressed data as possible.  In auto_flush mode, this
  * will ensure that the returned data is immediately decompressible to the
  * original data.  In no_flush mode, the data may not all be available
  * until the rest of the compressed data is written using more compress()
  * or a finish() call.  After calling compress() zero or more times, it
  * is necessary to call finish() exactly once.
  * @param input Any amount of data to compress.
  * @retval std::string containing compressed data.
  */
    std::string deflate(const std::string& input);
/**
  * @brief Writes a termination block to the raw zlib stream indicating the end.
  *
  * Flushes any remaining data that has not yet been written and then
  * writes a terminal block to the compressed data stream.  Returns this
  * compressed data as a std::string.  This function should be called exactly
  * once for each compressed data stream.
  * @retval std::string containing the last piece of compressed data.
  */
    std::string finish(void);
  };

/**
  * @brief Raw ZLib decompression class using std::string for input and output.
  *
  * Implements zlib decompression using std::string for input and output.
  * To use, simply call decompress() zero or more times.  Because the raw
  * compressed stream has no header, it is necessary to ensure that the same
  * window_bits parameter is used for the RawDeflater and RawInflater.
  * This class implements
  * <a href="https://www.ietf.org/rfc/rfc1951.txt">RFC 1951.</a>
  */
  class RawInflater : public ZLibBaseDecompressor {
public:
/**
  * @brief Constructs a Raw ZLib decompressor.
  *
  * Accepts a number of window_bits that must match that used with the
  * RawDeflater.
  *
  * @param window_bits An integer between 8 and 15 to control the window_size.
  * Defaults to 15.  This must match the window_bits used in the RawDeflater.
  */
    RawInflater(int windowBits = 15);
    ~RawInflater(void);
/**
  * Accepts a std::string of any size containing compressed data.  Returns
  * as much zlib uncompressed data as possible.  Call this function over
  * and over with all the compressed data in a stream in order to decompress
  * the entire stream.
  * @param input Any amount of data to decompress.
  * @retval std::string containing the decompressed data.
  */
    std::string inflate(const std::string& input);
  };

}

#endif
