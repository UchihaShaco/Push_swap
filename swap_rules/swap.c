/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 04:11:13 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/16 12:43:41 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack *a)
{
	int	up;
	int	down;

	up = pop_node(a);
	down = pop_node(a);
	push_node(a, up);
	push_node(a, down);
	ft_putendl_fd("sa", 1);
}

void	do_sb(t_stack *b)
{
	int	up;
	int	down;

	up = pop_node(b);
	down = pop_node(b);
	push_node(b, up);
	push_node(b, down);
	ft_putendl_fd("sb", 1);
}

void	do_ss(t_stack *a, t_stack *b)
{
	ft_putendl_fd("ss", 1);
	do_sa(a);
	do_sb(b);
}
