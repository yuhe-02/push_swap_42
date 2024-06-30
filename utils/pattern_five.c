/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:31:14 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/29 00:46:25 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

static	int max(int array[5])
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < 5)
	{
		if (rank < array[i])
			rank = array[i];
		i++;
	}
	return (rank);
}

static int	is_already_sorted(t_cross **stack)
{
	int		value;
	t_cross *tmp;

	value = -1;
	tmp = (*stack)->next;
	while (tmp->rank != -1)
	{
		if (value > tmp->rank)
			return (0);
		value = tmp->rank;
		tmp = tmp->next;
	}
	return (1);
}

static void	initialize_array(t_cross **stack, int array[5])
{
	t_cross	*tmp;

	tmp = (*stack)->next;
	array[0] = tmp->rank;
	tmp = tmp->next;
	array[1] = tmp->rank;
	tmp = tmp->next;
	array[2] = tmp->rank;
	tmp = tmp->next;
	array[3] = tmp->rank;
	tmp = tmp->next;
	array[4] = tmp->rank;
}

void	easy_step(t_cross **stack, int array[5], int flag)
{
	if (array[0])
}

void	pattern_five(t_cross **stack1, t_cross **stack2, int flag)
{
	int	max_value;
	int	array[5];

	initialize_array(stack1, array);
	max_value = max(array);
	if (is_already_sorted(array))
		return ;
	if (easy_step(stack1, array, flag))
		return ;
}