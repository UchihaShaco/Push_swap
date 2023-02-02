/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 09:26:42 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/27 19:15:32 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	check_arg(int size, char **arg, int **temp)
{
	int	i;
	int	*num;

	num = (int *)malloc(sizeof(int) * (size));
	i = 0;
	while (i < size)
	{
		if (check_valid_num(arg[i]) || (check_valid_digit(arg[i]) > 10) || \
		check_num_range(arg[i]) == 3000000000)
		{
			free(num);
			free_args(arg);
			print_error();
		}
		num[i] = ft_atoi(arg[i]);
		i++;
	}
	if (check_duplication(size, num))
	{
		free(num);
		free_args(arg);
		print_error();
	}
	*temp = num;
}

static char	**config_args(int argc, char *argv[])
{
	int		i;
	char	**ret;
	char	*str;
	char	*temp;

	i = 0;
	str = malloc(sizeof(char));
	str[0] = 0;
	while (++i < argc)
	{
		temp = str;
		if (i == 1)
		{
			str = ft_strjoin(str, argv[i]);
			free(temp);
		}
		else
		{
			temp = ft_strjoin(" ", argv[i]);
			str = ft_merge(str, temp);
		}
	}
	ret = ft_split(str, ' ');
	free(str);
	return (ret);
}

static void	free_exit(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		pop_node(a);
		i++;
	}
	free(b);
	free(a);
}

static void	check_empty_input(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (argv[i] == (NULL) || argv[i][0] == '\0' || \
		check_spaces_only(argv[i]) == 1)
		{
			print_error();
			break ;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		*temp_stack;

	stack_b = NULL;
	stack_a = NULL;
	temp_stack = NULL;
	args = NULL;
	if (argc < 2)
		print_error();
	else
	{
		check_empty_input(argc, argv);
		args = config_args(argc, argv);
		check_arg(count_element(args), args, &temp_stack);
		stack_a = init_stack();
		stack_b = init_stack();
		put_element(stack_a, count_element(args), temp_stack);
		if (!is_sorted(stack_a, stack_b))
			sorting(stack_a, stack_b, temp_stack);
	}
	free(temp_stack);
	free_args(args);
	free_exit(stack_a, stack_b);
}
