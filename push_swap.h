/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarino <lemarino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:43:10 by lemarino          #+#    #+#             */
/*   Updated: 2025/03/27 16:05:08 by lemarino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MACROS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~~*/
# define NO_COLOR "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[95m"
# define CYAN "\033[36m"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STRUCTS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Rotation counter for stack A and B
typedef struct s_rotations
{
	int				a_rots;
	int				b_rots;
}					t_rotations;

typedef struct s_stack
{
	long			nbr;
	long			index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// ps_parsing.c
char				**get_arguments(int ac, char **av);

// ps_listutils.c
t_stack				*ft_fill_stack(char **array);
int					ft_stacksize(t_stack *root);
int					ft_abs(int n);
void				lowest_to_top(t_stack **stack, bool wflag);

// ps_swap.c
void				sa(t_stack **stack_a, bool wflag);
void				sb(t_stack **stack_b, bool wflag);
void				ss(t_stack **stack_a, t_stack **stack_b, bool wflag);

// ps_rotate.c
void				ra(t_stack **stack_a, bool wflag);
void				rb(t_stack **stack_b, bool wflag);
void				rr(t_stack **stack_a, t_stack **stack_b, bool wflag);

// ps_revrotate.c
void				rra(t_stack **stack_a, bool wflag);
void				rrb(t_stack **stack_b, bool wflag);
void				rrr(t_stack **stack_a, t_stack **stack_b, bool wflag);

// ps_push.c
void				pa(t_stack **stack_b, t_stack **stack_a, bool wflag);
void				pb(t_stack **stack_a, t_stack **stack_b, bool wflag);

// ps_indexing.c
void				create_index(char **array, t_stack *root);

// ps_push_toB.c.c
void				fill_stack_b(t_stack **stack_a, t_stack **stack_b);

// ps_three_sort.c
void				three_sort(t_stack **stack_a);

// ps_economy.c
void				get_cost_a(t_stack **stack_a);
void				get_cost_b(t_stack **stack_b);
void				get_costs(t_stack **stack_a, t_stack **stack_b);

// ps_economy2.c
int					*get_costs_array(t_stack *a, t_stack *b);
t_stack				*ft_lowest_cost(t_stack *b, int *costs_arr);

// ps_executemoves.c
void				pair_nodes_n_costs(t_stack **stack_a, t_stack **stack_b);

// ps_liberate
void				free_stack(t_stack **root);
void				free_array(char **array);

#endif

// valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all