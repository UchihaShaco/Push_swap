# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 06:11:31 by jalwahei          #+#    #+#              #
#    Updated: 2023/02/01 18:22:54 by jalwahei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
INCLUDES = -I ./ -I libft
NAME = push_swap
HEADER = push_swap.h
LIBFT = libft
LIBFT_LIB = libft.a
SRCS = 	main.c	sort/five_args.c sort/set_chunk_pivot.c \
        sort/sorting.c sort/three_args.c sort/two_four_args.c sort/sort_chunk.c stack/push_pop.c \
        swap_rules/push.c swap_rules/reverse_rotate.c swap_rules/rotate.c swap_rules/swap.c \
        utils/utils.c utils/error.c stack/set_stack.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT)  -lft -o $(NAME) -l m

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re : fclean all 
