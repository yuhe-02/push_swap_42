/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_position2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:58:40 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:54:56 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	look_for_minpos2(t_cross **stack1)
{
	int		index;
	int		col;
	int		value;
	t_cross	*tmp;

	index = 1;
	col = 1;
	value = INT_MAX;
	tmp = (*stack1)->next;
	while (tmp->rank != -1)
	{
		if (value > tmp->rank)
		{
			value = tmp->rank;
			col = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (col);
}

int	search_under_limit2(t_cross **stack1, int limit, int *value)
{
	int		index;
	t_cross	*tmp;

	index = 0;
	tmp = (*stack1)->next;
	while (tmp->rank != -1)
	{
		if (tmp->rank <= limit)
		{
			*value = tmp->rank;
			return (index);
		}
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	rv_search_under_limit2(t_cross **stack1, int limit, int *value)
{
	int		index;
	t_cross	*tmp;

	index = ft_lstsize(stack1) - 1;
	tmp = (*stack1)->prev;
	while (tmp->rank != -1)
	{
		if (tmp->rank <= limit)
		{
			*value = tmp->rank;
			return (index);
		}
		tmp = tmp->prev;
		index--;
	}
	return (index);
}

int	search_value2(t_cross **stack, int value)
{
	int		index;
	t_cross	*tmp;

	index = 0;
	tmp = (*stack)->next;
	while (tmp->rank != -1)
	{
		if (tmp->rank == value)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (index);
}
