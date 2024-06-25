/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:00:20 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/25 22:42:34 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_lstadd_back(t_cross **lst, t_cross *new)
{
	t_cross *last;

	if (!(lst) || !(new))
		return ;
	if (*lst != NULL)
	{
		last = (*lst)->prev;
		last->next = new;
        new->prev = last;
        new->next = *lst;
        (*lst)->prev = new;
	}
	else
	{
		new->next = new;
        new->prev = new;
        *lst = new;
	}
}