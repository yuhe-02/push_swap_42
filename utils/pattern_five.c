/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:31:14 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:55:55 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	pattern_five(t_cross **stack1, t_cross **stack2, int flag)
{
	int	pos;

	pos = look_for_minpos(stack1);
	if (pos <= 3)
	{
		while (pos > 1)
		{
			ft_rotate(stack1, 0);
			pos--;
		}
	}
	else
	{
		while (5 - pos >= 0)
		{
			ft_reverse_rotate(stack1, 0);
			pos++;
		}
	}
	ft_push(stack2, stack1, 1);
	pattern_four(stack1, stack2, 0);
	ft_push(stack1, stack2, 0);
}
