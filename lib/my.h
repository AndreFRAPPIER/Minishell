/*
** EPITECH PROJECT, 2023
** mama
** File description:
** mama
*/

#ifndef LIB_H
    #define LIB_H
    #define PROMPT "[user@mysh]$> "
    #define CMD_NOT_FOUND 21504
    #define CMD_SEGFAULT 139
    #define CMD_EXEC_SUCCESS 0

    #include <stdio.h>
    #include <stdlib.h>

typedef struct environment {
    char **env;
    int change;
} env_t;

void my_puterror(char *str);
int my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_printf(char const *format, ...);
char **my_str_to_word_array(char *str);
void free_my_str_to_word_array(char **arr);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_concat_param(char *a, char *b);
char *my_concat_param_triple(char *a, char *b, char *c);

int my_sh(env_t *env);
void free_command(char **str, env_t *env);
int len_tab(char **tab);
int find_rank(char *name, char **env);
int command_manager(char **command, env_t *env);
int command_launcher(char **command, env_t *env);
char **get_command(char **source, int nb_sep_to_ignore);
void launch_builtin_function(char **command, env_t *env);
void launch_native_function(char **command, env_t *env);

char *get_value_var_env(char *str);
char *change_env_line(char *key_word, char *src);
char *change_env_line_with_path(char *key_word, char *src);
void builtin_cd(char **command, env_t *env);
void cd_last_directory(env_t *env);
void change_directory(env_t *env, char *path);
void cd_home(env_t *env);

void setenv_manager(char **command, env_t *env);
void unsetenv_manager(char **command, env_t *env);
env_t init_env(char **save_env);
char **copy_env(char **env);

int manage_separators(char **command, int nb_separators, env_t *env);
int get_number_separator(char **command);

#endif /* !LIB_H */
