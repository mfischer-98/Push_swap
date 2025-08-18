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

//Normalization
void	normalize_numbers(t_stack **a);
t_stack	*merge_sort(t_stack **lst);
t_stack	*get_mid(t_stack **lst);
t_stack	*merge_list(t_stack **lst, t_stack *left, t_stack *right);

//Sorting < 5
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);

#endif