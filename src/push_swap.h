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
	struct stack	*next;
}				t_stack;

//Parsing
int		parsing(int ac, char **av);
int		check_arg(char **av);
int		check_numbers(int n, char **av);
int		check_max(char **array, int size);
int 	check_duplicate(long *num, int size);
void	free_array(char **array, int n);

#endif