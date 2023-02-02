/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:48:30 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/30 14:08:36 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*put_element(t_stack *stack, int size, int *temp)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push_node(stack, temp[size - i - 1]);
		i++;
	}
	return (stack);
}

int	check_spaces_only(char *str)
{
	int	i;
	int	spaces_only;

	i = 0;
	spaces_only = 1;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			spaces_only = 0;
			break ;
		}
		i++;
	}
	return (spaces_only);
}
