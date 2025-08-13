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
	int args_num;
	long *numbers;

	numbers = NULL;
	args_num = parsing(ac, av, &numbers);
	if (!args_num)
	{
		ft_printf("Invalid args\n");
		exit(1); //invalid args
	}
	if (check_order(numbers, args_num))
		exit(0); //numbers are in order
	ft_printf("Size: %d\n", args_num);
	int i = 0;
	while (args_num > 0)
	{
		printf("Number: %ld\n", numbers[i]);
		i++;
		args_num--;
	}

	//if (args_num < 5) functions to fix two, 3 and 4
	//if (args_num >= 5) radix function
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