#include "myyshell.h"

/**
 * _myinv - prints invironment
 *
 * @inf: structure arguments
 *
 * Return: Always 0
 */

int _myinv(inf_t *inf)
{
print_lest_strg(inf->env);
return (0);
}

/**
 * _getinv - a function that gets the value
 *
 * @inf: structure arguments
 *
 * @nam: env
 * Return: value
 */

char *_getinv(inf_t *inf, const char *nam)
{
list_t *nodd = inf->env;
char *pr;

while (nodd)
{
pr = begin_with(nodd->strgr, nam);
if (pr && *pr)
return (pr);
nodd = nodd->nex;
}
return (NULL);
}

/**
 * _mysetinv - a function that Initialize a new variable
 *
 * @inf: structure arguments
 *
 *  Return: Always 0
 */

int _mysetinv(inf_t *inf)
{
if (inf->arrgc != 3)
{
_eputts("Incorrect number\n");
return (1);
}
if (_setinv(inf, inf->arrgv[1], inf->arrgv[2]))
return (0);
return (1);
}

/**
 * _myunsetinv - Remove invironment
 *
 * @inf: structure arguments
 *
 * Return: Always 0
 */

int _myunsetinv(inf_t *inf)
{
int j;

if (inf->arrgc == 1)
{
_eputts("few arguements.\n");
return (1);
}
for (j = 1; j <= inf->arrgc; j++)
_unsetinv(inf, inf->arrgv[j]);
return (0);
}

/**
 * populate_inv_lst - linked list
 *
 * @inf: structure arguments
 *
 * Return: Always 0
 */

int populate_inv_lst(inf_t *inf)
{
list_t *nodd = NULL;
size_t j;

for (j = 0; environ[j]; j++)
add_nodd_end(&nodd, environ[j], 0);
inf->env = nodd;
return (0);
}
