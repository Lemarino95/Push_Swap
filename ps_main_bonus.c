/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:08:44 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/26 18:03:44 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	args = get_arguments(ac, av);
	if (!args)
		return (0);
	stack_a = ft_fill_stack(args);
	create_index(args, stack_a);
	fill_stack_b(&stack_a, &stack_b, 0);
	while (stack_b)
		pair_nodes_n_costs_bonus(&stack_a, &stack_b);
	lowest_to_top(&stack_a, 0);
	check_moves(args);
	check_sequence(stack_a, stack_b);
	free_array(args);
	free_stack(&stack_a);
}
