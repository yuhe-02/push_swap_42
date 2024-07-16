/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:09:54 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:51:24 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	*get_array(int argc, char **strs)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * argc);
	if (!array)
		exit(0);
	while (i < argc)
	{
		array[i] = ft_simpleatoi(strs[i]);
		i++;
	}
	return (array);
}

void	sort_array(int argc, int *array)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}
