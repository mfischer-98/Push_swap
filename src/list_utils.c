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

void	list_init(t_stack **a, int size, long *numbers)
{
	int	i;
	t_stack *new_node;

	i = 0;
	while (i < size)
	{
		new_node = create_node((int)numbers[i]);
		if (!new_node)
			return ; //dar free dos nodes antigos caso algo errado
		new_node->next = *a; //novo node aponta para o topo da lista, ele mesmo
		*a = new_node; //primeiro da stack é o new node
		i++;
	}
}

t_stack	*create_node(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = num;
	node->next = NULL; //isso vai depois ser overwritten depois da primeira iteracao
	return (node);
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