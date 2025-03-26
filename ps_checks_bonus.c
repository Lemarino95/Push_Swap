/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:35:07 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/26 19:53:54 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"

static int	parse_moves(char *input)
{
	if (ft_strncmp(input, "sa\n", 3) == 0)
		return (1);
	else if (ft_strncmp(input, "sb\n", 3) == 0)
		return (2);
	else if (ft_strncmp(input, "ss\n", 3) == 0)
		return (3);
	else if (ft_strncmp(input, "pa\n", 3) == 0)
		return (4);
	else if (ft_strncmp(input, "pb\n", 3) == 0)
		return (5);
	else if (ft_strncmp(input, "ra\n", 3) == 0)
		return (6);
	else if (ft_strncmp(input, "rb\n", 3) == 0)
		return (7);
	else if (ft_strncmp(input, "rr\n", 3) == 0)
		return (8);
	else if (ft_strncmp(input, "rra\n", 4) == 0)
		return (9);
	else if (ft_strncmp(input, "rrb\n", 4) == 0)
		return (10);
	else if (ft_strncmp(input, "rrr\n", 3) == 0)
		return (11);
	else
		return (-42);
}	

void	apply_input(int input_code, t_stack **clone_a, t_stack **clone_b)
{
	
}

int	check_moves(char **args)
{
	t_stack	*clone_a;
	t_stack	*clone_b = NULL;
	int		input_code;
	char	*input;

	clone_a = ft_fill_stack(args);
	input_code = 0;
	input = "";
	while (input_code != -1)
	{
		if (input_code == -42)
			return (0);
		input = get_next_line(0);
		input_code = parse_moves(input);
		apply_input(input_code, &clone_a, &clone_b);
		free(input);
	}
	return (1);
}

// Verifies that the numbers were put in the right order
int	check_sequence(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *temp;

	temp = stack_a;
	if (stack_b)
		return(write(1, YELLOW"KO\n"NO_COLOR, 11), 0);
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return(write(1, YELLOW"KO\n"NO_COLOR, 11), 0);
		temp = temp->next;
	}
	return(write(1, GREEN"OK\n"NO_COLOR, 11), 1);
}
