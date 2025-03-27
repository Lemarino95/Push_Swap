/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:10:29 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/27 16:12:43 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	fill_stack_b(&stack_a, &stack_b);
	while (stack_b)
	{
		pair_nodes_n_costs(&stack_a, &stack_b);
	}
	lowest_to_top(&stack_a, 1);
	free_array(args);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
