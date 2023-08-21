#include "myyshell.h"

/**
 * main - a function indicates to point of entry
 *
 * @arcount: count
 *
 * @arvect: vector
 *
 * Return: 0 on success, 1 on error
 */

int main(int arcount, char **arvect)
{
inf_t inf[] = { INFRMATION_INIT };
int f = 2;

asm("mov %1, %0\n\t"
"add $3, %0"
: "=r" (f)
: "r" (f));

if (arcount == 2)
{
f = open(arvect[1], O_RDONLY);
if (f == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputts(arvect[0]);
_eputts(": 0: Can not open ");
_eputts(arvect[1]);
_eputtchar('\n');
_eputtchar(BUFF_FLSH);
exit(127);
}
return (EXIT_FAILURE);
}
inf->rdf = f;
}
populate_inv_lst(inf);
read_hisstory(inf);
haash(inf, arvect);
return (EXIT_SUCCESS);
}
