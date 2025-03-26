/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_economy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:13:21 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/21 19:33:43 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate the number and type of rotations to bring each node to the top
// cost < 0: rotate.
// cost > 0: reverse rotate.

void	get_cost_a(t_stack **stack_a)
{
	t_stack	*tmp;
	int		i;
	int		median;
	size_t	len;

	tmp = *stack_a;
	i = 0;
	len = ft_stacksize(tmp);
	median = (len / 2) + 1;
	while (tmp)
	{
		if (i < median)
			tmp->cost_a = -i;
		else
			tmp->cost_a = len - i;
		i++;
		tmp = tmp->next;
	}
}

void	get_cost_b(t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;
	int		median;
	size_t	len;

	tmp = *stack_b;
	i = 0;
	len = ft_stacksize(tmp);
	median = (len / 2) + 1;
	while (tmp)
	{
		if (i < median)
			tmp->cost_b = -i;
		else
			tmp->cost_b = len - i;
		i++;
		tmp = tmp->next;
	}
}

void	get_costs(t_stack **stack_a, t_stack **stack_b)
{
	get_cost_a(stack_a);
	get_cost_b(stack_b);
}
