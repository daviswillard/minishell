/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:41:27 by dwillard          #+#    #+#             */
/*   Updated: 2021/12/17 21:25:44 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	get_exit(t_command *commands)
{
	int	status;

	status = 0;
	while (commands)
	{
		if (commands->pid > 0)
		{
			waitpid(commands->pid, &status, 0);
			if (WIFEXITED(status))
				g_info.last_prcs = WEXITSTATUS(status);
		}
		commands = commands->next;
	}
	return (0);
}

static void	empty_fd_arr(void)
{
	int	temp;

	temp = 0;
	while (g_info.filed[temp])
	{
		if (temp == 32)
			break ;
		close(g_info.filed[temp]);
		temp++;
	}
	ft_bzero(g_info.filed, 32 * sizeof (int));
}

static int	get_fd(t_command *command)
{
	int	ret;

	ret = 0;
	while (!ret && command)
	{
		redirect(command->rdrct, command->fd_redirs);
		if (command->fd_redirs[0] == SIG_END)
		{
			ret = 1;
			continue ;
		}
		command = command->next;
	}
	return (ret);
}

int	command_center(char *input, char ***envp)
{
	int			ret;

	g_info.commands = parse_string(input);
	if (g_info.commands)
	{
		if (!get_fd(g_info.commands))
		{
			ret = pipex(g_info.commands);
			if (ret == 1)
				g_info.last_prcs = 1;
			else if (ret)
				g_info.last_prcs = 127;
		}
		get_exit(g_info.commands);
		free_command(g_info.commands);
		dup2(g_info.std_fd[0], STDIN_FILENO);
		dup2(g_info.std_fd[1], STDOUT_FILENO);
		empty_fd_arr();
	}
	*envp = g_info.env;
	errno = 0;
	g_info.error = 0;
	if (!access(g_info.minidir, F_OK))
		unlink(g_info.minidir);
	return (0);
}
