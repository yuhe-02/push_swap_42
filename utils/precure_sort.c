/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precure_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:57:44 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/03 23:53:39 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

int decide_range(int argc)
{
	return (argc / 6);
}

void	move_to_b(t_cross **stack_a, t_cross **stack_b, int argc)
{
	int	col_max = 25;
	int forward;
	int count;
	int num;
	int flg;
	int	num2;
	
	num = 1;
	num2 = (argc / col_max) * 0.8;
	while (argc > 0)
	{
		count = 0;
		forward = search_under_limit(stack_a, col_max);
		flg = 0;
		while (count < forward)
		{
			if (((*stack_b)->next)->rank >= get_max(stack_b) - num2 && !flg)
			{
				ft_rotate_sametime(stack_a, stack_b);
				flg = 1;
			}
			else
				ft_rotate(stack_a, 0);
			count++;
		}
		ft_push(stack_b, stack_a, 1);
		if (num >= 2 && ((*stack_b)->next)->rank < (((*stack_b)->next)->next)->rank)
		{
			if (((*stack_a)->next)->rank < (((*stack_a)->next)->next)->rank)
				ft_swap_sametime(stack_a, stack_b);
			else
				ft_swap(stack_b, 1);
		}
		col_max++;
		argc--;
		num++;
	}
}

// void	move_to_b(t_cross **stack_a, t_cross **stack_b, int argc)
// {
// 	int	col_max = 20;
// 	int forward[2];
// 	int count;
// 	int num;
// 	int flg;
// 	int backward[2];
	
// 	num = argc;
// 	while (argc > 0)
// 	{
// 		count = 0;
// 		forward[0] = search_under_limit2(stack_a, col_max, &forward[1]);
// 		backward[0] = rv_search_under_limit2(stack_a, col_max, &backward[1]);
// 		flg = 0;
// 		if (forward[0] < argc - backward[0])
// 		{
// 			while (count < forward[0])
// 			{
// 				if (((*stack_b)->next)->rank >= col_max*0.7 && (num - argc) % 2 == 0 && !flg)
// 				{
// 					ft_rotate_sametime(stack_a, stack_b);
// 					flg = 1;
// 				}
// 				else
// 					ft_rotate(stack_a, 0);
// 				count++;
// 			}
// 		}
// 		else
// 		{
// 			while (count < argc - backward[0])
// 			{
// 				ft_reverse_rotate(stack_a, 0);
// 				count++;
// 			}
// 		}
// 		ft_push(stack_b, stack_a, 1);
// 		if (num >= 2 && ((*stack_b)->next)->rank < (((*stack_b)->next)->next)->rank)
// 		{
// 			if (((*stack_a)->next)->rank < (((*stack_a)->next)->next)->rank)
// 				ft_swap_sametime(stack_a, stack_b);
// 			else
// 				ft_swap(stack_b, 1);
// 		}
// 		// if (((*stack_b)->next)->rank >= col_max*0.7 && (num - argc) % 2 == 0)
// 		// 	ft_rotate(stack_b, 1);
// 		col_max++;
// 		argc--;
// 	}
// }

void	move_to_a(t_cross **stack_a, t_cross **stack_b, int argc)
{
	int pos;
	int count;

	
	while (argc > 0)
	{
		count = 0;
		pos = search_value(stack_b, argc-1);
		if (pos < argc - pos)
		{
			while (count < pos)
			{
				ft_rotate(stack_b, 1);
				count++;
			}
		}
		else
		{
			while (count < argc - pos)
			{
				ft_reverse_rotate(stack_b, 1);
				count++;
			}
		}
		ft_push(stack_a, stack_b, 0);
		argc--;
	}
}

void	precure_sort(t_cross **stack_a, t_cross **stack_b, int argc)
{
	move_to_b(stack_a, stack_b, argc);
	move_to_a(stack_a, stack_b, argc);
}