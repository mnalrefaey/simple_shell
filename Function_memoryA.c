#include "myyshell.h"

/**
 * bevree - th pointers and NULLs be free from address
 * @pf: pointer's address to be free
 * Return: on success free return 1, else 0
*/

int bevree(void **pf)
{
if (pf && *pf)
{
free(*pf);
*pf = NULL;

return (1);
}
return (0);
}
