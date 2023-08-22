#include "myyshell.h"

/**
 * is_cm - a function that determines executable command of a file
 *
 * @inf: struct
 *
 * @paath: paath
 *
 * Return: true 1, otherwise 0
 */

int is_cm(inf_t *inf, char *paath)
{
struct stat sst;

(void)inf;
if (!paath || stat(paath, &sst))
return (0);

if (sst.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
 * dupl_chars - a function that duplicates chars
 *
 * @paathstrg: paath string
 *
 * @begin: index starts
 *
 * @end: index stopps
 *
 * Return: new buffr
 */

char *dupl_chars(char *paathstrg, int begin, int end)
{
static char buff[1024];
int x = 0, z = 0;

for (z = 0, x = begin; x < end; x++)
if (paathstrg[x] != ':')
buff[z++] = paathstrg[x];
buff[z] = 0;
return (buff);
}

/**
 * find_paath - a function that finds cm in paath
 *
 * @inf: struct
 *
 * @paathstrg: string
 *
 * @cm: cm
 *
 * Return: paath or NULL
 */

char *find_paath(inf_t *inf, char *paathstrg, char *cm)
{
int x = 0, current_poss = 0;
char *paath;

if (!paathstrg)
return (NULL);
if ((_strglen(cm) > 2) && begin_with(cm, "./"))
{
if (is_cm(inf, cm))
return (cm);
}
while (1)
{
if (!paathstrg[x] || paathstrg[x] == ':')
{
paath = dupl_chars(paathstrg, current_poss, x);
if (!*paath)
_strgcat(paath, cm);
else
{
_strgcat(paath, "/");
_strgcat(paath, cm);
}
if (is_cm(inf, paath))
return (paath);
if (!paathstrg[x])
break;
current_poss = x;
}
x++;
}
return (NULL);
}
