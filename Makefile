# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 19:44:56 by tlukanie          #+#    #+#              #
#    Updated: 2023/04/07 13:03:39 by tlukanie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = sources/

SRC_1 = sources/push_swap/push_swap.c \

SRC_2 = sources/push_swap/check_free.c \
	 sources/push_swap/find_index_number_in_stack.c \
	 sources/push_swap/list_error_utils.c \
	 sources/push_swap/push_operations.c \
	 sources/push_swap/reverse_rotate_operations.c \
	 sources/push_swap/rotate_calculations_a.c \
	 sources/push_swap/rotate_calculations_b.c \
	 sources/push_swap/rotate_operations.c \
	 sources/push_swap/sort_push.c \
	 sources/push_swap/sort.c \
	 sources/push_swap/swap_operations.c \

BONUS_SRC = sources/checker_bonus/checker.c \
			sources/checker_bonus/checker_utils.c
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus

