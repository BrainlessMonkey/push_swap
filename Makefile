NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
SRC_DIR = srcs/

SRC_1 = srcs/push_swap/action_a.c \
		srcs/push_swap/action_ab.c \
		srcs/push_swap/action_b.c \
		srcs/push_swap/check_1.c \
		srcs/push_swap/check_2.c \
		srcs/push_swap/free.c \
		srcs/push_swap/parsing.c \
		srcs/push_swap/push_swap.c \
		srcs/push_swap/rotate_and_push.c \
		srcs/push_swap/sort.c \
		srcs/push_swap/stack_utils_1.c \
		srcs/push_swap/stack_utils_2.c \
		srcs/push_swap/test_ab.c \
		srcs/push_swap/test_ba.c \
		
OBJ_1 = ${SRC_1:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ_1} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus