#include "myyshell.h"

/**
 *_myexit - a function that exits the shell
 *
 *@inf: a structure potential arguments
 *
 *Return: exit (0) if in.arrgv[0] != "exit"
 */

int _myexit(inf_t *inf)
{

int check;

if (inf->arrgv[1])
{
check = _erratooi(inf->arrgv[1]);
if (check == -1)
{
inf->statuus = 2;
print_errr(inf, "Illegal number: ");
_eputts(inf->arrgv[1]);
_eputtchar('\n');
return (1);
}
inf->err_numm = _erratooi(inf->arrgv[1]);
return (-2);
}
inf->err_numm = -1;
return (-2);
}

/**
 *_cd - a function that changes the directory
 *
 *@inf: structure containing  arguments
 *
 *Return: Always 0
 */

int _cd(inf_t *inf)
{
char *s, *dir, buffr[1024];
int chdir_rit;

s = getcwd(buffr, 1024);
if (s == NULL)
_puuts("TODO: >>getcwd failure here<<\n");
if (!inf->arrgv[1])
{
dir = _getinv(inf, "HOME=");
if (dir == NULL)
chdir_rit = chdir((dir = _getinv(inf, "PWD=")) ? dir : "/");
else
chdir_rit = chdir(dir);
}
else if (_strgcmp(inf->arrgv[1], "-") == 0)
{
if (!_getinv(inf, "OLDPWD="))
{
_puuts(s);
_putchaar('\n');
return (1);
}
_puuts(_getinv(inf, "OLDPWD=")), _putchaar('\n');
chdir_rit = chdir((dir = _getinv(inf, "OLDPWD=")) ? dir : "/");
}
else
chdir_rit = chdir(inf->arrgv[1]);
if (chdir_rit == -1)
{
print_errr(inf, "can't do ");
_eputts(inf->arrgv[1]), _eputtchar('\n');
}
else
{
_setinv(inf, "OLDPWD", _getinv(inf, "PWD="));
_setinv(inf, "PWD", getcwd(buffr, 1024));
}
return (0);
}

/**
 * _help - a function that changes the  directory
 *
 * @inf: structure containing arguments
 *
 * Return: Always 0
 */

int _help(inf_t *inf)
{
char **arrg_arry;

arrg_arry = inf->arrgv;
_puuts("Function not ready \n");
if (0)
_puuts(*arrg_arry);
return (0);
}
