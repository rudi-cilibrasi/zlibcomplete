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
