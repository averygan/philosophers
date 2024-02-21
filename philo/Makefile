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
SRCS	= philo.c var_init.c philo_init.c utils.c simulation.c monitor.c
OBJS 	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=thread
RM		= rm -fr
HEADER	= philo.h

all: ${NAME}

${NAME} : ${OBJS} ${HEADER}
	@$(CC) ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "philosophers compiled!"

.c.o:
	@$(CC) ${CFLAGS} -c $< -o $@

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@echo "fclean completed!"

re: fclean all

.PHONY: all clean fclean re