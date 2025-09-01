/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:56:25 by mefische          #+#    #+#             */
/*   Updated: 2025/08/08 15:56:25 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		args_num;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(0);
	args_num = parsing(ac, av, &a);
	if (!args_num)
		exit(1);
	if (check_order(&a))
		exit(0);
	if (args_num <= 5)
		few_args(&a, &b, args_num);
	if (args_num > 5)
		radix_sort(&a, &b, args_num);
	if (a)
		free_list(a);
	if (b)
		free_list(b);
	return (0);
}
