/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:08:44 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/27 17:35:57 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_moves(char *input)
{
	if (0 == ft_strncmp(input, "sa\n", 3))
		return (1);
	else if (0 == ft_strncmp(input, "sb\n", 3))
		return (2);
	else if (0 == ft_strncmp(input, "ss\n", 3))
		return (3);
	else if (0 == ft_strncmp(input, "pa\n", 3))
		return (4);
	else if (0 == ft_strncmp(input, "pb\n", 3))
		return (5);
	else if (0 == ft_strncmp(input, "ra\n", 3))
		return (6);
	else if (0 == ft_strncmp(input, "rb\n", 3))
		return (7);
	else if (0 == ft_strncmp(input, "rr\n", 3))
		return (8);
	else if (0 == ft_strncmp(input, "rra\n", 4))
		return (9);
	else if (0 == ft_strncmp(input, "rrb\n", 4))
		return (10);
	else if (0 == ft_strncmp(input, "rrr\n", 3))
		return (11);
	else
		return (write(2, RED"Error\n", 11), 0);
}

void	apply_input(int input_code, t_stack **clone_a, t_stack **clone_b)
{
	if (1 == input_code)
		sa(clone_a, 0);
	else if (2 == input_code)
		sb(clone_b, 0);
	else if (3 == input_code)
		ss(clone_a, clone_b, 0);
	else if (4 == input_code)
		pa(clone_b, clone_a, 0);
	else if (5 == input_code)
		pb(clone_a, clone_b, 0);
	else if (6 == input_code)
		ra(clone_a, 0);
	else if (7 == input_code)
		rb(clone_b, 0);
	else if (8 == input_code)
		rr(clone_a, clone_b, 0);
	else if (9 == input_code)
		rra(clone_a, 0);
	else if (10 == input_code)
		rrb(clone_b, 0);
	else if (11 == input_code)
		rrr(clone_a, clone_b, 0);
}

// Verifies that the numbers were put in the right order
int	check_sequence(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*temp;

	temp = stack_a;
	if (stack_b)
		return (write(1, YELLOW"KO\n"NO_COLOR, 11), 0);
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return (ft_printf(YELLOW"KO\n",NO_COLOR, 0));
		temp = temp->next;
	}
	return (ft_printf(GREEN"OK\n"NO_COLOR, 1));
}

// Verifies the validity of the moves gives as imput before applying them
int	check_moves(char **args)
{
	t_stack	*clone_a;
	t_stack	*clone_b;
	int		input_code;
	char	*input;

	clone_b = NULL;
	clone_a = ft_fill_stack(args);
	input_code = 0;
	input = NULL;
	input = get_next_line(0);
	while (input != NULL && input_code != -1)
	{
		input_code = parse_moves(input);
		free(input);
		apply_input(input_code, &clone_a, &clone_b);
		if (input_code == 0)
			return (free_stack(&clone_a), free_stack(&clone_b), 0);
		input = get_next_line(0);
	}
	check_sequence(clone_a, clone_b);
	free_stack(&clone_b);
	free_stack(&clone_a);
	return (1);
}

int	main(int ac, char *av[])
{
	char	**args;

	if (ac < 2)
		return (0);
	args = get_arguments(ac, av);
	if (!args)
		return (0);
	check_moves(args);
	free_array(args);
}
