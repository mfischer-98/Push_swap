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

/* void	sort_two(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = first->next;
	if (first->index > second->index)
	{
		first->next = second->next; //first aponta para nulo ou prox node
		second->next = first; //second aponta para o first
		*a = second; //a aponta para o second, que agora é o primeiro node
	}
	ft_printf("sa\n"); //olhar instrucoes
}

void	sort_three(t_stack **a)
{
	t_stack *first;
	t_stack	*second;
	t_stack	*third;

	first = *a;
	second = first->next;
    third = second->next;
	if (first->number > second->number)
	{
		sort_two(a);
        ft_printf("sa\n");
        // Update pointers after swap
        first = *a;
        second = first->next;
        third = second->next;
	}
	if (first->number > third->number)
	{
		third->next = first;
		second->next = NULL;
		*a = third;
		ft_printf("rra\n");
	}
}

void	few_args(t_stack **a, int size)
{
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a);
	// if (size == 4)
	// 	sort_four(&a);
} */

int	main(int ac, char **av)
{
	int		args_num;
	t_stack	*a;

	a = NULL; //inicializo a stack VAZIA, é só um pro vazio
	if (ac == 1)
		exit(0);
	args_num = parsing(ac, av, &a);
	if (!args_num)
		exit(1); //invalid args
	if (check_order(&a))
		exit(0); //numbers are in order
	index_list(&a);
	// if (args_num < 5)
	// 	few_args(&a, args_num);
	// // if (args_num >= 5)
	// // 	radix_sort();
	// print_list(&a);
	// return (0);
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