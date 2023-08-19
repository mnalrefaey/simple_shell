#ifndef MYYSHELL_H_INCLUDED
#define MYYSHELL_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

/*RD\WR buff*/
#define WR_BUFF_SIZE 1024
#define RD_BUFF_SIZE 1024
#define BUFF_FLSH -1

/*chain_memory*/
#define CM_NRM 0
#define CM_OOR 1
#define CM_AAND 2
#define CM_CHAIN 3

/*conv_numb()*/
#define CONV_LWCASE 1
#define CONV_UNSIGNED 2

/*system_getline()*/
#define USING_STRTOK 0
#define USING_GETLINE 0

#define HST_FILE ".simple_shell_hist"
#define HST_MAX 4096

extern char **inviroon;

/**
 * struct lststrg - singly list
 * @numm: number
 * @strgr: string
 * @nex: next node
 */

typedef struct lststrg
{
int numm;
char *strgr;
struct lststrg *nex;
} list_t;

/**
 * struct pasinfrmation - a function that contains pseudo-argu to pass
 * and allowing prototype for struct
 * @arrg: generated string
 * @aliaas: aliaas node
 * @inv_changed: if inviroon was changed
 * @hisstory: hisstory node
 * @paath: a paath string
 * @historycount: the hisstory line number count
 * @rdf: to read the input of line
 * @statuus: the return statuus of the last exec'd command
 * @inviroon: a modified copy of inviroon
 * @arrgv:array of strings
 * @arrgc: count of argument
 * @cm_buff_type: CM_type
 * @line_countt: count error
 * @cm_buff: an address of pointer
 * @err_numm: exit for code error
 * @filen: filename
 * @inv: copy of inviroon
 * @linec_fllag: if on count this line of input
 */

typedef struct pasinfrmation
{
char *arrg;
char **arrgv;
char *paath;
int arrgc;
unsigned int line_countt;
int err_numm;
int linec_fllag;
char *filen;
list_t *inv;
list_t *hisstory;
list_t *aliaas;
char **inviroon;
int inv_changed;
int statuus;
char **cm_buff;
int cm_buff_type;
int rdf;
int historycount;
} inf_t;

#define INFRMATION_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct builltiin - a builtin string
 * @tyype: flag of builtin command
 * @function: a function
 */

typedef struct builltiin
{
char *tyype;
int (*function)(inf_t *);
} builltiin_table;


/*sh_loop.c*/
int hsh(inf_t *, char **);
int find_builltiin(inf_t *);
void find_cm(inf_t *);
void fork_cm(inf_t *);

/*duplicate_function.c*/
int is_cm(inf_t *, char *);
char *dupl_chars(char *, int, int);
char *find_paath(inf_t *, char *, char *);

/*loofsh.c*/
int loofsh(char **);

/* print_erorrB.c */
void _eputts(char *);
int _eputtchar(char);
int _putf(char c, int f);
int _putsf(char *strg, int f);

/*function_stringA.c*/
int _strglen(char *);
int _strgcmp(char *, char *);
char *begin_with(const char *, const char *);
char *_strgcat(char *, char *);

/*function_stringB.c*/
char *_strgcpy(char *, char *);
char *_strgdup(const char *);
void _puuts(char *);
int _putchaar(char);

/*function_stringEx.c*/
char *_strgncpy(char *, char *, int);
char *_strgncat(char *, char *, int);
char *_strgchr(char *, char);

/*function_stringC.c*/
char **strgtow(char *, char *);
char **strgtow2(char *, char);

/*function_memoryB.c*/
char *_memst(char *, char, unsigned int);
void vree(char **);
void *_reallocate(void *, unsigned int, unsigned int);

/*function_memoryA.c*/
int bevree(void **);

/* Interative_function.c*/
int interative(inf_t *);
int is_dlim(char, char *);
int _isalfa(int);
int _atooi(char *);

/*print_erorrA.c*/
int _erratooi(char *);
void print_errr(inf_t *, char *);
int prent_d(int, int);
char *conv_numb(long int, int, int);
void rv_comms(char *);

/*Function_historicalC.c */
int _myexit(inf_t *);
int _mycd(inf_t *);
int _myhelp(inf_t *);

/*Function_historicalB.c*/
int _myhisstory(inf_t *);
int _myaliaas(inf_t *);

/*line_function.c*/
ssize_t get_input(inf_t *);
int _getline(inf_t *, char **, size_t *);
void siginhand(int);

/*information_function.c*/
void clear_inf(inf_t *);
void set_inf(inf_t *, char **);
void vree_inf(inf_t *, int);

/*function_invB.c*/
char *_getinv(inf_t *, const char *);
int _myinv(inf_t *);
int _mysetinv(inf_t *);
int _myunsetinv(inf_t *);
int populate_inv_lst(inf_t *);

/*function_invA.c*/
char **get_inviroon(inf_t *);
int _unsetinv(inf_t *, char *);
int _setinv(inf_t *, char *, char *);

/*Function_historicalA.c*/
char *get_hisstory_file(inf_t *inf);
int write_hisstory(inf_t *inf);
int read_hisstory(inf_t *inf);
int build_hisstory_list(inf_t *inf, char *buff, int linec);
int renumber_hisstory(inf_t *inf);

/*List_node_functionA.c*/
list_t *add_nodd(list_t **, const char *, int);
list_t *add_nodd_end(list_t **, const char *, int);
size_t print_lest_strg(const list_t *);
int delete_nodd_at_index(list_t **, unsigned int);
void vree_list(list_t **);

/*List_lenth_FunctionB.c*/
size_t list_lenth(const list_t *);
char **list_t_strings(list_t *);
size_t print_lest(const list_t *);
list_t *nodd_begin_with(list_t *, char *, char);
ssize_t get_nodd_index(list_t *, list_t *);

/*chain_function.c*/
int is_chaain(inf_t *, char *, size_t *);
void chain_checker(inf_t *, char *, size_t *, size_t, size_t);
int replace_aliaas(inf_t *);
int replace_fars(inf_t *);
int rep_string(char **, char *);

#endif
