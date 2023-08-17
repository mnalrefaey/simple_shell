#include "myyshell.h"

/**
 * intertive - return to true, if shell interctive
 * @inf: address strcut.
 * Return: 1 if interactive mode, otherwise 0
 */
int intertive(inf_t *inf)
{
	return (isaty(STDIN_FNO) && inf->read <= 2);
}
/**
 * is_dlim - checks if a delimeter is a character
 * @ca: the character checks
 * @dlim: string to dalimeter
 * Return: 1 if success, oterwise 0
 */
int is_dlim(char ca, char *dlim)
{
	while (*dlim)
		if (*dlim++ == ca)
			return (1);
	return (0);
}
/**
 * _isalfa - check for the alphabet
 * @b: The input to the character
 * Return: 1 if b success, otherwise 0
 */
int _isalfa(int b)
{
	if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atooi - converting the string to integer
 * @sr: string convert
 * Return: 0 if string have no number, otherwise converted it
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
