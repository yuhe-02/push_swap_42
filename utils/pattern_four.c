/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_four.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 00:32:51 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/01 21:59:12 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	pattern_four(t_cross **stack1, t_cross **stack2, int flag)
{
	int	pos;

	pos = look_for_minpos(stack1);
	if (pos != 4)
		while (pos > 1)
		{
			ft_rotate(stack1, 0);
			pos--;
		}
	else
		ft_reverse_rotate(stack1, 0);
	ft_push(stack2, stack1, 1);
	pattern_three(stack1, 0);
	ft_push(stack1, stack2, 0);
}