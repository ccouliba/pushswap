/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:17:09 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/20 20:44:16 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	tiny_sort(t_list **stack_a)
{
	if (!(stack_a_is_sorted(stack_a)))
	{
		if ((*stack_a)->id > (*stack_a)->next->id)
			swap_a(stack_a);
	}
}

void	mini_sort(t_list **stack_a)
{
	int	size;
	int	max_id;

	size = ft_lstsize(*stack_a);
	max_id = size - 1;
	if (!(stack_a_is_sorted(stack_a)))
	{
		if ((*stack_a)->id == max_id)
			rotate_a(stack_a);
		else if ((*stack_a)->next->id == max_id)
			rev_rotate_a(stack_a);
	}
	if (!(stack_a_is_sorted(stack_a)))
		swap_a(stack_a);
	*stack_a = stack_index(stack_a);
}
