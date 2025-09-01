/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 10:07:49 by mefische          #+#    #+#             */
/*   Updated: 2025/08/20 10:07:49 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	sa(a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->number;
	second = (*a)->next->number;
	third = (*a)->next->next->number;
	if (first > second && first > third)
		ra(a);
	else if (second > first && second > third)
		rra(a);
	first = (*a)->number;
	second = (*a)->next->number;
	if (first > second)
		sa(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int		min;

	min = get_min(a);
	while ((*a)->number != min)
		rra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(a);
	while ((*a)->number != min)
		rra(a);
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	few_args(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_two(a);
	if (size == 3)
		sort_three(a);
	if (size == 4)
		sort_four(a, b);
	if (size == 5)
		sort_five(a, b);
}
