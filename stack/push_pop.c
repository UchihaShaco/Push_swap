/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:36:29 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/01 18:20:18 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	push_node(t_stack *stack, int data)
{
	t_node	*bottom;
	t_node	*new_node;

	new_node = create_node(data);
	if (!new_node)
		print_error();
	if ((stack->top) == NULL)
	{
		stack->size = 1;
		stack->top = new_node;
		(new_node)->prev = new_node;
		(new_node)->next = new_node;
	}
	else
	{
		stack->size++;
		bottom = stack->top->prev;
		new_node->next = stack->top;
		new_node->prev = bottom;
		bottom->next = new_node;
		stack->top->prev = new_node;
		stack->top = new_node;
	}
}

int	pop_node(t_stack *stack)
{
	t_node	*temp;
	int		pop;

	pop = 0;
	if (stack->size == 0)
		print_error();
	else if (stack->size == 1)
	{
		pop = stack->top->value;
		free(stack->top);
		stack->size--;
		stack->top = NULL;
	}
	else
	{
		pop = stack->top->value;
		stack->size--;
		temp = stack->top->prev;
		stack->top = stack->top->next;
		free(stack->top->prev);
		stack->top->prev = temp;
		temp->next = stack->top;
	}
	return (pop);
}
