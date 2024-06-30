/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:09:47 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/29 00:26:04 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	create_cross(t_cross **stack, int argc, int *array, t_cross **stack_b)
{
	t_cross *node;
	t_cross *node2;
	int		i;
	t_cross *head;

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

void assign_order(t_cross *stack, int argc, int *array)
{
	int i;

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

void	output_cross(t_cross *stack)
{
	t_cross *head;

	head = stack->next;
	while (head->rank != -1)
	{
		printf("後ろのノードの値：%d 現在のノードの値：%d 次のノードの値：%d 大きさ: %d\n", (head->prev)->value, head->value, (head->next)->value, head->rank);
		printf("-----------------------------------------------------------------------\n");
		head = head->next;
	}
	printf("\n");
}

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

void	output_visible(t_cross *stack1, t_cross *stack2)
{
	size_t	s1 = ft_lstsize(&stack1);
	size_t	s2 = ft_lstsize(&stack2);
	t_cross *tmp1= stack1->next;
	t_cross *tmp2= stack2->next;
	size_t	i = 0;
	
	while (i < max(s1, s2))
	{
		if (s1 > s2 && i < (s1 - s2))
		{
			printf("%3d\n", tmp1->rank);
			tmp1 = tmp1->next;
		}
		else if (s1 < s2 && i < (s2 - s1))
		{
			printf("    %3d\n", tmp2->rank);
			tmp2 = tmp2->next;
		}
		else
		{
			printf("%3d %3d\n", tmp1->rank, tmp2->rank);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		i++;
	}
	printf("--- ---\n");
	printf(" a   b \n");
}