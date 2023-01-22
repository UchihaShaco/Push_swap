/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_four_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:35:43 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/12 01:11:42 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_args(t_stack *a)
{
	do_ra(a);
}

void	sort_four_args(t_stack *a, t_stack *b)
{
	do_pb(a, b);
	sort_three_args(a);
	is_one_args_in_b(a, b);
}
