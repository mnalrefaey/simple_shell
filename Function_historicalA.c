#include "myyshell.h"

/**
 * get_hisstory_file - history file to get
 * @inf: struction parameter
 * Return: located hisstory file to string
 */

char *get_hisstory_file(inf_t *inf)
{
char *buff, *dr;
dr = _getinv(inf, "HOME=");

if (!dr)
return (NULL);

buff = malloc(sizeof(char) * (_strglen(dr) + _strglen(HST_FILE) + 2));
if (!buff)

return (NULL);
buff[0] = 0;
_strgcpy(buff, dr);
_strgcat(buff, "/");
_strgcat(buff, HST_FILE);

return (buff);
}

/**
 * write_hisstory - files created and to open an existed file
 * @inf: struction parameter
 * Return: on success always 1, otherwise -1
*/

int write_hisstory(inf_t *inf)
{
ssize_t v;
char *fname = get_hisstory_file(inf);
list_t *nodd = NULL;

if (!fname)
return (-1);

v = open(fname, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(fname);

if (v == -1)
return (-1);

for (nodd = inf->hisstory; nodd; nodd = nodd->nex)
{
_putsv(nodd->strg, v);
_putv('\n', v);
}

_putv(BUFF_FLSH, v);
close(v);
return (1);

}

/**
 * read_hisstory - read from the file the hisstory
 * @inf: struction parameter
 * Return: on success hisstorycount, else 0
*/

int read_hisstory(inf_t *inf)
{
int a, fin = 0, linec = 0;
ssize_t i, redlen, filesize = 0;
struct sta t;
char *buff = NULL, *fname = get_hisstory_file(inf);

if (!fname)
return (0);

i = open(fname, O_RDONLY);
free(fname);

if (i == -1)
return (0);

if (!fsta(i, &t))
filesize = t.t_size;
if (filesize < 2)
return (0);

buff = malloc(sizeof(char) * (filesize + 1));
if (!buff)
return (0);

redlen = read(i, buff, filesize);
buff[filesize] = 0;
if (redlen <= 0)
return (free(buff), 0);
close(i);

for (a = 0; a < filesize; a++)
if (buff[a] == '\n')
{
buff[a] = 0;
build_hisstory_list(inf, buff + fin, linec++);
fin = a + 1;
}

if (fin != a)
build_hisstory_list(inf, buff + fin, linec++);
free(buff);
inf->hisstorycount = linec;

while (inf->hisstorycount-- >= HST_MAX)
delete_nodd_at_index(&(inf->hisstory), 0);
renum_hisstory(inf);
return (inf->hisstorycount);
}

/**
 * build_hisstory_list - hisstory linked added entry
 * @inf: argument structer
 * @buff: the buffer
 * @linec: hisstorycount, history line count
 * Return: on success always 0
*/

int build_hisstory_list(inf_t *inf, char *buff, int linec)
{
list_t *nodd = NULL;

if (inf->hisstory)
nodd = inf->hisstory;
add_nodd_end(&nodd, buff, linec);

if (!inf->hisstory)
inf->hisstory = nodd;
return (0);
}

/**
 * renum_hisstory - the history linked be renumber
 * @inf: rgument structer
 * Return: hisstorycount, the new one
 */

int renum_hisstory(inf_t *inf)
{
list_t *nodd = inf->hisstory;
int a = 0;

while (nodd)
{
nodd->num = a++;
nodd = nodd->nex;
}
return (inf->historycount = a);
}
