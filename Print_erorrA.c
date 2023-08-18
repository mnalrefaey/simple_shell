#include "myyshell.h"

/**
 * _erratooi - a function that converts string to integer
 *
 * @sg: string
 *
 * Return: if no numbers in string Return 0,
 * otherwise converted number, error -1
 */

int _erratooi(char *sg)
{
int p = 0;
unsigned long int sum = 0;

if (*sg == '+')
sg++;
for (p = 0;  sg[p] != '\0'; p++)
{
if (sg[p] >= '0' && sg[p] <= '9')
{
sum *= 10;
sum += (sg[p] - '0');
if (sum > INT_MAX)
return (-1);
}
else
return (-1);
}
return (sum);
}

/**
 * print_errr - a function that prints error message
 *
 * @inf: parameter
 *
 * @estrg: string
 *
 * Return: if no numbers in string return 0,
 * otherwise converted number, error -1
 */

void print_errr(inf_t *inf, char *estrg)
{
_eputts(inf->filen);
_eputts(": ");
prent_d(inf->line_countt, STDERR_FILENO);
_eputts(": ");
_eputts(inf->argv[0]);
_eputts(": ");
_eputts(estrg);
}

/**
 * prent_d - a function that prints a decimal number
 *
 * @inp: input
 * @f: file descriptor
 *
 * Return: number of characters
 */

int prent_d(int inp, int f)
{
int (*__putchaar)(char) = _putchaar;
int p, sum = 0;
unsigned int _acs_, curr;

if (f == STDERR_FILENO)
__putchaar = _eputtchar;
if (inp < 0)
{
_acs_ = -inp;
__putchaar('-');
sum++;
}
else
_acs_ = inp;
curr = _acs_;
for (p = 1000000000; p > 1; p /= 10)
{
if (_acs_ / p)
{
__putchaar('0' + curr / p);
sum++;
}
curr %= p;
}
__putchaar('0' + curr);
sum++;

return (sum);
}

/**
 * conv_numb - a function to convert
 *
 * @numb: number
 * @set: base
 * @flg: argument flags
 * Return: string
 */

char *conv_numb(long int numb, int set, int flg)
{
static char *arry;
static char buffr[50];
char sin = 0;
char *pttr;
unsigned long nam = numb;

if (!(flg & CONV_UNSIGNED) && numb < 0)
{
nam = -numb;
sin = '-';

}
arry = flg & CONV_LWCASE ? "0123456789abcdef" : "0123456789ABCDEF";
pttr = &buffr[49];
*pttr = '\0';

do	{
*--pttr = arry[nam % set];
nam /= set;
} while (nam != 0);

if (sin)
*--pttr = sin;
return (pttr);
}

/**
 * rv_comms - a function that replaces first instance
 *
 * @buff: address of string
 *
 * Return: Always 0;
 */

void rv_comms(char *buff)
{
int p;

for (p = 0; buff[p] != '\0'; p++)
if (buff[p] == '#' && (!p || buff[p - 1] == ' '))
{
buff[p] = '\0';
break;
}
}
