/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mefische <mefische@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:39:18 by mefische          #+#    #+#             */
/*   Updated: 2025/08/15 10:39:18 by mefische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	normalize_numbers(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	merge_sort(&temp);
	print_list(&temp);
}

t_stack	*merge_sort(t_stack **lst)
{
	t_stack	*left;
	t_stack	*right;
	t_stack	*temp;

	//if ((*lst = NULL) || ((*lst)->next = NULL)) segfault
	if ((*lst)->next == NULL)
		return *lst;
	left = *lst;
	right = get_mid(lst);
	temp = right->next;
	right->next = NULL;
	right = temp;

	left = merge_sort(&left);
	right = merge_sort(&right);
	return (merge_list(lst, left, right));
}

t_stack	*get_mid(t_stack **lst)
{
	t_stack	*temp_slow;
	t_stack	*temp_fast;

	temp_slow = *lst;
	temp_fast = (*lst)->next;
	while (temp_fast && temp_slow) //segfault
	{
		temp_slow = temp_slow->next;
		temp_fast = temp_fast->next->next;
	}
	return (temp_slow);
}

t_stack	*merge_list(t_stack **lst, t_stack *left, t_stack *right)
{
	t_stack	*temp;
	t_stack	*tail;

	tail = NULL;//not sure
	temp = *lst;//not sure
	while(left && right)
	{
		if (left->number < right->number)// se o da esquerda for menor, coloco ele primeiro na tail e passo pro prox na da esquerda
		{
			tail->next = left;
			left = left->next;
		}
		else
		{
			tail->next = right;
			right = right->next;
		}
		tail = tail->next;
	}
	if (left) //se sobrar algum numero em uma das listas, coloco no final
		tail->next = left;
	if (right)
		tail->next = right;
	return (temp->next);//not sure
}
