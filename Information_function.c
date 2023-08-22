#include "myyshell.h"

/**
 * clear_inf - a function that initializes struct
 *
 * @inf: address
 */

void clear_inf(inf_t *inf)
{
inf->arrg = NULL;
inf->arrgv = NULL;
inf->paath = NULL;
inf->arrgc = 0;
}

/**
 * set_inf - a function that initializes struct
 *
 * @inf: address
 *
 * @v: vector
 */

void set_inf(inf_t *inf, char **v)
{
int x = 0;

inf->filen = v[0];
if (inf->arrg)
{
inf->arrgv = strtwords(inf->arrg, " \t");
if (!inf->arrgv)
{
inf->arrgv = malloc(sizeof(char *) * 2);
if (inf->arrgv)
{
inf->arrgv[0] = _strgdup(inf->arrg);
inf->arrgv[1] = NULL;
}
}
for (x = 0; inf->arrgv && inf->arrgv[x]; x++)
;
inf->arrgc = x;

replace_aliaas(inf);
replace_fars(inf);
}
}

/**
 * vree_inf - a function that frees struct
 *
 * @inf: address
 *
 * @every:  if frees fields true
 */

void vree_inf(inf_t *inf, int every)
{
vrree(inf->arrgv);
inf->arrgv = NULL;
inf->paath = NULL;
if (every)
{
if (!inf->cm_buff)
free(inf->arrg);
if (inf->inv)
vrree_lst(&(inf->inv));
if (inf->hisstory)
vrree_lst(&(inf->hisstory));
if (inf->aliaas)
vrree_lst(&(inf->aliaas));
vrree(inf->inviroon);
inf->inviroon = NULL;
bevree((void **)inf->cm_buff);
if (inf->rdf > 2)
close(inf->rdf);
_putchaar(BUFF_FLSH);
}
}
