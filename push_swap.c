/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 19:37:22 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/21 21:52:10 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	pushswap(t_list **stack_a, t_list **stack_b, int size_a)
{
	if (!(stack_a_is_sorted(stack_a)))
	{
		if (size_a == 2)
			tiny_sort(stack_a);
		else if (size_a == 3)
			mini_sort(stack_a);
		else if (size_a == 4 || size_a == 5)
		{
			if (!(stack_a_is_sorted(stack_a)))
			{
				push_from_a(stack_a, stack_b);
				medium_sort(stack_a, stack_b);
			}
		}
		else if (size_a > 5)
			if (!(stack_a_is_sorted(stack_a)))
				big_sort(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	exit_ps(ac, av);
	if (ac < 3)
		return (0);
	else
	{
		stack_b = NULL;
		stack_a = stack_creation(ac, av);
		pushswap(&stack_a, &stack_b, ft_lstsize(stack_a));
		free_stack(&stack_b, free);
		free_stack(&stack_a, free);
	}
	return (0);
}
