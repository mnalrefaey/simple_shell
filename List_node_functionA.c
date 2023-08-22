#include "myyshell.h"

/**
 * add_nodd - a function that adds a nodd
 *
 * @heed: address
 *
 * @strgr: strgr of nodd
 *
 * @numm: nodd index
 *
 * Return: the size
 */

list_t *add_nodd(list_t **heed, const char *strgr, int numm)
{
list_t *new_heed;

if (heed == NULL)
return (NULL);
new_heed = malloc(sizeof(list_t));
if (new_heed == NULL)
return (NULL);
_memst((void *)new_heed, 0, sizeof(list_t));
new_heed->numm = numm;
if (strgr)
{
new_heed->strgr = _strgdup(strgr);
if (!new_heed->strgr)
{
free(new_heed);
return (NULL);
}
}
new_heed->nex = *heed;
*heed = new_heed;
return (new_heed);
}

/**
 * add_nodd_end - a function that adds a nodd
 *
 * @heed: address
 *
 * @strgr: strgr field
 *
 * @numm: nodd index
 *
 * Return: the size
 */

list_t *add_nodd_end(list_t **heed, const char *strgr, int numm)
{
list_t *new_nodd, *nodd;

if (heed == NULL)
return (NULL);

nodd = *heed;
new_nodd = malloc(sizeof(list_t));
if (new_nodd == NULL)
return (NULL);
_memst((void *)new_nodd, 0, sizeof(list_t));
new_nodd->numm = numm;
if (strgr)
{
new_nodd->strgr = _strgdup(strgr);
if (!new_nodd->strgr)
{
free(new_nodd);
return (NULL);
}
}
if (nodd)
{
while (nodd->nex)
nodd = nodd->nex;
nodd->nex = new_nodd;
}
else
*heed = new_nodd;
return (new_nodd);
}

/**
 * print_lest_strg - a function that prints element
 *
 * @g: pointer
 *
 * Return: the size
 */

size_t print_lest_strg(const list_t *g)
{
size_t x = 0;

while (g)
{
_puuts(g->strgr ? g->strgr : "(nil)");
_puuts("\n");
g = g->nex;
x++;
}
return (x);
}

/**
 * remove_nodd - a function that removes nodd
 *
 * @heed: address
 *
 * @indx: index of nodd
 *
 * Return: success 1, failure 0
 */

int delete_nodd_at_index(list_t **heed, unsigned int indx)
{
list_t *nodd, *prev_nodd;
unsigned int x = 0;

if (!heed || !*heed)
return (0);

if (!indx)
{
nodd = *heed;
*heed = (*heed)->nex;
free(nodd->strgr);
free(nodd);
return (1);
}
nodd = *heed;
while (nodd)
{
if (x == indx)
{
prev_nodd->nex = nodd->nex;
free(nodd->strgr);
free(nodd);
return (1);
}
x++;
prev_nodd = nodd;
nodd = nodd->nex;
}
return (0);
}

/**
 * vrree_lst - a function that frees nodds

 * @heed_prt: the address of pointer
 *
 * Return: void
 */

void vrree_lst(list_t **heed_prt)
{
list_t *nodd, *nex_nodd, *heed;

if (!heed_prt || !*heed_prt)
return;
heed = *heed_prt;
nodd = heed;
while (nodd)
{
nex_nodd = nodd->nex;
free(nodd->strgr);
free(nodd);
nodd = nex_nodd;
}
*heed_prt = NULL;
}
