/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:11:03 by yyamasak          #+#    #+#             */
/*   Updated: 2024/08/04 14:18:40 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	ft_push(t_cross **target, t_cross **src, int flag)
{
	t_cross	*tmp;

	tmp = ft_lstpop(src);
	ft_lstadd_front(target, tmp);
	if (!flag)
		write(1, "pa\n", 3);
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	ft_swap(t_cross **target, int flag)
{
	t_cross	*first;
	t_cross	*second;
	t_cross	*third;

	first = (*target)->next;
	second = first->next;
	third = second->next;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = (*target);
	(*target)->next = second;
	if (!flag)
		write(1, "sa\n", 3);
	else if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_rotate(t_cross **stack, int flag)
{
	t_cross	*tmp;

	tmp = ft_lstpop(stack);
	ft_lstadd_back(stack, tmp);
	if (!flag)
		write(1, "ra\n", 3);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_cross **stack, int flag)
{
	t_cross	*tmp;

	tmp = ft_lstpoplast(stack);
	ft_lstadd_front(stack, tmp);
	if (!flag)
		write(1, "rra\n", 4);
	if (flag == 1)
		write(1, "rrb\n", 4);
}
