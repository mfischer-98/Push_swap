/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 10:01:09 by mefische          #+#    #+#             */
/*   Updated: 2025/08/11 15:16:28 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	list_init(t_stack **a, int num)
{
	t_stack *new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
			return ; //dar free dos nodes antigos caso algo errado
	new_node->number = num;
	new_node->next = NULL; // to add ao fim da lista
	//encontro ultimo node e aponto o novo node pra ele
	last = *a;
	if (*a == NULL) //se lista vazia, o node vira head
	{
		*a = new_node;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
}

void	free_list(t_stack *a)
{
	t_stack	*temp;

	while (a != NULL)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	free(a);
}

void	index_list(t_stack **a)
{
	t_stack	*i;
	t_stack *j;
	int		count;

	i = *a;
	while (i)
	{
		j = *a;
		count = 0;
		while(j)
		{
			if (i->number > j->number)
				count++;
			j = j->next;
		}
		i->index = count;
		i = i->next;
	}
}

int	get_min(t_stack **stack)
{
	//create temp and compare with min(first number)
	//if current number < min then I change it to current
	t_stack	*temp;
	int		min;

	min = (*stack)->number;
	temp = (*stack)->next;
	while (temp)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next; 
	}
	//ft_printf("min: %d\n", min);
	return (min);
}
