#include "myyshell.h"

/**
 * interactive - returns true if shell is interactive
 * @inf: struct address
 * Return: 1 if interactive mode, otherwise 0
 */
int interactive(inf_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->read <= 2);
}

/**
 * is_dlim - checks if character is a delimeter
 * @ca: the char to check
 * @dlim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_dlim(char ca, char *dlim)
{
	while (*dlim)
		if (*dlim++ == ca)
			return (1);
	return (0);
}

/**
 * _isalfa - checks for alphabetic character
 * @b: The character to input
 * Return: 1 if b is alphabetic, otherwise 0
 */

int _isalfa(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atooi - converts a string to an integer
 * @sr: the string to be converted
 * Return: 0 if no numbers in string, otherwise converted number
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
