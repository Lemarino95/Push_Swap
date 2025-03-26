/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:16:18 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/26 12:46:15 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Variables are named after the position they will occupy at the end
void	ft_revrotate(t_stack **root)
{
	t_stack	*last;
	t_stack	*second;

	second = *root;
	while ((*root)->next->next)
		*root = (*root)->next;
	last = *root;
	*root = (*root)->next;
	(*root)->next = second;
	last->next = NULL;
}

// (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one
void	rra(t_stack **stack_a, bool wflag)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_revrotate(stack_a);
		if (wflag)
			ft_printf("rra\n");
	}
	else
		ft_printf(RED"Could't reverse-rotate stack_a."NO_COLOR);
}

// (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
void	rrb(t_stack **stack_b, bool wflag)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_revrotate(stack_b);
		if (wflag)
			ft_printf("rrb\n");
	}
	else
		ft_printf(RED"Could't reverse-rotate stack_b."NO_COLOR);
}

// rra and rrb at the same time
void	rrr(t_stack **stack_a, t_stack **stack_b, bool wflag)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		ft_revrotate(stack_a);
		ft_revrotate(stack_b);
		if (wflag)
			ft_printf("rrr\n");
	}
	else
		ft_printf(RED"Could't reverse-rotate stacks."NO_COLOR);
}
