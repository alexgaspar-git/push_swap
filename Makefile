SRCS		= main.c \
			  split.c \
			  utils.c \
			  parsing.c \
			  sorting.c \
			  lst.c \
			  lst_utils.c \
			  do_op.c \
			  small_case.c \
			  sort_algo.c \
			  sort_algo_utils.c \
			  init.c \
			  calc_rb.c
SRCS		:= $(addprefix src/,$(SRCS)) 
OBJS		= ${SRCS:.c=.o}
NAME		= push_swap
CC			= gcc
MAKE		= make
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra -Iinclude
$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
all:			$(NAME)

clean:
				${RM} ${OBJS} $(OBJ_BONUS)
fclean:			clean
				${RM} $(NAME) $(NAME_BONUS)
re:				fclean all
.PHONY:			all clean fclean re bonus