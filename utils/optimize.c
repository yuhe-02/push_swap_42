/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:10:43 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/16 23:04:36 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	decide_range(int argc)
{
	return ((int)((7 * argc) / 100 + 5));
}

void	opt_by_rotate(t_cross **sa, t_cross **sb, int nums[5])
{
	if (nums[4] < 2)
		return ;
	if (((*sb)->next)->rank >= nums[2] - nums[1])
	{
		if (nums[3] > 2 && (*sa)->next->rank > nums[0])
			ft_rotate_sametime(sa, sb, 1);
		else
			ft_rotate(sb, 1);
	}
	else if (((*sb)->next)->rank < (((*sb)->next)->next)->rank)
		ft_swap(sb, 1);
}
