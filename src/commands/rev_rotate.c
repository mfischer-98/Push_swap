/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_extra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:11:46 by mefische          #+#    #+#             */
/*   Updated: 2025/08/20 12:11:46 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	second_last = *stack;
	while (second_last->next->next) //encontro penultimo node
		second_last = second_last->next;
	last = second_last->next; //ultimo node é o proximo
	last->next = *stack; //ultimo aponta para o inicio da stack (segundo agora)
	*stack = last; //stack atualizada é last
	second_last->next = NULL; //penultimo aponta p nulo
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}
