# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 06:11:31 by jalwahei          #+#    #+#              #
#    Updated: 2023/01/22 14:55:45 by jalwahei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 
INCLUDES = -I ./ -I libft
NAME = push_swap
HEADER = push_swap.h
LIBFT = libft
LIBFT_LIB = libft.a
SRCS = utils/error.c swap_rules/swap.c swap_rules/push.c\
	   swap_rules/rotate.c swap_rules/reverse_rotate.c\
	   sort/sorting.c sort/two_four_args.c sort/three_args.c sort/five_args.c\
	   sort/set_chunk_pivot.c sort/sort_chunk.c utils/utils.c\
	   stack/set_stack.c stack/push_pop.c\
	   main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -L$(LIBFT) -lft $^ -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	make clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean : clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re : fclean all