/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:22:15 by dwillard          #+#    #+#             */
/*   Updated: 2022/01/17 18:23:33 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "sources/builtin/builtin.h"
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <err.h>


# define INPUT_END 1
# define OUTPUT_END 0

typedef struct s_command
{
	char		*name;
	char		**argv;
	void		*next;
}				t_command;

t_command	*parse_string(char **envp, char *file);

void		*free_arr(char ***arr);

int			command_center(char **envp, char *input);

int			pipex(t_command *commands, char **envp);

int			lst_len(t_command *lst);

int			chk_builtin(t_command *command);

#endif
