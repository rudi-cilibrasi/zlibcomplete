# zlibcomplete
C++ interface to the ZLib library supporting compression with FLUSH, decompression, and std::string. RAII

# Download

[zlibcomplete-1.0.4.tar.gz](http://rudi-cilibrasi.github.io/zlibcomplete/downloads/zlibcomplete-1.0.4.tar.gz)

See [Full Documentation here](http://rudi-cilibrasi.github.io/zlibcomplete/)

# Building

    ./bootstrap.sh
    autoreconf
    ./configure
    make
    sudo make install

# Documentation

See [Full Documentation here](http://rudi-cilibrasi.github.io/zlibcomplete/)

# Usage

To use the library it is sufficient to include the header file in your
C++ source code and add the

    -lzlibcomplete

option to your linker flags.

Here is a simple example to do gzip compression:

    #include <iostream>
    #include <zlc/zlibcomplete.hpp>

    using namespace zlibcomplete;
    using namespace std;

    int main(int argc, char **argv)
    {
      const int CHUNK = 16384;
      char inbuf[CHUNK];
      int readBytes;
      GZipCompressor compressor(9, auto_flush);
      for (;;) {
        cin.read(inbuf, CHUNK);
        readBytes = cin.gcount();
        if (readBytes == 0) {
          break;
        }
        string input(inbuf, readBytes);
        string output = compressor.compress(input);
        cout << output;
      }
      cout << compressor.finish();
      return 0;
    }

Notice that each chunk of data to be compressed is passed to the compress
function, and it returns a string to append to the compressed data
stream.  After all data has been passed to compress, it is important to call
finish so that a terminating block can be written to the compressed stream
indicating that the data is complete.

Decompression is similar:

    #include <iostream>
    #include <zlc/zlibcomplete.hpp>

    using namespace zlibcomplete;
    using namespace std;

    int main(int argc, char **argv)
    {
      const int CHUNK = 16384;
      char inbuf[CHUNK];
      int readBytes;
      GZipDecompressor decompressor;
      for (;;) {
        cin.read(inbuf, CHUNK);
        readBytes = cin.gcount();
        if (readBytes == 0) {
          break;
        }
        string input(inbuf, readBytes);
        string output = decompressor.decompress(input);
        cout << output;
      }
      return 0;
    }

If you would like to use ZLib compression instead, simply replace
GZipCompressor with ZLibCompressor and GZipDecompressor with ZLibDecompressor.

If you would like fine-grained control over the window size or want to
avoid any kind of compression header, you may use RawInflater or RawDeflater
instead.

To control the compression options more precisely, there are three
arguments that may be specified in order:

First, one may specify a compression level:

    int level

between 1 and 9.  This defaults to 9.

Next, one can specify one of two flush modes.  auto\_flush automatically
flushes after each string is compressed.  no\_flush prevents flushing until
the finish method is called.  The two choices are:

    zlibcomplete::auto_flush

or

    zlibcomplete::no_flush

passed as the second argument to the constructor.

The third argument is an integer window\_bits between 8 and 15.  This
represents the window size as a power of 2.  The default is 15, representing
a 32 kilobyte sliding history window.

The default level is 9, the default flush mode is auto\_flush, and the
default window\_bits is 15.  It is okay to call the constructors with
any number of arguments between 0 and 3, in order.

If fine-grained control is necessary, such as compressing without header
blocks, then one can use RawInflater and RawDeflater.  RawDeflater takes
the same arguments as the other constructors.  RawInflater requires one
argument, the integer window\_size, specifying a number between 8 and 15
in order to know how to properly decompress.

