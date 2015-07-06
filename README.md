# zlibcomplete
C++ header-only interface to the ZLib library supporting compression with FLUSH, decompression, and std::string. RAII

# Usage

Simply copy the file zlibcompete.hpp into your project or a header directory
and include with:

    #include "zlibcomplete.hpp"

or

    #include <zlibcomplete.hpp>

Then, use as follows:

    int main(int argc, char **argv) {
      ZLibCompleteDeflate deflater; // By default, auto-flush is on.
      deflater << "greetings, this text will be compressed and flushed.\n";
      std::string result = deflater();
      return 0;
    }
      
