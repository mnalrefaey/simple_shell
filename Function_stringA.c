#include "myyshell.h"

/**
 * _strglen - dtring length to be returned in
 * @c: to check the string
 * Return: return to length string
*/

int _strglen(char *c)
{
int a = 0;

if (!c)
return (0);

while (*c++)
a++;

return (a);
}

/**
 * _strgcmp - performs lexicogarphic comparison of two strgangs.
 * @ca: the strang number one
 * @cb: the strang number two
 * Return: return 1 if ca > cb, -1 if ca < cb, 0 if ca == cb
*/

int _strgcmp(char *ca, char *cb)
{
while (*ca && *cb)
{
if (*ca != *cb)
return (*ca - *cb);

ca++;
cb++;
}
if (*ca == *cb)
return (0);

else
return (*ca < *cb ? -1 : 1);
}

/**
 * begin_with - looking for needle if she start with haystack
 * @hays: search for string
 * @nd: find the sub-string
 * Return: return to the address of the char, else NULL
*/

char *begin_with(const char *hays, const char *nd)
{
while (*nd)
if (*nd++ != *hays++)
return (NULL);

return ((char *)hays);
}

/**
 * _strgcat - string that contain two
 * @ds: the buffer destination
 * @surc: the buffer source
 * Return: return to destination buffer
*/

char *_strgcat(char *ds, char *surc)
{
char *rt = ds;

while (*ds)
ds++;

while (*surc)
*ds++ = *surc++;
*ds = *surc;

return (rt);
}
