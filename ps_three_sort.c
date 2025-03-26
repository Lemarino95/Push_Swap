/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:57:32 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/26 12:56:49 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort_checks(t_stack **a, t_stack *first,
	t_stack *second, t_stack *third)
{
	if (first->nbr < second->nbr && second->nbr > third->nbr \
												&& first->nbr < third->nbr)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (first->nbr < second->nbr && second->nbr > third->nbr \
												&& first->nbr > third->nbr)
		rra(a, 1);
	else if (first->nbr > second->nbr && second->nbr > third->nbr \
												&& third->nbr < first->nbr)
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (first->nbr > second->nbr && second->nbr < third->nbr \
												&& third->nbr < first->nbr)
		ra(a, 1);
	else if (first->nbr > second->nbr && second->nbr < third->nbr \
												&& third->nbr > first->nbr)
		sa(a, 1);
}

void	three_sort(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = (*a);
	second = (*a)->next;
	third = (*a)->next->next;
	three_sort_checks(a, first, second, third);
}
