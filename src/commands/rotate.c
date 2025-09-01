/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:27:22 by mefische          #+#    #+#             */
/*   Updated: 2025/08/20 12:27:22 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*old_start;
	t_stack	*new_start;
	t_stack	*new_last;

	old_start = *stack;
	new_start = old_start->next;
	*stack = new_start;
	new_last = *stack;
	while (new_last->next != NULL)
		new_last = new_last->next;
	new_last->next = old_start;
	old_start->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}
