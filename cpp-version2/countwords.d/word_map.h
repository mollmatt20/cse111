// $Id: word_map.h,v 1.2 2022-03-27 12:31:06-07 - - $

#ifndef WORD_MAP_H
#define WORD_MAP_H

#include <iostream>
#include <map>
using namespace std;

class word_map {
   private:
      using map_type = map<string,size_t>;
      map_type words;
      string tolower (const string&);
      void scan_line (const string&);
   public:
      using const_iterator = map_type::const_iterator;
      void scan_file (istream&);
      const_iterator begin() const { return words.cbegin(); }
      const_iterator end() const { return words.cend(); }
};

#endif

