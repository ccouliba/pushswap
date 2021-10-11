/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:08:14 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/20 22:37:28 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	swap(t_list **stack)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->content ^= (*stack)->next->content;
		(*stack)->next->content ^= (*stack)->content;
		(*stack)->content ^= (*stack)->next->content;
	}
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	double_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
