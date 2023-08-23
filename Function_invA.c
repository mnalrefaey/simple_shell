#include "myyshell.h"

/**
 * get_inviroon - for the string array copy returns
 * @inf: arguments containing structure
 * Return:on success always 0
 */

char **get_inviroon(inf_t *inf)
{
if (!inf->environ || inf->inv_changed)
{
inf->environ = list_t_strings(inf->env);
inf->inv_changed = 0;

}
return (inf->environ);
}

/**
 * _unsetinv - variable removed from an environ
 * @inf: argument structure
 * @vr: property string
 * Return: on success deleting 1, else 0
*/

int _unsetinv(inf_t *inf, char *vr)
{
list_t *nodd = inf->env;
size_t a = 0;
char *b;

if (!nodd || !vr)
return (0);

while (nodd)
{
b = begin_with(nodd->strgr, vr);

if (b && *b == '=')
{
inf->inv_changed = delete_nodd_at_index(&(inf->env), a);
a = 0;
nodd = inf->env;
continue;

}
nodd = nodd->nex;
a++;

}
return (inf->inv_changed);

}

/**
 * _setinv - new inveroon variable initializest
 * @inf: argument structure
 * @vr: property string
 * @vlu: the value of the string variable
 *  Return: on success always 0
*/

int _setinv(inf_t *inf, char *vr, char *vlu)
{
char *buff = NULL;
list_t *nodd;
char *b;

if (!vr || !vlu)
return (0);

buff = malloc(_strglen(vr) + _strglen(vlu) + 2);
if (!buff)
return (1);
_strgcpy(buff, vr);
_strgcat(buff, "=");
_strgcat(buff, vlu);
nodd = inf->env;

while (nodd)
{
b = begin_with(nodd->strgr, vr);
if (b && *b == '=')
{
free(nodd->strgr);
nodd->strgr = buff;
inf->inv_changed = 1;

return (0);
}
nodd = nodd->nex;

}
add_nodd_end(&(inf->env), buff, 0);
free(buff);
inf->inv_changed = 1;

return (0);
}
