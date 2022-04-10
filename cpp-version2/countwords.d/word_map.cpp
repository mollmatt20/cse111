// $Id: word_map.cpp,v 1.20 2022-03-27 12:31:06-07 - - $

#include <cctype>
#include <regex>
using namespace std;

#include "word_map.h"

string word_map::tolower (const string& line) {
   string lower {line};
   for (char& chr: lower) chr = ::tolower (chr);
   return lower;
}

void word_map::scan_line (const string& line) {
   static const regex word_rx {"[[:alpha:]]+"};
   for (auto itor = sregex_iterator (line.begin(), line.end(), word_rx);
        itor != sregex_iterator();
        ++itor) {
      ++words[tolower (itor->str())];
   }
}

void word_map::scan_file (istream& infile) {
   for (;;) {
      string line;
      getline (infile, line);
      if (infile.eof()) break;
      scan_line (line);
   }
}

