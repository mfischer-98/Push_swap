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
int		parsing(int ac, char **av, long **numbers);
int		check_arg(char **av, long **numbers);
int		check_numbers(int n, char **av, long **numbers);
int		check_max(char **array, int size, long **numbers);
int 	check_duplicate(long *numbers, int size);
void	free_array(char **array, int n);
int		check_order(long *num, int n);

//List handling
void	list_init(t_stack **a, int size, long *numbers);
t_stack	*create_node(int num);
void	print_list(t_stack **a);

//Normalization
void	normalize_numbers(t_stack **a, long *array, int size);
void	quickSort(long *array, int start, int end);
int		partition(long *array, int start, int end);

//Sorting < 5
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);

#endif