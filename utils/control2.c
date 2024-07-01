/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 21:30:14 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/01 21:31:53 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	ft_rotate_sametime(t_cross **stack_a, t_cross **stack_b)
{
	ft_rotate(stack_a, 2);
	ft_rotate(stack_b, 2);
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate_sametime(t_cross **stack_a, t_cross **stack_b)
{
	ft_reverse_rotate(stack_a, 2);
	ft_reverse_rotate(stack_b, 2);
	write(1, "rrr\n", 4);
}

void	ft_swap_sametime(t_cross **stack_a, t_cross **stack_b)
{
	ft_swap(stack_a, 2);
	ft_swap(stack_b, 2);
	write(1, "ss\n", 3);
}