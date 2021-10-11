/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:17:04 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/20 22:21:43 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	cut_chunk(t_list **stack, int size)
{
	int	n;

	n = 0;
	if (*stack)
	{
		if (size < 61)
			n = size / 4;
		else if (size > 60 && size < 101)
			n = size / 5;
		else if (size > 100)
			n = size / 20;
		while (size % n != 0)
			n++;
	}
	return (n);
}

void	push_chunk_by_chunk(t_list **stack_a, t_list **stack_b, size_t size_a,
int n)
{
	int	count_pb;

	count_pb = 0;
	while (size_a--)
	{
		*stack_a = stack_index(stack_a);
		if ((*stack_a)->id >= 0 && (*stack_a)->id < n)
		{
			push_b(stack_b, stack_a);
			count_pb++;
			sorting_b(stack_b);
		}
		else
			rotate_a(stack_a);
		*stack_a = stack_index(stack_a);
		if (count_pb == n)
			break ;
	}
	*stack_b = stack_index(stack_b);
	*stack_a = stack_index(stack_a);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	size_t	size_a;
	size_t	size_b;
	size_t	n;

	size_a = ft_lstsize(*stack_a);
	n = cut_chunk(stack_a, size_a);
	while (size_a)
	{
		push_chunk_by_chunk(stack_a, stack_b, size_a, n);
		size_a -= n;
	}
	size_b = ft_lstsize(*stack_b);
	while (size_b--)
	{
		*stack_b = stack_index(stack_b);
		get_highest_in_b(stack_a, stack_b, size_b);
		*stack_b = stack_index(stack_b);
		*stack_a = stack_index(stack_a);
	}
	*stack_a = stack_index(stack_a);
	if ((*stack_a)->id == ft_lstsize(*stack_a) - 1)
		rotate_a(stack_a);
}
