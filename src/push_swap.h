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
# include <stdio.h>

struct stack
{
	int				number;
	int				index;
	struct stack	*next;
};

//Parsing
int	parsing(int ac, char **av);
int	check_arg(char **av);
int	check_numbers(int n, char **av);

#endif