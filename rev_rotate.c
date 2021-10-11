/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:08:06 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/20 22:28:56 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*a_last;
	t_list	*a_p_last;

	a_last = *stack;
	a_p_last = *stack;
	while (a_last->next)
	{
		a_p_last = a_last;
		a_last = a_last->next;
	}
	ft_lstadd_front(stack, a_last);
	a_p_last->next = NULL;
}

void	rev_rotate_a(t_list **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_list **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	double_rev_rotate(t_list **stack_a, t_list **stack_b)
{
	rev_rotate_a(stack_a);
	rev_rotate_b(stack_b);
	write(1, "rrr\n", 4);
}
