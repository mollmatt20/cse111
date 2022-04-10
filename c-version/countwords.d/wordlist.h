// $Id: wordlist.h,v 1.2 2021-12-20 12:42:21-08 - - $

//
// Sorted list of word and frequency counts.
//
// wordlist_new - allocate a new list
// wordlist_delete - free the list
// wordlist_incr - increment the word count, insert if not there
// 

#ifndef WORDLIST_H
#define WORDLIST_H

typedef struct wordlist wordlist;

wordlist* wordlist_new (void);
void wordlist_delete (wordlist*);
void wordlist_incr (wordlist*, const char*);
void wordlist_print (wordlist* list);

#endif

