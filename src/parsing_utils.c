/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 10:52:01 by mefische          #+#    #+#             */
/*   Updated: 2025/08/13 10:52:01 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while(temp->next)
	{
		if (temp->number < temp->next->number)
			return (0);
		temp = temp->next;
	}
	return (free_list(*a), 1);
}

void	free_array(char **array, int n)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < n)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
}

void	print_list(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		printf("Node Number: %d  Index: %d\n", current->number, current->index);
		current = current->next;
	}
	//printf("Node Number: %d  Index: %d\n\n\n", current->number, current->index);
}
