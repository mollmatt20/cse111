// $Id: countwords.cpp,v 1.9 2022-03-27 16:27:03-07 - - $

#include <cerrno>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#include "word_map.h"

struct {
   string name;
   int status = EXIT_SUCCESS;
} exec;

void read_file (const string& filename, word_map& words) {
   if (filename == "-") words.scan_file (cin);
   else {
      ifstream infile (filename);
      if (infile) words.scan_file (infile);
      else {
         exec.status = EXIT_FAILURE;
         cerr << exec.name << ": " << filename << ": "
              << strerror (errno) << endl;
      }
   }
}

int main (int argc, char** argv) {
   exec.name = basename (argv[0]);
   exec.status = EXIT_SUCCESS;
   vector<string> filenames (&argv[1], &argv[argc]);

   word_map words;
   if (filenames.size() == 0) filenames.push_back ("-");
   for (const auto& filename: filenames) read_file (filename, words);

   for (const auto& pair: words) {
      cout << pair.first << " " << pair.second << endl;
   }
   return exec.status;
}

