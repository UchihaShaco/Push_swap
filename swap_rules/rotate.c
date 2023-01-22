/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 06:17:13 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/16 15:51:19 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack *a)
{
	if (a->top == NULL)
		return ;
	a->top = a->top->next;
	ft_putendl_fd("ra", 1);
}

void	do_rb(t_stack *b)
{
	if (b->top == NULL)
		return ;
	b->top = b->top->next;
	ft_putendl_fd("rb", 1);
}

void	do_rr(t_stack *a, t_stack *b)
{
	ft_putendl_fd("rr", 1);
	do_ra(a);
	do_rb(b);
}
