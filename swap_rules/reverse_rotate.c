/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 05:17:12 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/10 11:46:57 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack *a)
{
	if (a->top == NULL)
		return ;
	a->top = a->top->prev;
	ft_putendl_fd("rra", 1);
}

void	do_rrb(t_stack *b)
{
	if (b->top == NULL)
		return ;
	b->top = b->top->prev;
	ft_putendl_fd("rrb", 1);
}

void	do_rrr(t_stack *a, t_stack *b)
{
	do_rra(a);
	do_rrb(b);
	ft_putendl_fd("rrr", 1);
}
