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
