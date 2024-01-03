# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:02:50 by agan              #+#    #+#              #
#    Updated: 2024/01/03 15:02:51 by agan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
SRCS	= srcs/philo.c srcs/var_init.c
OBJS 	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -fr

#ft_printf
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF := ./ft_printf/libftprintf.a

all: ${NAME}

${NAME} : ${OBJS} ${FT_PRINTF}
	@$(CC) ${CFLAGS} ${OBJS} ${FT_PRINTF} -o ${NAME}
	@echo "philosophers compiled!"

.c.o:
	@$(CC) ${CFLAGS} -c $< -o $@

${FT_PRINTF}:
	@make -s -C ${FT_PRINTF_DIR}

clean:
	@make -s clean -C ${FT_PRINTF_DIR}
	@rm -fr ${OBJS}

fclean: clean
	@make -s fclean -C ${FT_PRINTF_DIR}
	@rm -f ${NAME}
	@echo "fclean completed!"

re: fclean all

.PHONY: all clean fclean re