/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-42sh-victor.champagne
** File description:
** get_ampersand
*/

#include "shell.h"

int around_ampersand(char *ampersand)
{
    int result = FAILURE;

    for (int tmp = 0; ampersand[tmp] != '\0'; tmp++)
        (ampersand[tmp] != '\t' && ampersand[tmp] != ' ') ?
        result = SUCCESS : 0;
    return (result);
}

int check_cmd_ampersand(char **cmd_ampersand)
{
    int result = SUCCESS;
    (my_tablen(cmd_ampersand) == 1) ? result = FAILURE : 0;

    if (result == SUCCESS)
        for (int count = 0; cmd_ampersand[count]; count++)
            (around_ampersand(cmd_ampersand[count]) == FAILURE) ?
            result = FAILURE : 0;
    if (result != SUCCESS)
        return (FAILURE);
    return (SUCCESS);
}

int handle_or(char *cmd, shell_t *shell)
{
    int res = SUCCESS;
    char **cmd_ampersand = my_str_to_word_array(cmd, "||");
    (check_cmd_ampersand(cmd_ampersand) == FAILURE) ? res = FAILURE,
    write_error(INSTRUCTION_ERROR), shell->output = 1 : 0;
    shell->output = 0;

    if (res == SUCCESS)
        for (int i = 0; cmd_ampersand[i] && shell->output == 1; i++) {
            (handle_commands(cmd_ampersand[i], shell) == FAILURE) ?
            res = FAILURE : 0;
            if (res == FAILURE) {
                free_my_tab(cmd_ampersand);
                return (FAILURE);
            }
        }
    free_my_tab(cmd_ampersand);
    return (res);
}

int handle_ampersand(char *cmd, shell_t *shell)
{
    int res = SUCCESS;
    char **cmd_ampersand = my_str_to_word_array(cmd, "&&");
    (check_cmd_ampersand(cmd_ampersand) == FAILURE) ? res = FAILURE,
    write_error(INSTRUCTION_ERROR), shell->output = 1 : 0;
    shell->output = 0;

    if (res == SUCCESS)
        for (int i = 0; cmd_ampersand[i] && shell->output == 0; i++) {
            (handle_commands(cmd_ampersand[i], shell) == FAILURE) ?
            res = FAILURE : 0;
            if (res == FAILURE) {
                free_my_tab(cmd_ampersand);
                return (FAILURE);
            }
        }
    free_my_tab(cmd_ampersand);
    return (res);
}
