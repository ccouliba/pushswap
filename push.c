/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:08:01 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/21 21:45:37 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*temp;

	if (*src)
	{
		temp = (*src)->next;
		if (*dest)
			ft_lstadd_front(dest, *src);
		else
		{
			*dest = ft_lstnew((*src)->content);
			free(*src);
		}
		*src = temp;
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
