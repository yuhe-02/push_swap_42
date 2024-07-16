/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 21:32:04 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/13 21:40:20 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	free_str_array(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i++]);
	}
	free(str);
}

void	free_nodes(t_cross **stack_a, t_cross **stack_b)
{
	t_cross	*tmp;
	t_cross	*tar;

	tmp = (*stack_a)->next;
	while (tmp->rank != -1)
	{
		tar = tmp;
		tmp = tmp->next;
		free(tar);
	}
	free(*stack_a);
	free(*stack_b);
}
