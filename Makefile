# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nromito <nromito@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 10:08:24 by nromito           #+#    #+#              #
#    Updated: 2024/06/12 14:11:14 by nromito          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

LIBFT = libft/libft.a
LIBFT_PATH = libft/

HEADERS = header/philo.h

SRCS = philo.c

OBJS = ${SRCS:.c=.o}

COMPILE = cc -Wall -Wextra -Werror -g

RED = "\033[1;31m"
GREEN = "\033[1;32m"
YELLOW = "\033[1;33m"
BLUE = "\033[1;34m"
MAGENTA = "\033[1;35m"
CYAN = "\033[1;36m"
WHITE = "\033[1;37m"
NONE = "\033[0m"

all: ${NAME}
%.o: %.c
		$(COMPILE) -I $(LIBFT_PATH) -c $< -o $@

${NAME}: ${OBJS} ${HEADER}
		make -C ${LIBFT_PATH}
		$(COMPILE) $(OBJS) -o $(NAME) $(LIBFT) -lreadline
		@echo $(MAGENTA) "  ____  _   _  _  _      _____" $(NONE)
		@echo $(RED)    " |  _ \| | | || || |    |  _  |" $(NONE)
		@echo $(YELLOW) " | |_)|| |_| || || |    | | | |" $(NONE)
		@echo $(GREEN)  " |  __/| |_| || || |    | | | |" $(NONE)
		@echo $(CYAN)   " | |   | | | || || |___ | |_| |" $(NONE)
		@echo $(BLUE)   " |_|   |_| |_||_||_____||_____|" $(NONE)
		@echo $(WHITE)  "                               " $(NONE)

clean:
		@rm -rf $(OBJS)
		@make -C $(LIBFT_PATH) clean
		@echo $(GREEN)"Successfully cleaned!" $(NONE)

fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIBFT_PATH) fclean
		@echo $(CYAN)"Successfully Fcleaned!" $(NONE)

re: fclean all

.PHONY: all clean fclean

