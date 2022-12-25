/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:21:10 by jalwahei          #+#    #+#             */
/*   Updated: 2022/12/25 18:29:28 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// # include "./library/libft.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// helper func
int			sign_digit(char c, char d);

// stack filling 
t_stack		*fill_stack(int ac, char **av);
t_stack		*stack_new(int num);
void		stack_add_last(t_stack **stack, t_stack *new);
t_stack		*get_stack_last(t_stack *stack);
long int	ft_atoi(const char *str);

#endif