/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:30:54 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/21 18:50:33 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
** Indexation of one element
*/
void	elem_index(t_list *stack, t_list *elem)
{
	int	index;

	index = 0;
	if (!stack)
		return ;
	elem->id = 0;
	while (stack)
	{
		if (elem->content > stack->content)
			index++;
		stack = stack->next;
	}
	elem->id = index;
}

/*
** Indexation of the entire stack
*/
t_list	*stack_index(t_list **stack)
{
	t_list	*temp;

	if (!(*stack))
		return (NULL);
	temp = *stack;
	while (temp)
	{
		elem_index(*stack, temp);
		temp = temp->next;
	}
	return (*stack);
}

/*
** Creation of stack_a
*/
t_list	*stack_creation(int ac, char **av)
{
	int		i;
	t_list	*stack;

	i = 1;
	stack = ft_lstnew(ft_atoll(av[1]));
	if (!stack)
		return (0);
	while (++i < ac)
		ft_lstadd_back(&stack, ft_lstnew(ft_atoll(av[i])));
	stack = stack_index(&stack);
	return (stack);
}

/*
** Free function of one element
*/
void	free_elem(t_list *elem, void (*clr)())
{
	if (elem && clr)
		free(elem);
}

/*
** Free function of the entire stack
*/
void	free_stack(t_list **stack, void (*clr)())
{
	t_list	*elem;

	elem = *stack;
	if (*stack)
	{
		while (*stack)
		{
			elem = (*stack)->next;
			clr(*stack);
			*stack = elem;
		}
		*stack = NULL;
	}
}
