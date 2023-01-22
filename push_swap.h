/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalwahei <jalwahei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 04:10:04 by jalwahei          #+#    #+#             */
/*   Updated: 2023/01/22 14:55:49 by jalwahei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

int			main(int argc, char *argv[]);
void		print_error(void);
int			check_valid_digit(char *element);
int			check_valid_num(char *element);
long long	check_num_range(char *element);
int			check_duplication(int size, int *element);
long long	ft_atoi_ll(const char *str);
int			count_element(char **element);
char		*ft_merge(char *s1, char *s2);
void		free_args(char **argv);

t_node		*create_node(int data);
t_stack		*put_element(t_stack *stack, int size, int *temp);
t_stack		*init_stack(void);

int			is_sorted(t_stack *a, t_stack *b);
void		sorting(t_stack *a, t_stack *b, int *arr);
void		is_two_args_in_b(t_stack *a, t_stack *b);
void		is_one_args_in_b(t_stack *a, t_stack *b);
void		sort_two_args(t_stack *a);
void		sort_three_args(t_stack *a);
void		sort_four_args(t_stack *a, t_stack *b);
void		sort_five_args(t_stack *a, t_stack *b);

int			set_chunk_num(int size);
int			*set_pivot(int chunk_num, int arr_size);
int			max_index(t_stack *b);
void		bubble_sort(int arr[], int arr_size);
void		sort_one_chunk(t_stack *a, t_stack *b);
void		set_chunks_bound(t_stack *a, t_stack *b, int *arr, int *pivots);
void		sort_chunks(t_stack *a, t_stack *b, int *arr);
void		rotate_or_reverse(t_stack *b, int size, int index);

void		push_node(t_stack *stack, int data);
int			pop_node(t_stack *stack);
void		do_sa(t_stack *a);
void		do_sb(t_stack *b);
void		do_ss(t_stack *a, t_stack *b);
void		do_pa(t_stack *a, t_stack *b);
void		do_pb(t_stack *a, t_stack *b);
void		do_ra(t_stack *a);
void		do_rb(t_stack *b);
void		do_rr(t_stack *a, t_stack *b);
void		do_rra(t_stack *a);
void		do_rrb(t_stack *b);
void		do_rrr(t_stack *a, t_stack *b);

#endif
