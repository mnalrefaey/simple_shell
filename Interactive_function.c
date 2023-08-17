#include "myyshell.h"

/**
<<<<<<< HEAD
 * Interative - a function that returns true if shell is Interative
 *
 * @inf: struct address
 * Return: If interative mode returns 1, otherwise 0
 */
 
int Interative(inf_t *inf)
{
return (isatty(STDIN_FILENO) && inf->rdf <= 2);
=======
 * intertive - return to true, if shell interctive
 * @inf: address strcut.
 * Return: 1 if interactive mode, otherwise 0
 */
int intertive(inf_t *inf)
{
	return (isaty(STDIN_FNO) && inf->read <= 2);
>>>>>>> b4018b73e90115db92d9bf52b5e9d0566014a3e0
}
/**
<<<<<<< HEAD
 * is_dlim - checks delimeter of character
 *
 * @ca: checks the char
 *
 * @dlim: string
 
 * Return: If true returns 1, if false 0
=======
 * is_dlim - checks if a delimeter is a character
 * @ca: the character checks
 * @dlim: string to dalimeter
 * Return: 1 if success, oterwise 0
>>>>>>> b4018b73e90115db92d9bf52b5e9d0566014a3e0
 */
 
int is_dlim(char ca, char *dlim)
{
while (*dlim)
if (*dlim++ == ca)
return (1);
return (0);
}
/**
<<<<<<< HEAD
 * _isalfa - a function that checks alphabetic character
 *
 * @b: a character
 * Return: if b is alphabetic returns 1, otherwise 0
 */
 
 int _isalfa(int b)
=======
 * _isalfa - check for the alphabet
 * @b: The input to the character
 * Return: 1 if b success, otherwise 0
 */
int _isalfa(int b)
>>>>>>> b4018b73e90115db92d9bf52b5e9d0566014a3e0
{
if ((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z'))
return (1);
else
return (0);
}
/**
<<<<<<< HEAD
 * _atooi - a function that converts a string to an integer
 *
 * @sr: the string
 * Return: if no numbers returns 0, otherwise returns converted number
=======
 * _atooi - converting the string to integer
 * @sr: string convert
 * Return: 0 if string have no number, otherwise converted it
>>>>>>> b4018b73e90115db92d9bf52b5e9d0566014a3e0
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
