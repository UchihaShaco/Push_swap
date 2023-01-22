/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:33:57 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/17 15:49:40 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_one_chunk(t_stack *a, t_stack *b)
{
	while (a->size)
		do_pb(a, b);
	while (b->size)
	{
		rotate_or_reverse(b, b->size, max_index(b));
		do_pa(a, b);
	}
}

void	set_chunks_bound(t_stack *a, t_stack *b, int *arr, int *pivots)
{
	int	i;
	int	j;
	int	chunk_num;

	chunk_num = set_chunk_num(a->size);
	i = 0;
	while (i < chunk_num - 1)
	{
		j = 0;
		while (j < pivots[i + 1] - pivots[i])
		{
			if (arr[pivots[i]] <= a->top->value
				&& arr[pivots[i + 1]] > a->top->value)
			{
				do_pb(a, b);
				j++;
			}
			else
				do_ra(a);
		}
		i++;
	}
}

void	sort_chunks(t_stack *a, t_stack *b, int *arr)
{
	int	*pivots;
	int	chunk_num;

	chunk_num = set_chunk_num(a->size);
	bubble_sort(arr, a->size);
	pivots = set_pivot(chunk_num, a->size);
	set_chunks_bound(a, b, arr, pivots);
	while (a->size)
		do_pb(a, b);
	while (b->size)
	{
		rotate_or_reverse(b, b->size, max_index(b));
		do_pa(a, b);
	}
	free(pivots);
}
