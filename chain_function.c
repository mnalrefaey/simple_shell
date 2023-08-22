#include "myyshell.h"

/**
 * is_chaain - a function that tests chain delimeter
 *
 * @inf: struct
 *
 * @buff: buffr
 *
 * @poss: address
 *
 * Return: chain delimeter 1,  otherwise 0
 */

int is_chaain(inf_t *inf, char *buff, size_t *poss)
{
size_t r = *poss;

if (buff[r] == '|' && buff[r + 1] == '|')
{
buff[r] = 0;
r++;
inf->cm_buff_type = CM_OOR;
}
else if (buff[r] == '&' && buff[r + 1] == '&')
{
buff[r] = 0;
r++;
inf->cm_buff_type = CM_AAND;
}
else if (buff[r] == ';')
{
buff[r] = 0;
inf->cm_buff_type = CM_CHAIN;
}
else
return (0);
*poss = r;
return (1);
}
/**
 * chain_checker - a function that checks chain
 *
 * @inf: struct
 * @buff: buffr
 * @poss: address
 * @x: beginning of position
 * @lnth: lnth of buff
 *
 * Return: Void
 */
void chain_checker(inf_t *inf, char *buff, size_t *poss, size_t x, size_t lnth)
{
size_t r = *poss;
if (inf->cm_buff_type == CM_AAND)
{
if (inf->statuus)
{
buff[x] = 0;
r = lnth;
}
}
if (inf->cm_buff_type == CM_OOR)
{
if (!inf->statuus)
{
buff[x] = 0;
r = lnth;
}
}
*poss = r;
}
/**
 * replace_aliaas - a function that replaces aliaases
 * @inf: parameter
 * Return: replaced 1, otherwise 0
 */
int replace_aliaas (inf_t *inf)
{
int x;
list_t *nodd;
char *poss;
for (x = 0; x < 10; x++)
{
nodd = nodd_begin_with(inf->aliaas, inf->arrgv[0], '=');
if (!nodd)
return (0);
free(inf->arrgv[0]);
poss = _strgchr(nodd->strgr, '=');
if (!poss)
return (0);
poss = _strgdup(poss + 1);
if (!poss)
return (0);
inf->arrgv[0] = poss;
}
return (1);
}

/**
 * vaars_replace - a function that replaces vaars
 *
 * @inf: parameter
 *
 * Return: replaced 1, otherwise 0
 */

int vaars_replace(inf_t *inf)
{
int x = 0;
list_t *nodd;

for (x = 0; inf->arrgv[x]; x++)
{
if (inf->arrgv[x][0] != '$' || !inf->arrgv[x][1])
continue;

if (!_strgcmp(inf->arrgv[x], "$?"))
{
rep_string(&(inf->arrgv[x]),
_strgdup(conv_numb(inf->statuus, 10, 0)));
continue;
}
if (!_strgcmp(inf->arrgv[x], "$$"))
{
rep_string(&(inf->arrgv[x]),
_strgdup(conv_numb(getpid(), 10, 0)));
continue;
}
nodd = nodd_begin_with(inf->inv, &inf->arrgv[x][1], '=');
if (nodd)
{
rep_string(&(inf->arrgv[x]),
_strgdup(_strgchr(nodd->strgr, '=') + 1));
continue;
}
rep_string(&inf->arrgv[x], _strgdup(""));
}
return (0);
}

/**
 * rep_string - a function that replaces string
 *
 * @olstr: address
 *
 * @nwstr: string
 *
 * Return: replaced 1, otherwise 0
 */
int rep_string(char **olstr, char *nwstr)
{
free(*olstr);
*olstr = nwstr;
return (1);
}
