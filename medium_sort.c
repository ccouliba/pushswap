/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:17:06 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/20 22:22:52 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	push_from_a(t_list **stack_a, t_list **stack_b)
{
	size_t	size_a;

	size_a = ft_lstsize(*stack_a);
	while (size_a--)
	{
		if ((*stack_a)->id > 1)
			rotate_a(stack_a);
		else
			push_b(stack_b, stack_a);
		if (ft_lstsize(*stack_a) == 3)
			break ;
	}
	*stack_a = stack_index(stack_a);
	mini_sort(stack_a);
	*stack_b = stack_index(stack_b);
}

void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	size_t	size_b;

	size_b = ft_lstsize(*stack_b);
	if (size_b > 1 && !(stack_b_is_sorted(stack_b)))
		swap_b(stack_b);
	while (size_b--)
		push_a(stack_a, stack_b);
	*stack_a = stack_index(stack_a);
	if ((*stack_a)->id > (*stack_a)->next->id)
		swap_a(stack_a);
	*stack_a = stack_index(stack_a);
}
