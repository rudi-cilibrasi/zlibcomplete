#include <iostream>
#include <stdlib.h>
#include <zlc/zlibcomplete.hpp>

using namespace zlibcomplete;
using namespace std;

int main(int argc, char **argv)
{
  const int CHUNK = 16384;
  char inbuf[CHUNK];
  int readBytes;
  int window_bits = 15;
  if (argc > 1) {
    window_bits = atoi(argv[1]);
  }
  if (window_bits < 8 || window_bits > 15) {
    window_bits = 15;
  }
  RawInflater inflater(window_bits);
  for (;;) {
    cin.read(inbuf, CHUNK);
    readBytes = cin.gcount();
    if (readBytes == 0) {
      break;
    }
    string input(inbuf, readBytes);
    cout << inflater.inflate(input);
  }
  return 0;
}
