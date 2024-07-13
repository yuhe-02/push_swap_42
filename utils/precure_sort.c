/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precure_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 22:57:44 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/11 00:15:17 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	init_array(int *nums, int argc)
{
	nums[0] = decide_range(argc);
	nums[1] = nums[0] * 0.6;
	nums[2] = INT_MIN;
	nums[3] = argc;
	nums[4] = 0;
}

void	move_to_b(t_cross **stack_a, t_cross **stack_b, int argc)
{
	int	nums[5];

	init_array(nums, argc);
	while (nums[3] > 0)
	{
		if ((*stack_a)->next->rank < nums[0])
		{
			ft_push(stack_b, stack_a, 1);
			nums[0]++;
			nums[3]--;
			nums[4]++;
			if (nums[2] < ((*stack_b)->next)->rank)
				nums[2] = ((*stack_b)->next)->rank;
			opt_by_rotate(stack_a, stack_b, nums);
		}
		else
			ft_rotate(stack_a, 0);
	}
}

static void	move_to_target(t_cross **stack, int num, void (*f)(t_cross **, int))
{
	int	count;

	count = 0;
	while (count < num)
	{
		f(stack, 1);
		count++;
	}
}

void	move_to_a(t_cross **stack_a, t_cross **stack_b, int argc)
{
	int	pos;
	int	count;

	while (argc > 0)
	{
		count = 0;
		pos = search_value(stack_b, argc - 1);
		if (pos < argc - pos)
			move_to_target(stack_b, pos, ft_rotate);
		else
			move_to_target(stack_b, argc - pos, ft_reverse_rotate);
		ft_push(stack_a, stack_b, 0);
		argc--;
	}
}

void	precure_sort(t_cross **stack_a, t_cross **stack_b, int argc)
{
	move_to_b(stack_a, stack_b, argc);
	move_to_a(stack_a, stack_b, argc);
}
