# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 18:47:01 by jalwahei          #+#    #+#              #
#    Updated: 2023/01/01 22:46:47 by jalwahei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
SRCS=push_swap.c \
	stack_add.c \
	rotate.c \
	swap_moves.c \
	pa_pb.c \
	push_utils.c \
	

OBJS=$(SRCS:.c=.o)
CC=cc
CFLAGS= -Werror -Wall -Wextra
HEADER=push_swap.h 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all