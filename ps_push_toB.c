/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_toB.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:21:56 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/27 17:54:26 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Pushes to stack B all nodes whith a number below the median, 
//  except the biggest three (in case of a very small list)
static void	push_lowest(t_stack **stack_a, t_stack **stack_b, \
												int len_stack_a, bool wflag)
{
	while (ft_stacksize(*stack_a) > (len_stack_a / 2))
	{
		if ((*stack_a)->index <= (len_stack_a / 2) && \
						(*stack_a)->index < (len_stack_a - 3))
			pb(stack_a, stack_b, wflag);
		else
			ra(stack_a, wflag);
	}
}

// Pushes to stack B the remaing nodes, except the three biggest numbers
static void	push_to_three(t_stack **stack_a, t_stack **stack_b, \
												int len_stack_a, bool wflag)
{
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->index < (len_stack_a - 3))
			pb(stack_a, stack_b, wflag);
		else
			ra(stack_a, wflag);
	}
}

// Pushes to stack B all nodes but the biggest ones
void	fill_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	len_stack_a;

	len_stack_a = ft_stacksize(*stack_a);
	if (len_stack_a > 6)
		push_lowest(stack_a, stack_b, len_stack_a, 1);
	if (len_stack_a > 2)
	{
		push_to_three(stack_a, stack_b, len_stack_a, 1);
		three_sort(stack_a);
	}
}
