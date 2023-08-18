#include "myyshell.h"

/**
 **_strgncpy - string to copy
 *@dst: the string for destination to copy it
 *@surc: string for source
 *@m: characters amount to be copy
 *Return: to the string
 */
char *_strgncpy(char *dst, char *surc, int m)
{
int a, g;
char *c = dst;
a = 0;
while (surc[a] != '\0' && a < m - 1)
{
dst[a] = surc[a];
a++;
}
if (a < m)
{
g = a;
while (g < m)
{
dst[g] = '\0';
g++;
}
}
return (c);
}
/**
 **_strgncat - it have two strings
 *@dst: string number one
 *@surc: string number two
 *@m: the bytes the maximum used
 *Return: to the string
 */
char *_strgncat(char *dst, char *surc, int m)
{
int a, g;
char *c = dst;
g = 0;
a = 0;
while (dst[a] != '\0')
a++;
while (surc[g] != '\0' && g < m)
{
dst[a] = surc[g];
g++;
a++;
}
if (g < m)
dst[a] = '\0';
return (c);
}
/**
 **_strgchr - the location for string character
 *@c: string parsed
 *@b: searching for the character
 *Return: the pointer to the memory c
 */
char *_strgchr(char *c, char b)
{
do {
if (*c == b)
return (c);
} while (*c++ != '\0');
return (NULL);
}
