/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 07:17:13 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/10 05:14:24 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stack *a, t_stack *b)
{
	if (b->top == NULL)
		return ;
	push_node(a, pop_node(b));
	ft_putendl_fd("pa", 1);
}

void	do_pb(t_stack *a, t_stack *b)
{
	if (a->top == NULL)
		return ;
	push_node(b, pop_node(a));
	ft_putendl_fd("pb", 1);
}
