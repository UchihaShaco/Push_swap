/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:00:31 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/22 13:58:22 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_ll(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((long long)result * sign);
}

int	count_element(char **element)
{
	int	i;

	i = 0;
	while (element[i])
		i++;
	return (i);
}

char	*ft_merge(char *s1, char *s2)
{
	char	*ret;

	ret = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ret);
}

void	free_args(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	bubble_sort(int arr[], int arr_size)
{
	int	temp;
	int	i;
	int	j;

	temp = 0;
	i = 0;
	while (i < arr_size - 1)
	{
		j = 0;
		while (j < arr_size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
