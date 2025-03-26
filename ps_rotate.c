/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:58:08 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/26 12:44:49 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Variables are named after the position they will occupy at the end
void	ft_rotate(t_stack **root)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*tmp;

	last = *root;
	first = (*root)->next;
	tmp = *root;
	tmp = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
	last->next = NULL;
	*root = first;
}

//  Shift up all elements of stack a by 1.
// The first element becomes the last one.
void	ra(t_stack **stack_a, bool wflag)
{
	if (*stack_a && (*stack_a)->next)
	{
		ft_rotate(stack_a);
		if (wflag)
			ft_printf("ra\n");
	}
	else
		ft_printf(RED"Could't rotate stack_a."NO_COLOR);
}

//  Shift up all elements of stack b by 1.
// The first element becomes the last one.
void	rb(t_stack **stack_b, bool wflag)
{
	if (*stack_b && (*stack_b)->next)
	{
		ft_rotate(stack_b);
		if (wflag)
			ft_printf("rb\n");
	}
	else
		ft_printf(RED"Could't rotate stack_b."NO_COLOR);
}

// ra and rb at the same time
void	rr(t_stack **stack_a, t_stack **stack_b, bool wflag)
{
	if (*stack_a && (*stack_a)->next && *stack_b && (*stack_b)->next)
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		if (wflag)
			ft_printf("rr\n");
	}
	else
		ft_printf(RED"Could't rotate stacks."NO_COLOR);
}
