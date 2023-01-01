/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:20:25 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/01 18:43:05 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sign_digit(char c, char d)
{
	if (d == 'd')
		return (c >= '0' && c <= '9');
	if (d == 's')
		return (c == '+' || c == '-');
	return (0);
}

static int	input_is_num(char *av)
{
	int	i;

	i = 0;
	if (sign_digit(av[i], 's') && av[i + 1] != '\0')
		i++;
	while (av[i] && sign_digit(av[i], 'd'))
		i++;
	if (av[i] != '\0' && !sign_digit(av[i], 'd'))
		return (1);
	return (0);
}

static int	num_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

static int	duplicates(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && num_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static	int	not_correct_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (input_is_num(av[i]))
			return (1);
		i++;
	}
	if (duplicates(av))
	{
		printf("error");
		return (0);
	}
	return (0);
}

t_stack	*fill_stack(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit(0);
		if (i == 1)
		stack_a = stack_new((int)nb);
		else
			stack_add_last(&stack_a, stack_new(nb));
		i++;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
	{
		printf("error");
		return (0);
	}
	if (not_correct_input(av))
	{
		printf("error");
		return (0);
	}
	stack_b = NULL;
	stack_a = fill_stack(ac, av);
	push_sort(&stack_a, &stack_b);
	return (0);
}
