/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:09:47 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:51:48 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	create_cross(t_cross **stack, int argc, int *array, t_cross **stack_b)
{
	t_cross	*node;
	t_cross	*node2;
	int		i;
	t_cross	*head;

	node = ft_lstnew(0, -1);
	node2 = ft_lstnew(0, -1);
	i = 0;
	if (!node || !node2)
		exit(0);
	*stack = NULL;
	*stack_b = NULL;
	ft_lstadd_back(stack, node);
	ft_lstadd_back(stack_b, node2);
	while (i < argc)
	{
		node = ft_lstnew(array[i], 0);
		if (!node)
			exit(0);
		ft_lstadd_back(stack, node);
		i++;
	}
}

void	assign_order(t_cross *stack, int argc, int *array)
{
	int	i;

	stack = stack->next;
	while (stack->rank != -1)
	{
		i = 0;
		while (i < argc)
		{
			if (stack->value == array[i])
			{
				stack->rank = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

int	is_already_sorted(t_cross **stack)
{
	int		value;
	t_cross	*tmp;

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
