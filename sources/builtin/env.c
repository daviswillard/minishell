
#include <builtin.h>

int	ft_env(char **argv, char **envp)
{
    int i;

    i = 0;
    if (argv && argv[1])
    {
        ft_putstr_fd("minishell: env: ", STDERR_FILENO);
        ft_putendl_fd(ARG_ERROR, STDERR_FILENO);
        return (-1);
    }
    while (envp && envp[i])
    {
        ft_putendl_fd(envp[i], STDOUT_FILENO);
        i++;
    }
    return (0);
}