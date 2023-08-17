#include "myyshell.h"

/**
 * Interative - a function that returns true if shell is Interative
 *
 * @inf: struct address
 * Return: If interative mode returns 1, otherwise 0
 */
 
int Interative(inf_t *inf)
{
return (isatty(STDIN_FILENO) && inf->rdf <= 2);
}

/**
 * is_dlim - checks delimeter of character
 *
 * @ca: checks the char
 *
 * @dlim: string
 
 * Return: If true returns 1, if false 0
 */
 
int is_dlim(char ca, char *dlim)
{
while (*dlim)
if (*dlim++ == ca)
return (1);
return (0);
}

/**
 * _isalfa - a function that checks alphabetic character
 *
 * @b: a character
 * Return: if b is alphabetic returns 1, otherwise 0
 */
 
 int _isalfa(int b)
{
if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
return (1);
else
return (0);
}

/**
 * _atooi - a function that converts a string to an integer
 *
 * @sr: the string
 * Return: if no numbers returns 0, otherwise returns converted number
 */

int _atooi(char *sr)
{
int a, sin = 1, flg = 0, oput;
unsigned int answer = 0;

for (a = 0; sr[a] != '\0' && flg != 2; a++)
{
if (sr[a] == '-')
sin *= -1;

if (sr[a] >= '0' && sr[a] <= '9')
{
flg = 1;
answer *= 10;
answer += (sr[a] - '0');
}
else if (flg == 1)
flg = 2;
}
		
if (sin == -1)
oput = -answer;
else
oput = answer;

return (oput);
}
