/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:45:22 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/22 15:19:16 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_three_args(t_stack *a)
{
	int	top;
	int	mid;
	int	bottom;

	top = a->top->value;
	mid = a->top->next->value;
	bottom = a->top->prev->value;
	if (bottom > top && bottom < mid)
	{
		do_rra(a);
		do_sa(a);
	}
	else if (bottom < top && bottom > mid)
		do_ra(a);
	else if (top > mid && top < bottom)
		do_sa(a);
	else if (top < mid && top > bottom)
		do_rra(a);
	else if (mid < top && mid > bottom)
	{
		do_ra(a);
		do_sa(a);
	}
}
