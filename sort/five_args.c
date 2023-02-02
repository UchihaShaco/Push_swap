/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:33:57 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/22 15:19:00 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	add_in_four(t_stack *a, t_stack *b)
{
	if (a->top->value > a->top->next->value
		&& a->top->next->value < a->top->next->next->value)
	{
		do_ra(a);
		do_pa(a, b);
	}
	else if (a->top->next->value > a->top->next->next->value
		&& a->top->next->next->value < a->top->prev->value)
	{
		do_ra(a);
		do_ra(a);
		do_pa(a, b);
	}
	else if (a->top->next->next->value > a->top->prev->value
		&& a->top->prev->value < a->top->value)
	{
		do_rra(a);
		do_pa(a, b);
	}
	else
		do_pa(a, b);
}

static void	sort_in_five(t_stack *a)
{
	if (a->top->next->value < a->top->value
		&& a->top->next->value < a->top->next->next->value)
		do_ra(a);
	else if (a->top->next->next->value < a->top->next->value
		&& a->top->next->next->value < a->top->prev->prev->value)
	{
		do_ra(a);
		do_ra(a);
	}
	else if (a->top->prev->prev->value < a->top->next->next->value
		&& a->top->prev->prev->value < a->top->prev->value)
	{
		do_rra(a);
		do_rra(a);
	}
	else if (a->top->prev->value < a->top->prev->prev->value
		&& a->top->prev->value < a->top->value)
		do_rra(a);
}

void	is_two_args_in_b(t_stack *a, t_stack *b)
{
	int	input;

	input = b->top->value;
	if (input < a->top->value)
		do_pa(a, b);
	else if (input > a->top->value
		&& input < a->top->next->value)
	{
		do_ra(a);
		do_pa(a, b);
	}
	else if (input > a->top->next->value
		&& input < a->top->prev->value)
	{
		do_rra(a);
		do_pa(a, b);
	}
	else if (input > a->top->prev->value)
		do_pa(a, b);
}

void	is_one_args_in_b(t_stack *a, t_stack *b)
{
	if (b->top->value > a->top->value
		&& b->top->value < a->top->next->value)
	{
		do_ra(a);
		do_pa(a, b);
	}
	else if (b->top->value > a->top->next->value
		&& b->top->value < a->top->next->next->value)
	{
		do_ra(a);
		do_ra(a);
		do_pa(a, b);
	}
	else if (b->top->value > a->top->next->next->value
		&& b->top->value < a->top->prev->value)
	{
		do_rra(a);
		do_pa(a, b);
	}
	else if (b->top->value < a->top->value
		&& b->top->value > a->top->prev->value)
		do_pa(a, b);
	else
		add_in_four(a, b);
	sort_in_five(a);
}

void	sort_five_args(t_stack *a, t_stack *b)
{
	do_pb(a, b);
	do_pb(a, b);
	sort_three_args(a);
	is_two_args_in_b(a, b);
	is_one_args_in_b(a, b);
}
