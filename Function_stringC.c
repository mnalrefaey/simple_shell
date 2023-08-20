#include "myyshell.h"

/**
 * **strgtw - function that split the string
 * @strgr: the string input
 * @dl: the string delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strgtw(char *strgr, char *dl)
{
int a, g, o, n = 0;
int wnum = 0;
char **c;

if (strgr == NULL || strgr[0] == 0)
return (NULL);
if (!dl)
dl = " ";
for (a = 0; strgr[a] != '\0'; a++)
if (!is_dlim(strgr[a], dl) && (is_dlim(strgr[a + 1], dl) || !strgr[a + 1]))
wnum++;
if (wnum == 0)
return (NULL);
c = malloc((1 + wnum) *sizeof(char *));
if (!c)
return (NULL);
for (a = 0, g = 0; g < wnum; g++)
{
while (is_dlim(strgr[a], dl))
a++;
o = 0;
while (!is_dlim(strgr[a + o], dl) && strgr[a + o])
o++;
c[g] = malloc((o + 1) * sizeof(char));
if (!c[g])
{
for (o = 0; o < g; o++)
free(c[o]);
free(c);
return (NULL);
}
for (n = 0; n < o; n++)
c[g][n] = strgr[a++];
c[g][n] = 0;
}
c[g] = NULL;
return (c);
}

/**
 * **strgtwb - function that split the string
 * @strgr: the input string
 * @dl: the string delimeter
 * Return: a pointer to an array of strings, or NULL on failure
*/

char **strgtwb(char *strgr, char dl)
{
int a, g, o, n = 0;
int wnum = 0;
char **c;

if (strgr == NULL || strgr[0] == 0)
return (NULL);
for (a = 0; strgr[a] != '\0'; a++)
if ((strgr[a] != dl && strgr[a + 1] == dl) ||
(strgr[a] != dl && !strgr[a + 1]) || strgr[a + 1] == dl)
wnum++;
if (wnum == 0)
return (NULL);
c = malloc((1 + wnum) *sizeof(char *));
if (!c)
return (NULL);
for (a = 0, g = 0; g < wnum; g++)
{
while (strgr[a] == dl && strgr[a] != dl)
a++;
o = 0;
while (strgr[a + o] != dl && strgr[a + o] && strgr[a + o] != dl)
o++;
c[g] = malloc((o + 1) * sizeof(char));
if (!c[g])
{
for (o = 0; o < g; o++)
free(c[o]);
free(c);
return (NULL);
}
for (n = 0; n < o; n++)
c[g][n] = strgr[a++];
c[g][n] = 0;
}
c[g] = NULL;
return (c);
}
