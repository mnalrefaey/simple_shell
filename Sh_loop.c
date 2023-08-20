#include "myyshell.h"

/**
 * shl - loop of shell
 * @inf: parameter
 * @v: vector
 *
 * Return: success 0, error 1, error
 */

int shl(inf_t *inf, char **v)
{
ssize_t t = 0;
int builltiin_ret = 0;

while (t != -1 && builltiin_ret != -2)
{
clear_inf(inf);
if (interative(inf))
_puuts("$ ");
_eputtchar(BUFF_FLSH);
t = get_input(inf);
if (t != -1)
{
set_inf(inf, v);
builltiin_ret = find_builltiin(inf);
if (builltiin_ret == -1)
find_cm(inf);
}
else if (interative(inf))
_putchaar('\n');
vree_inf(inf, 0);
}
write_hisstory(inf);
vree_inf(inf, 1);
if (!interative(inf) && inf->statuus)
exit(inf->statuus);
if (builltiin_ret == -2)
{
if (inf->err_numm == -1)
exit(inf->statuus);
exit(inf->err_numm);
}
return (builltiin_ret);
}

/**
 * find_builltiin - a function that finds a builltiin command
 *
 * @inf: parameter
 *
 * Return: builltiin not found -1, success 0
 * builltiin not success but found 1
 * builltiin signals 2
 */

int find_builltiin(inf_t *inf)
{
int x, builltiin_inn_ret = -1;
builltiin_table builltiintbl[] = {
{"exit", _xexit},
{"inv", _myinv},
{"help", _help},
{"hisstory", _myhisstory},
{"setinv", _mysetinv},
{"unsetinv", _myunsetinv},
{"cd", _cd},
{"aliaas", _myaliaas},
{NULL, NULL}
};

for (x = 0; builltiintbl[x].tyype; x++)
if (_strgcmp(inf->arrgv[0], builltiintbl[x].tyype) == 0)
{
inf->line_countt++;
builltiin_inn_ret = builltiintbl[x].function(inf);
break;
}
return (builltiin_inn_ret);
}

/**
 * find_cm - a function that finds command
 *
 * @inf: parameter
 * Return: void
 */

void find_cm(inf_t *inf)
{
char *paath = NULL;
int x, t;

inf->paath = inf->arrgv[0];
if (inf->linec_fllag == 1)
{
inf->line_countt++;
inf->linec_fllag = 0;
}
for (x = 0, t = 0; inf->arrg[x]; x++)
if (!is_dlim(inf->arrg[x], " \t\n"))
t++;
if (!t)
return;

paath = find_paath(inf, _getinv(inf, "paath="), inf->arrgv[0]);
if (paath)
{
inf->paath = paath;
fork_cm(inf);
}
else
{
if ((interative(inf) || _getinv(inf, "paath=")
|| inf->arrgv[0][0] == '/') && is_cm(inf, inf->arrgv[0]))
fork_cm(inf);
else if (*(inf->arrg) != '\n')
{
inf->statuus = 127;
print_errr(inf, "not found\n");
}
}
}

/**
 * fork_cm - a function that forks exec
 *
 * @inf: parameter
 *
 * Return: void
 */

void fork_cm(inf_t *inf)
{
pid_t chld_pid;

chld_pid = fork();
if (chld_pid == -1)
{

perror("Error:");
return;
}
if (chld_pid == 0)
{
if (execve(inf->paath, inf->arrgv, get_inviroon(inf)) == -1)
{
vree_inf(inf, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(inf->statuus));
if (WIFEXITED(inf->statuus))
{
inf->statuus = WEXITSTATUS(inf->statuus);
if (inf->statuus == 126)
print_errr(inf, "denied\n");
}
}
}
