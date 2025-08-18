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

void	normalize_numbers(t_stack **a, long *array, int size)
{
	t_stack *current;
	int		i;

	quickSort(array, 0, size - 1);
	current = *a;
	while (current != NULL)
	{
		i = 0;
		while (i < size && array[i] != current->number)
			i++;
		current->index = i;
		current = current->next;
	}
	print_list(a);
}


void	quickSort(long *array, int start, int end)
{
	int	pivot;

	if (end <= start) //base case para a recursao
		return ;
	pivot = partition(array, start, end);
	quickSort(array, start, pivot - 1); //sort subarray esq
	quickSort(array, pivot + 1, end); //sort subarray direita
}

int	partition(long *array, int start, int end)
{
	long	pivot;
	long	temp;
	int		i;
	int		j;

	pivot = array[end]; //pivot é o último elemento
	temp = 0;
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] < pivot) //se for menor passo pra esquerda, pro i
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
		}
		j++;
	}
	i++; //quero que o pivot seja a proxima posicao de i
	temp = array[i]; //troco o array de i com o temp 
	array[i] = array[end];
	array[end] = temp;
	return (i);
}
