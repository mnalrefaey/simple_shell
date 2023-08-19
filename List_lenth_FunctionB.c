#include "myyshell.h"

/**
 * list_lenth - the lenght determined linked list
 * @g: the first nodd pointer
 * Return: the list size
*/

size_t list_lenth(const list_t *g)
{
size_t a = 0;

while (g)
{
g = g->nex;
a++;
}

return (a);
}

/**
 * list_t_string - returns an array of strings of the list->strg
 * @hd: pointer to first nodd
 * Return: array of strings
*/

char **list_t_string(list_t *hd)
{
list_t *nodd = hd;
size_t a = list_lenth(hd), k;
char **strgrs;
char *strgr;

if (!hd || !a)
return (NULL);
strgrs = malloc(sizeof(char *) * (a + 1));

if (!strgrs)
return (NULL);

for (a = 0; nodd; nodd = nodd->nex, a++)
{
strgr = malloc(_strglen(nodd->strgr) + 1);

if (!strgr)
{
for (k = 0; k < a; k++)
free(strgrs[k]);
free(strgrs);
return (NULL);
}

strgr = _strgcpy(strgr, nodd->strgr);
strgrs[a] = strgr;

}
strgrs[a] = NULL;
return (strgrs);
}

/**
 * print_lest - prints all elements of a list_t linked list
 * @g: pointer to first nodd
 *
 * Return: size of list
*/

size_t print_lest(const list_t *g)
{
size_t a = 0;

while (g)
{
_puuts(conv_numb(g->numm, 10, 0));
_putchaar(':');
_putchaar(' ');
_puuts(g->strgr ? g->strgr : "(nil)");
_puuts("\n");
g = g->nex;
a++;

}
return (a);
}

/**
 * nodd_begin_with - string return to nodd begin with pfix
 * @nodd: the pointer head
 * @pfix: match the string
 * @s: the character match
 * Return: NULL, or the match nodd
*/

list_t *nodd_begin_with(list_t *nodd, char *pfix, char s)
{
char *b = NULL;

while (nodd)
{
b = begin_with(nodd->strgr, pfix);

if (b && ((s == -1) || (*b == s)))
return (nodd);
nodd = nodd->nex;
}
return (NULL);
}

/**
 * get_nodd_index - gets the index of a nodd
 * @hd: pointer head
 * @nodd: pointer nodd
 * Return: return index, or -1
*/

ssize_t get_nodd_index(list_t *hd, list_t *nodd)
{
size_t a = 0;

while (hd)
{
if (hd == nodd)
return (a);

hd = hd->nex;
a++;

}
return (-1);
}
