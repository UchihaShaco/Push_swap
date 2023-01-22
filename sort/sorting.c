/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:33:57 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/10 05:35:25 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	t_node	*i;
	t_node	*j;

	if (b->top != NULL)
		return (0);
	i = a->top;
	j = a->top->next;
	while (i != a->top->prev)
	{
		if (i->value > j->value)
			return (0);
		i = i->next;
		j = j->next;
	}
	return (1);
}

void	sorting(t_stack *a, t_stack *b, int *arr)
{
	if (a->size == 2)
		sort_two_args(a);
	else if (a->size == 3)
		sort_three_args(a);
	else if (a->size == 4)
		sort_four_args(a, b);
	else if (a->size == 5)
		sort_five_args(a, b);
	else if (a->size < 16)
		sort_one_chunk(a, b);
	else
		sort_chunks(a, b, arr);
	free(arr);
}
