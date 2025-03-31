/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:46:35 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/28 15:40:18 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_order(char **args)
{
	int	i;

	i = 0;
	while (args[i] && args[i + 1])
	{
		if (ft_atoi(args[i]) > ft_atoi(args[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

static int	search_dups(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (write(2, RED"Error\n"NO_COLOR, 11), 0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_parsing(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][0] == '-' && args[i][1])
			j++;
		if (ft_atoi(args[i]) > INT_MAX || ft_atoi(args[i]) < INT_MIN \
														|| args[i][0] == 0)
			return (write(2, RED"Error\n", 11), 0);
		else
		{
			while (args[i][j])
			{
				if (!(ft_isdigit(args[i][j])))
					return (write(2, RED"Error\n", 11), 0);
				j++;
			}
		}
		i++;
	}
	return (check_order(args));
}

static char	**exclude_executable(int ac, char **av)
{
	char	**array;
	int		i;
	int		j;

	i = 1;
	j = 0;
	array = ft_calloc(ac, sizeof(char *));
	if (!array)
		return (NULL);
	while (av[i])
	{
		array[j] = ft_strdup(av[i]);
		if (!array[j])
			return (NULL);
		i++;
		j++;
	}
	return (array);
}

char	**get_arguments(int ac, char **av)
{
	char	**args;

	args = NULL;
	if (2 == ac)
		args = ft_split(av[1], ' ');
	else if (ac > 2)
		args = exclude_executable(ac, av);
	if (!args)
		return (NULL);
	if (search_dups(args) && ft_parsing(args))
		return (args);
	else
		return (free_array(args), NULL);
}
