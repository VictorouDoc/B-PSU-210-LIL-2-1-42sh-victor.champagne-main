/*
** EPITECH PROJECT, 2022
** B-PSU-210-LIL-2-1-42sh-victor.champagne
** File description:
** execve_parsing
*/

#include "shell.h"

void command_process(shell_t *shell, char **cmd, char *command)
{
    (shell->pipe_out == true) ? dup2(shell->tmp_file, 1) : 0;
    execve(command, cmd, shell->env) == -1 ? my_printf("%s", cmd[0]),
    write_error(EXEC_FORMAT), shell->output = 1 : 0;
    exit(1);
}

int execve_error(shell_t *shell, char **path, char **cmd, char *tmp)
{
    if (!access(tmp, X_OK)) {
        start_command(cmd, tmp, shell);
        free(tmp);
        free_my_tab(path);
        return (1);
    }
    return (SUCCESS);
}
