#include "myyshell.h"

/**
 * _strgcpy - a function that copies string
 *
 * @dst: dstination
 *
 * @sourc: source
 *
 * Return: destination
 */

char *_strgcpy(char *dst, char *sourc)
{
int x = 0;

if (dst == sourc || sourc == 0)
return (dst);
while (sourc[x])
{
dst[x] = sourc[x];
x++;
}
dst[x] = 0;
return (dst);
}

/**
 * _strgdup - a function that duplicates string
 *
 * @strg: string
 *
 * Return: duplicated str
 */

char *_strgdup(const char *strg)
{
int lnth = 0;
char *rtt;

if (strg == NULL)
return (NULL);
while (*strg++)
lnth++;
rtt = malloc(sizeof(char) * (lnth + 1));
if (!rtt)
return (NULL);
for (lnth++; lnth--;)
rtt[lnth] = *--strg;
return (rtt);
}

/**
 * _puuts - a function that prints string
 *
 * @strg: string
 *
 * Return: void
 */

void _puuts(char *strg)
{
int x = 0;

if (!strg)
return;
while (strg[x] != '\0')
{
_putchaar(strg[x]);
x++;
}
}

/**
 * _putchaar - a function that writes char
 * @s: The character to print
 *
 * Return: if success 1 , error -1
 */

int _putchaar(char s)
{
static int x;
static char buff[WR_BUFF_SIZE];

if (s == BUFF_FLSH || x >= WR_BUFF_SIZE)
{
write(1, buff, x);
x = 0;
}
if (s != BUFF_FLSH)
buff[x++] = s;
return (1);
}
