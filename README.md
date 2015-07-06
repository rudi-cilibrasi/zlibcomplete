# zlibcomplete
C++ header-only interface to the ZLib library supporting compression with FLUSH, decompression, and std::string. RAII

# Building

    ./bootstrap.sh
    autoreconf
    ./configure
    make
    sudo make install

# Usage

Then, use as follows to do gzip compression:

    #include <iostream>
    #include <zlibcomplete.hpp>

    using namespace zlibcomplete;
    using namespace std;

    int main(int argc, char **argv)
    {
      const int CHUNK = 16384;
      char inbuf[CHUNK];
      int readBytes;
      GZipCompressor compressor(9, auto_flush);
      do {
        cin.read(inbuf, CHUNK);
        readBytes = cin.gcount();
        string input(inbuf, readBytes);
        string output = compressor.compress(input);
        cout << output;
      } while (readBytes != 0);
      cout << compressor.finish();
      return 0;
    }

Decompression is similar:

    #include <iostream>
    #include <zlibcomplete.hpp>

    using namespace zlibcomplete;
    using namespace std;

    int main(int argc, char **argv)
    {
      const int CHUNK = 16384;
      char inbuf[CHUNK];
      int readBytes;
      GZipDecompressor decompressor;
      do {
        cin.read(inbuf, CHUNK);
        readBytes = cin.gcount();
        string input(inbuf, readBytes);
        string output = decompressor.decompress(input);
        cout << output;
      } while (readBytes != 0);
      return 0;
    }

If you would like to use ZLib compression instead, simple replace
GZipCompressor with ZLibCompressor and GZipDecompressor with ZLibDecompressor.

If you would like fine-grained control over the window size or want to
avoid any kind of compression header, you may use RawInflater or RawDeflater
instead.

