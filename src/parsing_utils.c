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

