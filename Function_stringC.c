#include "myyshell.h"

/**
 * **strtwords - a function that splits string
 *
 * @strg: string
 *
 * @n: string
 *
 * Return: array of strings,  failure NULL
 */

char **strtwords(char *strg, char *n)
{
int x, q, z, r, nmwrds = 0;
char **c;

if (strg == NULL || strg[0] == 0)
return (NULL);
if (!n)
n = " ";
for (x = 0; strg[x] != '\0'; x++)
if (!is_dlim(strg[x], n) && (is_dlim(strg[x + 1], n) || !strg[x + 1]))
nmwrds++;

if (nmwrds == 0)
return (NULL);
c = malloc((1 + nmwrds) *sizeof(char *));
if (!c)
return (NULL);
for (x = 0, q = 0; q < nmwrds; q++)
{
while (is_dlim(strg[x], n))
x++;
z = 0;
while (!is_dlim(strg[x + z], n) && strg[x + z])
z++;
c[q] = malloc((z + 1) * sizeof(char));
if (!c[q])
{
for (z = 0; z < q; z++)
free(c[z]);
free(c);
return (NULL);
}
for (r = 0; r < z; r++)
c[q][r] = strg[x++];
c[q][r] = 0;
}
c[q] = NULL;
return (c);
}

/**
 * **strtowrds - a function that splits string
 *
 * @strg: string
 *
 * @h: delimeter
 *
 * Return: array of strings, failure NULL
 */

char **strtowrds(char *strg, char h)
{
int x, y, u, j, nmwrds = 0;
char **c;

if (strg == NULL || strg[0] == 0)
return (NULL);
for (x = 0; strg[x] != '\0'; x++)
if ((strg[x] != h && strg[x + 1] == h) ||
(strg[x] != h && !strg[x + 1]) || strg[x + 1] == h)
nmwrds++;
if (nmwrds == 0)
return (NULL);
c = malloc((1 + nmwrds) *sizeof(char *));
if (!c)
return (NULL);
for (x = 0, y = 0; y < nmwrds; y++)
{
while (strg[x] == h && strg[x] != h)
x++;
u = 0;
while (strg[x + u] != h && strg[x + u] && strg[x + u] != h)
u++;
c[y] = malloc((u + 1) * sizeof(char));
if (!c[y])
{
for (u = 0; u < y; u++)
free(c[u]);
free(c);
return (NULL);
}
for (j = 0; j < u; j++)
c[y][j] = strg[x++];
c[y][j] = 0;
}
c[y] = NULL;
return (c);
}
