/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:31:09 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/01 22:58:25 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (sorted(*stack_a))
		return ;
	while (!(sorted(*stack_a)))
	{
		printf("Hello 1\n");
		if ((*stack_a)->value > get_stack_last(*stack_a)->value \
		&& !sorted(*stack_a))
		{
			if (get_stack_last(*stack_b)->value > (*stack_b)->value \
			&& !sorted(*stack_b))
				do_rr(stack_a, stack_b);
			else
				do_ra(stack_a);
		}
		else if (get_stack_last(*stack_b)->value > \
		(*stack_a)->value && !sorted(*stack_b))
			do_rb(stack_b);
		else if ((*stack_a)->value > (*stack_a)->next->value \
		&& !sorted(*stack_a))
		{
			if ((*stack_b)->value > (*stack_b)->next->value \
			&& !sorted(*stack_b))
				do_ss(stack_a, stack_b);
			else
				do_sa(stack_a);
		}
	}
}

void	push_sort(t_stack **stack_a, t_stack **stack_b)
{
		printf("Hello 1\n");
	if (sorted(*stack_a))
		return ;
	else
		sort(stack_a, stack_b);
}
