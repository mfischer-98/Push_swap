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
	if (parsing(ac, av))
	{
		ft_printf("Invalid args!\n");
		exit(1);
	}
	ft_printf("Valid args!\n");
	return (0);
}

/* 
00001100
00100001
00001010

2,1,4,10,7 antes
1,2,4,7,10 depois

{
	number: int;
	index: unsigned int;
}

{
	1; 2; 4; 7; 10 number
	0; 1; 2; 3; 4 index
}

{
	2; 1; 4; 10; 7
	1; 0; 2; 4; 3
} */