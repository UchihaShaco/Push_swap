/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_chunk_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:33:57 by jalwahei          #+#    #+#             */
/*   Updated: 2023/02/01 18:21:41 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

// static	int	find_sqrt(int x)
// {
// 	int		approximation;
// 	double	precision;

// 	approximation = x;
// 	precision = 0.5;
// 	while (abs(approximation * approximation - x) > precision)
// 	{
// 		approximation = (approximation + (x / approximation)) / 2;
// 	}
// 	return (approximation);
// }

int	set_chunk_num(int size)
{
	int	chunk_num;

	chunk_num = sqrt(size) / 2;
	return (chunk_num);
}

int	*set_pivot(int chunk_num, int arr_size)
{
	int	*pivots;
	int	i;
	int	tmp_value;

	pivots = (int *)malloc(sizeof(int) * (chunk_num + 1));
	tmp_value = arr_size / chunk_num;
	pivots[0] = 0;
	pivots[chunk_num] = arr_size - 1;
	i = 1;
	while (i < chunk_num)
	{
		pivots[i] = tmp_value * i;
		i++;
	}
	return (pivots);
}

int	max_index(t_stack *b)
{
	t_node	*temp;
	int		i;
	int		max;
	int		index;

	max = -2147483647;
	i = 0;
	index = 0;
	temp = b->top;
	while (i < b->size)
	{
		if (max < temp->value)
		{
			index = i;
			max = temp->value;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	rotate_or_reverse(t_stack *b, int size, int index)
{
	int	i;

	i = -1;
	if (index <= size / 2)
		while (++i < index)
			do_rb(b);
	else
		while (++i < size - index)
			do_rrb(b);
}
