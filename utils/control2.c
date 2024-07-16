/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:30:14 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/16 23:03:37 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	ft_rotate_sametime(t_cross **stack_a, t_cross **stack_b, int flg)
{
	ft_rotate(stack_a, 2);
	ft_rotate(stack_b, 2);
	if (flg)
		write(1, "rr\n", 3);
}

void	ft_reverse_rotate_sametime(t_cross **sa, t_cross **sb, int flg)
{
	ft_reverse_rotate(sa, 2);
	ft_reverse_rotate(sb, 2);
	if (flg)
		write(1, "rrr\n", 4);
}

void	ft_swap_sametime(t_cross **stack_a, t_cross **stack_b, int flg)
{
	ft_swap(stack_a, 2);
	ft_swap(stack_b, 2);
	if (flg)
		write(1, "ss\n", 3);
}
