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

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
			return ; //dar free dos nodes antigos caso algo errado
	new_node->number = num;
	new_node->next = *a; // || NULL? novo node aponta para o topo da lista, ele mesmo
	*a = new_node; //primeiro da stack é o new node
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