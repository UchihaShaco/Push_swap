/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:44:51 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/01 22:46:19 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* swap:
*	Swaps the top 2 elements of a stack.
*	Does nothing if there is only one or no elements.
*/
static void	swap(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack;
	stack = stack->next;
	stack->next = tmp;
}

/* do_sa:
*	Swaps the top 2 elements of stack a.
*	Prints "sa" to the standard output.
*/
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

/* do_sb:
*	Swaps the top 2 elements of stack b.
*	Prints "sb" to the standard output.
*/
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

/* do_ss:
*	Swaps the top 2 elements of stack a and the top 2 elements
*	of stack b.
*	Prints "ss" to the standard output.
*/
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
