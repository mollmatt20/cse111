// $Id: vstring.h,v 1.2 2021-12-20 12:42:21-08 - - $

//
// Buffer to accumulate a variable sized character string.
//
// vstring_new - allocate a new vstring
// vstring_delete - delete the vstring
// vstring_clear - set the vstring to the empty string
// vstring_append - append a character to the vstring
// vstring_peek - return a peek of the contents of the string
//

#ifndef VSTRING_H
#define VSTRING_H

typedef struct vstring vstring;

vstring* vstring_new (void);
void vstring_delete (vstring*);
void vstring_clear (vstring*);
void vstring_append (vstring*, char);
const char* vstring_peek (vstring*);

#endif

