#include "myyshell.h"

/**
 * _myhisstory - function show the history list and start in 0
 * @inf: arguments structure
 *  Return: on success always 0
*/
 
int _myhisstory(inf_t *inf)
{
print_lest(inf->hisstory);
return (0);
}

/**
 * unset_aliaas - the string that we set alaais
 * @inf:  struct paraments
 * @strg: the string
 * Return: on success 0, else 1
*/
 
int unset_aliaas(inf_t *inf, char *strg)
{
char *b, g;
int rt;

b = _strgchr(strg, '=');
if (!b)
return (1);

g = *b;
*b = 0;
rt = delete_nodd_at_index(&(inf->aliaas),
    get_nodd_index(inf->aliaas, nodd_begin_with(inf->aliaas, strg, -1)));
*b = g;
return (rt);
}

/**
 * set_aliaas - the string that we set alaais
 * @inf: struct
 * @strg: the string
 * Return: on success 0, else 1
*/

int set_aliaas(inf_t *inf, char *strg)
{
char *b;

b = _strgchr(strg, '=');
if (!b)
return (1);

if (!*++b)
return (unset_aliaas(inf, strg));

unset_aliaas(inf, strg);
return (add_nodd_end(&(inf->aliaas), strg, 0) == NULL);
}

/**
 * print_aliaas - prints string aliaas
 * @nodd: the nodd aliaas
 * Return: on success 0, else 1
*/

int print_aliaas(list_t *nodd)
{
char *b = NULL, *i = NULL;

if (nodd)
{
b = _strgchr(nodd->strgr, '=');
for (i = nodd->strgr; i <= b; i++)
    
_putchaar(*i);
_putchaar('\'');
_puuts(b + 1);
_puuts("'\n");
return (0);
}

return (1);
}

/**
 * _myaliaas - mimics the aliaas builltiin
 * @in: structure containing potential arguments
 * Return: on success always 0
*/

int _myaliaas(inf_t *in)
{
int a = 0;
char *b = NULL;
list_t *nodd = NULL;

if (in->arrgc == 1)
{
nodd = in->aliaas;

while (nodd)
{
print_aliaas(nodd);
nodd = nodd->nex;
}

return (0);
}
for (a = 1; in->arrgv[a]; a++)
{
b = _strgchr(in->arrgv[a], '=');
if (b)
set_aliaas(in, in->arrgv[a]);

else
print_aliaas(nodd_begin_with(in->aliaas, in->arrgv[a], '='));
}
return(0);
}
