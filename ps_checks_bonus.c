/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:35:07 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/26 17:35:42 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

// Verifies that the numbers were put in the right order
ssize_t	check_sequence(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp;

	temp = stack_a;
	if (stack_b)
		return(write(1, YELLOW"KO\n"NO_COLOR, 11));
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return(write(1, YELLOW"KO\n"NO_COLOR, 11));
		temp = temp->next;
	}
	return(write(1, GREEN"OK\n"NO_COLOR, 11));
}

