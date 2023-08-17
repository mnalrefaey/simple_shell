#include "myyshell.h"

/**
 * _myhisstory - display history start with 0, one line and one numbers line
 * @inf: structure arguments
 *  Return: success always 0
 */
int _myhisstory(inf_t *inf)
{
	print_list(inf->hisstory);
	return (0);
}
/**
 * unset_aliaas - aliaas set in string
 * @inf: struct
 * @strg: string
 * Return: 0 on success, otherwise 1
 */
int unset_aliaas(inf_t *inf, char *strg)
{
	char *c, g;
	int rt;

	c = _strgchr(strg, '=');
	if (!c)
		return (1);
	g = *c;
	*c = 0;
	rt = delete_nodd_at_index(&(inf->aliaas),
		get_nodd_index(inf->aliaas, nodd_ begin_with(inf->aliaas, strg, -1)));
	*c = g;
	return (rt);
}
/**
 * set_aliaas - the string to aliaas
 * @inf: struct
 * @strg: string aliaas
 * Return: 0 always on success, 1 unsuccess
 */
int set_aliaas(inf_t *inf, char *strg)
{
	char *c;

	c = _strgchr(strg, '=');
	if (!c)
		return (1);
	if (!*++c)
		return (unset_aliaas(inf, strg));

	unset_aliaas(inf, strg);
	return (add_nodd_end(&(inf->aliaas), strg, 0) == NULL);
}

/**
 * print_aliaas - string to print
 * @nodd: node to alias
 * Return: 0 always on success, otherwise 1
 */
int print_aliaas(list_t *nodd)
{
	char *c = NULL, *i = NULL;

	if (nodd)
	{
		c = _strgchr(nodd->strg, '=');
		for (i = nodd->strg; i <= c; i++)
		_putchaar(*i);
		_putchaar('\'');
		_puuts(c + 1);
		_puuts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myaliaas - the alais buitin mimic
 * @inf: struct argument
 *  Return: 0 always
 */
int _myaliaas(inf_t *inf)
{
	int a = 0;
	char *c = NULL;
	list_t *nodd = NULL;

	if (in->argc == 1)
	{
		nodd = in->aliaas;
		while (nodd)
		{
			print_aliaas(nodd);
			nodd = nodd->next;
		}
		return (0);
	}
	for (a = 1; inf->argv[a]; a++)
	{
		c = _strgchr(inf->argv[a], '=');
		if (c)
			set_aliaas(inf, inf->argv[a]);
		else
			print_aliaas(nodd_ begin_with(inf->aliaas, inf->argv[a], '='));
	}

	return (0);
}
