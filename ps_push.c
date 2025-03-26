/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:16:56 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/26 12:47:06 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **root1, t_stack **root2)
{
	t_stack	*tmp;

	tmp = *root2;
	*root2 = *root1;
	*root1 = (*root1)->next;
	(*root2)->next = tmp;
}

// Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_stack **stack_b, t_stack **stack_a, bool wflag)
{
	if (*stack_b && stack_b)
	{
		ft_push(stack_b, stack_a);
		if (wflag)
			ft_printf("pa\n");
	}
	else
		ft_printf(RED"Missing stack_b\n"NO_COLOR);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_stack **stack_a, t_stack **stack_b, bool wflag)
{
	if (*stack_a && stack_a)
	{
		ft_push(stack_a, stack_b);
		if (wflag)
			ft_printf("pb\n");
	}
	else
		ft_printf(RED"Missing stack_a\n"NO_COLOR);
}
