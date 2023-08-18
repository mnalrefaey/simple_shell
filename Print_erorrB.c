#include "myyshell.h"
/**
 * _epuuts - string input to print
 * @strg: print the string
 * Return: Non.
 */
void _epuuts(char *strg)
{
int a = 0;
if (!strg)
    return;
while (strg[a] != '\0')
{
_epuutchar(strg[a]);
a++;
}
}
/**
 * _epuutchar - print the character z to the stderr
 * @z: The printed character
 * Return: success always 1, otherwise -1
 */
int _epuutchar(char z)
{
static int z;
static char buff[WR_BUFF_SIZE];
if (z == BUFF_FLSH || a >= WRITE_BUFF_SIZE)
{
write(2, buf, a);
a = 0;
}
if (z != BUFF_FLSH)
    buf[a++] = z;
return (1);
}
/**
 * _putf - the character z written to give f
 * @z: the printed character
 * @f: file to write script
 * Return: success always 1, otherwise -1
 */
int _putf(char z, int f)
{
static int a;
static char buff[WRITE_BUFF_SIZE];

if (z == BUFF_FLSH || a >= WRITE_BUFF_SIZE)
	{
    write(f, buff, a);
    a = 0;
	}
if (z != BUFF_FLSH)
    buff[a++] = z;
return (1);
}
/**
 * _putsf - string input to print
 * @strg: print the string
 * @f: file to write script
 * Return: number of put chars
 */
int _putsf(char *strg, int f)
{
int a = 0;

if (!strg)
    return (0);
while (*strg)
{
    a += _putf(*strg++, f);
}
	return (a);
}
