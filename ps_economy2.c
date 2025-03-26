/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_economy2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:40:07 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/25 21:44:43 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create an array holding the number of moves needed to move each element
//  in stackB above the greatest number inferior to it in stackA

static int	total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = ft_abs(cost_a);
	abs_b = ft_abs(cost_b);
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		else
			return (abs_b);
	}
	else
		return (abs_a + abs_b);
}

static int	fill_costs_array(t_stack *a, t_stack *tmp_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_a2;
	int		i;

	tmp_a = a;
	i = 1;
	while (tmp_a)
	{
		tmp_a2 = a;
		while (tmp_a2)
		{
			if (tmp_b->index == (tmp_a2->index - i))
				return (total_cost(tmp_a2->cost_a, tmp_b->cost_b));
			tmp_a2 = tmp_a2->next;
		}
		i++;
	}
	return (0);
}

int	*get_costs_array(t_stack *a, t_stack *b)
{
	t_stack	*tmp_b;
	int		*costs_arr;
	int		j;

	j = 0;
	tmp_b = b;
	costs_arr = malloc(ft_stacksize(b) * sizeof(int));
	if (!costs_arr)
		return (NULL);
	get_costs(&a, &b);
	while (tmp_b)
	{
		costs_arr[j] = fill_costs_array(a, tmp_b);
		tmp_b = tmp_b->next;
		j++;
	}
	return (costs_arr);
}

// Finds the cheapest number to move from stack B to A by comparing
//  the values in costs_arr
t_stack	*ft_lowest_cost(t_stack *b, int *costs_arr)
{
	t_stack	*tmp;
	t_stack	*cheapest_node;
	int		lowest_sofar;
	int		i;

	i = 0;
	lowest_sofar = costs_arr[i];
	tmp = b;
	cheapest_node = b;
	while (tmp)
	{
		if (costs_arr[i] < lowest_sofar)
		{
			lowest_sofar = costs_arr[i];
			cheapest_node = tmp;
		}
		tmp = tmp->next;
		i++;
	}
	return (cheapest_node);
}
