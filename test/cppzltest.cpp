#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <zlc/zlibcomplete.hpp>

using namespace zlibcomplete;
using namespace std;

// Thanks to DeLadoss for finding this bug and providing a fix.

void runBigChunkTest(void) {
  const int chunkTestSize = 100000;
  std::string str;

  int ival = 0;
  int step = 1;

  while (str.size() < chunkTestSize) {
    str += (char) ival;
    ival = (ival + step) % 177;
    step = (step + 1) % 17;
    str += "padding";
  }

  GZipCompressor compressor(9, auto_flush);
  string output = compressor.compress(str);
  output  += compressor.finish();

  GZipDecompressor decompressor;
  string output2 = decompressor.decompress(output);
  if (output2 != str) {
    cerr << "Large chunk compression test failed.\n";
    exit(1);
  }
}

int main(int argc, char **argv)
{
  runBigChunkTest();
  return 0;
}
