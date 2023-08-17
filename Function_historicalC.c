#include "myyshell.h"

/**
 *_myexit - a function that exits the shell
 *
 *@inf: a structure potential arguments
 *
 *Return: exit (0) if in.argv[0] != "exit"
 */

int _myexit(inf_t *inf)
{

int check;

if (inf->argv[1])
{
check = _erratooi(inf->argv[1]);
if (check == -1)
{
inf->statuus = 2;
print_errr(inf, "Illegal number: ");
_eputts(inf->argv[1]);
_eputtchar('\n');
return (1);
}
inf->err_numm = _erratooi(inf->argv[1]);
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
int chngdir_ret;

s = getcwd(buffr, 1024);
if (s == NULL)
_puuts("TODO: >>gettcwd failure emsg here<<\n");
if (!inf->argv[1])
{
dir = _getinv(inf, "HOME=");
if (dir == NULL)
chngdir_ret = chdir((dir = _getinv(inf, "PWD=")) ? dir : "/");
else
chngdir_ret = chdir(dir);
}
else if (_strgcmp(inf->argv[1], "-") == 0)
{
if (!_getinv(inf, "OLDPWD="))
{
_puuts(s);
_putchaar('\n');
return (1);
}
_puuts(_getinv(inf, "OLDPWD=")), _putchaar('\n');
chngdir_ret = chdir((dir = _getinv(inf, "OLDPWD=")) ? dir : "/");
}
else
chngdir_ret = chdir(inf->argv[1]);
if (chngdir_ret == -1)
{
print_errr(inf, "can't do ");
_eputts(inf->argv[1]), _eputtchar('\n');
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
char **arg_arry;

arg_arry = inf->argv;
_puuts("Function not ready \n");
if (0)
_puuts(*arg_arry);
return (0);
}
