#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* environ macro */
extern char **environ;

/**
 * struct sep_list_s - Single linked list node to store separators
 * @sep: The separator (;, |, or &)
 * @next: Pointer to the next node in the linked list
 * Description: This data structure represents a single
 *              linked list node
 *              used to store separators in the shell.
 */
typedef struct sep_list_s
{
	char sep;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_ls_s - Single linked list node to store
 *                    command lines
 * @line: The command line
 * @next: Pointer to the next node in the linked list
 *
 * Description: This data structure represents a single
 *              linked list node
 *              used to store command lines in the shell.
 */
typedef struct line_ls_s
{
	char *line;
	struct line_ls_s *next;
} line_list;

/**
 * struct shell_dt - Contains relevant data
 *                     for the shell during runtime
 * @argv: The argument vector (command-line arguments)
 * @input: The command line input provided by the user
 * @args: The tokens extracted from the command line
 * @stat: The last status of the shell
 * @counter: The line counter for tracking the number of lines processed
 * @_env: The environment variables
 * @pid: The process ID of the shell
 */
typedef struct shell_dt
{
	char **argv;
	char *input;
	char **args;
	int stat;
	int counter;
	char **_env;
	char *pid;
} shll_comm;

/**
 * struct rvar_ls - Single linked list node to store variables
 * @len_var: Length of the variable
 * @val: Value of the variable
 * @len_val: Length of the value
 * @next: Pointer to the next node in the linked list
 *
 * Description: This data structure represents a single linked
 *              list node
 *              used to store variables in the shell.
 */
typedef struct rvar_ls
{
	int len_var;
	char *val;
	int len_val;
	struct rvar_ls *next;
} r_var;

/**
 * struct builtin_s - Builtin command structure
 * @commname: The name of the command builtin (e.g., cd, exit, env)
 * @f: Pointer to the function associated with the command
 *
 * Description: This structure represents a builtin command in the shell.
 * It contains the name of the command and a pointer to the function that
 * implements the command functionality.
 */
typedef struct builtin_s
{
	char *commname;
	int (*f)(shll_comm *datash);
} builtin_t;

/* Linked lists functions */
sep_list *add_noden(sep_list **head, char sep);
void free_spls(sep_list **head);
line_list *add_lnndend(line_list **head, char *line);
void free_lnls(line_list **head);
r_var *add_varnd(r_var **head, int lvar, char *var, int lval);
void free_valls(r_var **head);

/* String functions protytypes */
char *_strccaat(char *dest, const char *src);
char *_strcopy(char *dest, char *src);
void _mmcpy(void *newptr, const void *ptr, unsigned int size);
void *_realmaloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strsppn(char *s, char *accept);
char *_strdupp(const char *s);
int _strlength(const char *s);
int compr_chrs(char str[], const char *delim);
char *_strtiktok(char str[], const char *delim);
int _isdigital(const char *s);
void rv_strng(char *s);
int getlngth(int n);
char *convitoa(int n);
int _ati(char *s);
char **_reallcdp(char **ptr, unsigned int old_size, unsigned int new_size);
int _strccmmpp(char *s1, char *s2);
char *_strchar(char *s, char c);

/* Error handling functions prototypes */
int duplchrs(char *input, int i);
int sepopererr(char *input, int i, char last);
int frstchrctr(char *input, int *i);
void dspsynerr(shll_comm *data_sh, char *input, int i, int bool);
int chsynerr(shll_comm *data_sh, char *input);
char *withotcmt(char *input);
void loopshll(shll_comm *datash);

/* read_line function protytype */
char *read_ln(int *i_eof);

/* Environmant variables function protytypes */
int verfyvrs(r_var **h, char *in, char *st, shll_comm *data);
char *rplinp(r_var **head, char *input, char *new_input, int nlen);
char *getenvrn(const char *name, char **_env);
int dsplyenv(shll_comm *datash);
char *cpinf(char *name, char *value);
void stenv(char *name, char *value, shll_comm *datash);
int _stnv(shll_comm *datash);
int _unstnv(shll_comm *datash);
int cmpr_envnm(const char *name_env, const char *name_ptr);
void vrifyenv(r_var **h, char *in, shll_comm *data);
char *replc_str(char *input, shll_comm *datash);

/* Split functions protytypes */
char *swp_chrct(char *input, int bool);
void mv_next(sep_list **list_s, line_list **list_l, shll_comm *datash);
int splitcmd(shll_comm *datash, char *input);
void addnd(sep_list **head_s, line_list **head_l, char *input);
char **spltln(char *input);

/* get_line functions protytypes */
ssize_t _getln(char **lineptr, size_t *n, FILE *stream);
void getln(char **lineptr, size_t *n, char *buffer, size_t j);

/* Execute functions protytypes */
int excut_ln(shll_comm *datash);
int chck_errcommnd(char *dir, shll_comm *datash);
int cmmnd_ex(shll_comm *datash);
int chckcdir(char *path, int *i);
char *_wch(char *cmd, char **_env);
int isexc(shll_comm *datash);

/* cd functions protypes */
void chndirdor(shll_comm *datash);
void cdtdist(shll_comm *datash);
void chngeirprev(shll_comm *datash);
void chngdirthome(shll_comm *datash);
int chngdirshell(shll_comm *datash);

/* main functions protytypes*/
void empty_dt(shll_comm *datash);
void set_dtshll(shll_comm *datash, char **av);

/* built-in functions prototypes */
int (*getbltn(char *cmd))(shll_comm *datash);
int ext_sh(shll_comm *datash);

/* Error handling functions prototypes */
int geterr(shll_comm *datash, int eval);
void get_sgnt(int sig);
char *error_get_alias(char **args);
char *err_envrn(shll_comm *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *errpth126(shll_comm *datash);
char *concermsg(shll_comm *, char *, char *, char *);
char *errgcd(shll_comm *datash);
char *err404(shll_comm *datash);
char *errshellex(shll_comm *datash);

/* Help functions prototypes */
void dsp_hlpenv(void);
void dsp_helpstnv(void);
void dsp_unstnv(void);
void dsp_helpgnrl(void);
void dsp_helpex(void);
void disp_hlp(void);
void dsp_helpals(void);
void disp_hlpcd(void);
int gethlp(shll_comm *datash);

#endif
