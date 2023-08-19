#include "myyshell.h"

/**
 * inpt_buff - commands of buffrs
 *
 * @inf: struct
 *
 * @buff: address
 *
 * @ln:  ln variable address
 *
 * Return: bytes
 */

ssize_t inpt_buff(inf_t *inf, char **buff, size_t *ln)
{
ssize_t m = 0;
size_t ln_p = 0;

if (!*ln)
{
free(*buff);
*buff = NULL;
signal(SIGINT, siginhand);
#if USING_GETLINE
m = getline(buff, &ln_p, stdin);
#else
m = _getline(inf, buff, &ln_p);
#endif
if (m > 0)
{
if ((*buff)[m - 1] == '\n')
{
(*buff)[m - 1] = '\0';
m--;
}
inf->linec_fllag = 1;
rv_comms(*buff);
build_hisstory_list(inf, *buff, inf->historycount++);
{
*ln = m;
inf->cm_buff = buff;
}
}
}
return (m);
}

/**
 * get_inpt - a function that gets minus of line
 *
 * @inf: struct
 *
 * Return: bytes
 */

ssize_t get_inpt(inf_t *inf)
{
static char *buff;
static size_t x, k, ln;
ssize_t d = 0;
char **buff_p = &(inf->arrg), *t;

_putchaar(BUFF_FLSH);
d = inpt_buff(inf, &buff, &ln);
if (d == -1)
return (-1);
if (ln)
{
k = x;
t = buff + x;
chain_checker(inf, buff, &k, x, ln);
while (k < ln)
{
if (is_chaain(inf, buff, &k))
break;
k++;
}
x = k + 1;
if (x >= ln)
{
x = ln = 0;
inf->cm_buff_type = CM_NRM;
}
*buff_p = t;
return (_strglen(t));
}

*buff_p = buff;
return (d);
}

/**
 * rd_bufff - a function that reads a bufffr
 *
 * @inf: struct
 *
 * @buff: bufffr
 *
 * @x: size
 *
 * Return: m
 */

ssize_t rd_bufff(inf_t *inf, char *buff, size_t *x)
{
ssize_t m = 0;

if (*x)
return (0);
m = read(inf->rdf, buff, RD_BUFF_SIZE);
if (m >= 0)
*x = m;
return (m);
}

/**
 * _getline - a function that gets nex line
 *
 * @inf: struct
 *
 * @prt: a pointer address
 *
 * @lnth: size of prt
 *
 * Return: c
 */

int _getline(inf_t *inf, char **prt, size_t *lnth)
{
static char buff[RD_BUFF_SIZE];
static size_t x, ln;
size_t t;
ssize_t m = 0, c = 0;
char *pb = NULL, *new_pb = NULL, *kh;

pb = *prt;
if (pb && lnth)
c = *lnth;
if (x == ln)
x = ln = 0;

m = rd_bufff(inf, buff, &ln);
if (m == -1 || (m == 0 && ln == 0))
return (-1);

kh = _strgchr(buff + x, '\n');
t = kh ? 1 + (unsigned int)(kh - buff) : ln;
new_pb = _reallocate(pb, c, c ? c + t : t + 1);
if (new_pb == NULL)
return (pb ? free(pb), -1 : -1);

if (c)
_strgncat(new_pb, buff + x, t - x);
else
_strgncpy(new_pb, buff + x, t - x + 1);

c += t - x;
x = t;
pb = new_pb;

if (lnth)
*lnth = c;
*prt = pb;
return (c);
}

/**
 * siginhand - blcks Ctrl and C
 *
 * @sg_number: signal
 *
 * Return: void
 */

void siginhand(__attribute__((unused))int sg_number)
{
_puuts("\n");
_puuts("$ ");
_putchaar(BUFF_FLSH);
}
