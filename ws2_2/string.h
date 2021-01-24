#ifndef __ILRD_STRING_H__
#define __ILRD_STRING_H__

#include <string.h> /* size_t */

char *StrCpy(char *dest, const char *source);
char *StrNCpy(char *dest, const char *source, size_t n);
int StrCaseCmp(const char *str1, const char *str2);
char *StrChr(const char *str, int c); 
char *StrDup(const char *str);
size_t StrLen(const char *str);
char *StrCat(char *dest, const char *source);
char *StrNCat(char *dest, const char *source, size_t n);
char *StrStr(const char *str_to_find, const char *str_to_search);
size_t StrSpn(const char *str1, const char *str2);


#endif

