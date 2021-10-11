/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:58:18 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/20 22:29:52 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sorting_b(t_list **stack_b)
{
	*stack_b = stack_index(stack_b);
	if (ft_lstsize(*stack_b) > 1 && !stack_b_is_sorted(stack_b))
	{
		if ((*stack_b)->id < ft_lstlast(*stack_b)->id)
			rotate_b(stack_b);
		if ((*stack_b)->id < (*stack_b)->next->id)
			swap_b(stack_b);
	}
}

int	find_max_val(t_list **stack, int n)
{
	int		i;
	int		max_id;
	t_list	*temp;

	*stack = stack_index(stack);
	max_id = n - 1;
	temp = *stack;
	if (temp->id == max_id)
		return (1);
	i = 1;
	while (temp)
	{
		if (temp->id == max_id)
			break ;
		i++;
		temp = temp->next;
	}
	return (i);
}

void	rot_max_val(t_list **stack_a, t_list **stack_b, int n)
{
	int	i;

	i = -1;
	*stack_b = stack_index(stack_b);
	while (++i < n - 1)
		rotate_b(stack_b);
	push_a(stack_a, stack_b);
	*stack_a = stack_index(stack_a);
	*stack_b = stack_index(stack_b);
}

void	revrot_max_val(t_list **stack_a, t_list **stack_b, int n)
{
	int	i;

	i = 1;
	*stack_b = stack_index(stack_b);
	while (i <= n + 1)
	{
		rev_rotate_b(stack_b);
		i++;
	}
	push_a(stack_a, stack_b);
	*stack_a = stack_index(stack_a);
	*stack_b = stack_index(stack_b);
}

void	get_highest_in_b(t_list **stack_a, t_list **stack_b, int n)
{
	int	pos_max_val;

	pos_max_val = find_max_val(stack_b, n);
	if (pos_max_val == 1)
	{
		push_a(stack_a, stack_b);
		*stack_a = stack_index(stack_a);
		*stack_b = stack_index(stack_b);
	}
	else if (pos_max_val < (n / 2))
		rot_max_val(stack_a, stack_b, pos_max_val);
	else
		revrot_max_val(stack_a, stack_b, (ft_lstsize(*stack_b) - pos_max_val));
}
