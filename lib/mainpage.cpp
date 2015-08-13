/*! \mainpage zlibcomplete introduction
 *
 * \section intro_sec Introduction
 *
 * This library provides a convenient wrapper around the zlib library.
 * zlib is written in C and uses explicit pointers and allocation for
 * all operations.  zlibcomplete simplifies typical use by providing a
 * high-level C++ interface using std::string instead of pointers.  This
 * library uses RAII (Resource Allocation Is Initialization) in order to
 * obviate explicit allocation or deallocation.  The result is an easier to
 * use and simpler, less error-prone interface to the underlying zlib
 * functionality.

   \section download_sec Download
   <a href="downloads/zlibcomplete-1.0.4.tar.gz">zlibcomplete-1.0.4.tar.gz</a>

   \section install_sec Installation


<PRE>
    ./bootstrap.sh
    autoreconf
    ./configure
    make
    sudo make install
</PRE>

   \section step1 Usage

 Here is an example program showing how to do GZip compression:


<PRE>

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

</PRE>

Decompression is similar:

<PRE>

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

</PRE>

<PRE>

</PRE>
 *
 */
