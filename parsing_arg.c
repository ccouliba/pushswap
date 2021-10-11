/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 19:50:47 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/22 19:24:54 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

/*
** handle double args
** 1 if there is no double
*/
int	double_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while ((i < ac) && av[i + 1])
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoll(av[i]) == ft_atoll(av[j++]))
				return (0);
		}
		i++;
	}
	return (1);
}

/*
** handle numbers
** 1 if is a digit
*/
int	is_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (j == 0 && (av[i][j] == '-' || av[i][j] == '+'))
			{
				if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
					return (0);
			}
			else if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
		}
	}
	return (1);
}

/*
** handle int min and max (long && ulonglong)
** 1 if is an integer
*/
int	is_integer(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_strlen(av[i]) > 11)
			return (0);
		else if (ft_strlen(av[i]) == 10 && (ft_atoll(av[i]) > INT_MAX))
			return (0);
		else if (ft_strlen(av[i]) == 11 && (ft_atoll(av[i]) < INT_MIN))
			return (0);
		else if ((ft_atoll(av[i]) > INT_MAX) || (ft_atoll(av[i]) < INT_MIN))
			return (0);
	}
	return (1);
}

/*
** Parsing
** 1 if there is not error
*/
int	parsing_error(int ac, char **av)
{
	if (!(is_digit(ac, av)))
		return (0);
	else if (!(is_integer(ac, av)))
		return (0);
	else if (!(double_arg(ac, av)))
		return (0);
	return (1);
}

/*
** Exit function
*/
void	exit_ps(int ac, char **av)
{
	if (!(parsing_error(ac, av)))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if ((arg_is_sorted(ac, av)))
		exit(EXIT_SUCCESS);
}
