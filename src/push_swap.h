/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:22:04 by mefische          #+#    #+#             */
/*   Updated: 2025/08/07 16:22:04 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}				t_stack;

//Parsing
int		parsing(int ac, char **av, t_stack **a);
int		check_arg(char **av, t_stack **a);
int		check_numbers(int n, char **av, t_stack **a);
int		check_max(char **array, int size, t_stack **a);
int 	check_duplicate(int *numbers, int size);
void	free_array(char **array, int n);
int		check_order(t_stack **a);

//List handling
void	list_init(t_stack **a, int num);
void	print_list(t_stack **a);
void	free_list(t_stack *a);
void	index_list(t_stack **a);
int		get_min(t_stack **stack);

//Sorting < 5
void	few_args(t_stack **a, t_stack **b, int size);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

//Commands
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	reverse_rotate_a(t_stack **a, int size);
void	rra(t_stack **a);
void	rrb(t_stack **b);

#endif