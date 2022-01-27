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

# include <builtin.h>
# include <libft.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <err.h>

# define INPUT_END 1
# define OUTPUT_END 0
# define NO_FILE -1
# define NO_READ -2
# define NO_WRIT -3
# define MEM_ERR -4
# define OPN_ERR -5
# define STD_VAL -6
# define HEREDOC 100

typedef struct s_command
{
	char	*name;
	char	**argv;
	char	**redirects;
	void	*next;
}t_command;

typedef struct s_env
{
	char	*str;
	void	*next;
}t_env;

struct s_info
{
	int		std_fd[2];
	int		yulya_var;
	int		last_prcs;
	t_env	*env_lst;
}g_info;

t_command	*parse_string(char **envp, char *file);

t_env		*lst_new(char *content);

void		lst_add_back(t_env **lst, t_env *new);

int			lst_len(t_command *lst);

void		error(char *str);

int			command_center(char **envp, char *input);

int			pipex(t_command *commands);

void		dups(int fd_in, char ***doc, int fd[2]);

int			chk_builtin(t_command *command);

int			*redirect(char **red_arr, int *fd_pair, char ***document);

#endif
