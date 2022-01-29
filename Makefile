# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwillard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:22:10 by dwillard          #+#    #+#              #
#    Updated: 2022/01/17 18:22:12 by dwillard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	minishell

SRCS			=	sources/parser.c		sources/command_center.c\
					sources/main.c			sources/pipex.c\
					sources/shell_utils.c	sources/pipex_utils.c\
					sources/redirects.c		\
					sources/builtin/cd.c	sources/builtin/cd_utils.c\
					sources/builtin/pwd.c	sources/builtin/echo.c

OBJS			=	$(SRCS:.c=.o)

DEPS 			= 	$(SRCS:.c=.d)

LIBFT			=	libft.a
LIBFT_PATH		=	./libft/
LIBFTMAKE		=	$(MAKE) all -sC $(LIBFT_PATH)
LDFLAGS			=	-L$(HOME)/.brew/opt/readline/lib

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD

all:				lib $(NAME) $(BUILTIN)
.c.o:
					$(CC) $(CFLAGS) -I. -Ilibft -Isources/builtin -c $< -o $@

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -I. -Ilibft -Isources/builtin \
 					-L$(LIBFT_PATH) -lft $(LDFLAGS) -lreadline -o $(NAME)

lib:
					$(LIBFTMAKE)

clean:
					$(MAKE)	clean -sC $(LIBFT_PATH)
					rm -rf $(OBJS) $(DEPS)

fclean:				clean
					$(MAKE)	fclean -sC $(LIBFT_PATH)
					rm -rf $(NAME)

re:					fclean all
.PHONY:				all lib bonus clean fclean re
-include			$(OBJS:.o=.d) $(BNS_OBJS:.o=.d)
