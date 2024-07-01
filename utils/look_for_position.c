/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_for_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:58:40 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/01 21:58:42 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	look_for_minpos(t_cross **stack1)
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
		if (value > tmp->value)
		{
			value = tmp->value;
			col = index; 
		}
		tmp = tmp->next;
		index++;
	}
	return (col);
}