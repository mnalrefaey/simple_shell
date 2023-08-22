#include "myyshell.h"

/**
 * _memst - memory files with byte
 * @c: memory pointer
 * @h: bytes fill out
 * @f: bytes to be filled
 * Return: return to the pointer memory
*/

char *_memst(char *c, char h, unsigned int f)
{
unsigned int a;

for (a = 0; a < f; a++)
c[a] = h;

return (c);
}

/**
 * vrree - the string be free
 * @fr: the string that will be free
*/

void vrree(char **fr)
{
char **i = fr;

if (!fr)
return;

while (*fr)
free(*fr++);
free(i);

}

/**
 * _reallocate - a block of memory will be reallocate
 * @pr: the previous malloc block
 * @old: the block byte size
 * @nw: new block byte size
 * Return: return to the old block pointer
*/

void *_reallocate(void *pr, unsigned int old, unsigned int nw)
{
char *b;

if (!pr)
return (malloc(nw));

if (!nw)
return (free(pr), NULL);

if (nw == old)
return (pr);

b = malloc(nw);
if (!b)
return (NULL);

old = old < nw ? old : nw;

while (old--)
b[old] = ((char *)pr)[old];
free(pr);

return (b);
}
