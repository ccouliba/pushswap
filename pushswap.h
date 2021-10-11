/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:16:18 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/22 19:29:42 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_list
{
	int				id;
	int				content;
	struct s_list	*next;
}				t_list;

/*
** A few Libft functions
*/
t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
int			ft_strlen(char *str);
long long	ft_atoll(const char *str);

/*
** Parsing
*/
int			double_arg(int ac, char **av);
int			is_digit(int ac, char **av);
int			is_integer(int ac, char **av);
int			parsing_error(int ac, char **av);

/*
** Stack creation & stack init & free
*/
void		elem_index(t_list *stack, t_list *elem);
t_list		*stack_index(t_list **stack);
t_list		*stack_creation(int ac, char **av);
void		free_elem(t_list *elem, void (*clr)(void*));
void		free_stack(t_list **stack, void (*clr)(void*));
void		exit_ps(int ac, char **av);

/*
** Checking if stack is sorted
*/
int			arg_is_sorted(int ac, char **av);
int			stack_a_is_sorted(t_list **stack_a);
int			stack_b_is_sorted(t_list **stack_b);

/*
** Operations
*/
void		swap(t_list **stack);
void		swap_a(t_list **stack_a);
void		swap_b(t_list **stack_b);
void		double_swap(t_list **stack_a, t_list **stack_b);
void		push(t_list **dest, t_list **src);
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_b, t_list **stack_a);
void		rotate(t_list **stack);
void		rotate_a(t_list **stack_a);
void		rotate_b(t_list **stack_b);
void		double_rotate(t_list **stack_a, t_list **stack_b);
void		rev_rotate(t_list **stack);
void		rev_rotate_a(t_list **stack_a);
void		rev_rotate_b(t_list **stack_b);
void		double_rev_rotate(t_list **stack_a, t_list **stack_b);

/*
** mini_sort && medium_sort
** from 3 to 5 numbers
*/
void		tiny_sort(t_list **stack_a);
void		mini_sort(t_list **stack_a);
void		push_from_a(t_list **stack_a, t_list **stack_b);
void		medium_sort(t_list **stack_a, t_list **stack_b);

/*
** big_sort
** from 6 to infinite
*/
int			cut_chunk(t_list **stack, int size);
void		push_chunk_by_chunk(t_list **stack_a, t_list **stack_b,
				size_t size_a, int n);
void		big_sort(t_list **stack_a, t_list **stack_b);
void		pushswap(t_list **stack_a, t_list **stack_b, int size_a);

/*
** utils functions
*/
void		sorting_b(t_list **stack_b);
int			find_max_val(t_list **stack, int n);
void		rot_max_val(t_list **stack_a, t_list **stack_b, int n);
void		revrot_max_val(t_list **stack_a, t_list **stack_b, int n);
void		get_highest_in_b(t_list **stack_a, t_list **stack_b, int n);

#endif
