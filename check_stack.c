/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 03:49:46 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/20 22:24:49 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
** handle sorting
** 1 if the args is sorted
*/
int	arg_is_sorted(int ac, char **av)
{
	int	i;

	i = 0;
	while ((++i < ac) && av[i + 1])
	{
		if (ft_atoll(av[i]) > ft_atoll(av[i + 1]))
			return (0);
	}
	return (1);
}

/*
** handle sorting
** 1 if stack_a is sorted
*/
int	stack_a_is_sorted(t_list **stack_a)
{
	t_list	*temp;

	if (!(*stack_a))
		return (0);
	temp = *stack_a;
	while (temp->next)
	{
		if (temp->id > temp->next->id)
			return (0);
		temp = temp->next;
	}
	return (1);
}

/*
** handle sorting
** 1 if stack_b is sorted
*/
int	stack_b_is_sorted(t_list **stack_b)
{
	t_list	*temp;

	if (!(*stack_b))
		return (0);
	temp = *stack_b;
	while (temp->next)
	{
		if (temp->id < temp->next->id)
			return (0);
		temp = temp->next;
	}
	return (1);
}
