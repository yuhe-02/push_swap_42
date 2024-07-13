/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:44:08 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:38:10 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

static void	initialize_array(t_cross **stack, int array[3])
{
	t_cross	*tmp;

	tmp = (*stack)->next;
	array[0] = tmp->rank;
	tmp = tmp->next;
	array[1] = tmp->rank;
	tmp = tmp->next;
	array[2] = tmp->rank;
}

static void	pt_three_2(t_cross **stack, int flag, int array[3])
{
	if (array[2] < array[0] && array[0] < array[1])
	{
		ft_reverse_rotate(stack, flag);
	}
	else if (array[1] < array[2] && array[2] < array[0])
	{
		ft_rotate(stack, flag);
	}
	else if (array[2] < array[1] && array[1] && array[0])
	{
		ft_rotate(stack, flag);
		ft_swap(stack, flag);
	}
}

void	pattern_three(t_cross **stack, int flag)
{
	int	array[3];

	initialize_array(stack, array);
	if (array[0] < array[1] && array[1] < array[2])
		return ;
	else if (array[0] < array[2] && array[2] < array[1])
	{
		ft_reverse_rotate(stack, flag);
		ft_swap(stack, flag);
	}
	else if (array[1] < array[0] && array[0] < array[2])
	{
		ft_swap(stack, flag);
	}
	else
		pt_three_2(stack, flag, array);
}
