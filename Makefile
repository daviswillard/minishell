
NAME			=	minishell
CHECKER			=	checker

SRCS			=	sources/parser.c

OBJS			=	$(SRCS:.c=.o)

DEPS 			= 	$(SRCS:.c=.d)

HEAD			=	includes/push_swap.h
LIBFT			=	libft.a
LIBFT_PATH		=	./libft/
LIBFTMAKE		=	$(MAKE) all -sC $(LIBFT_PATH)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -MMD

all:				lib $(NAME)

bonus:				lib $(CHECKER)

.c.o:
					$(CC) $(CFLAGS) -Iincludes/ -c $< -o $@

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

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
