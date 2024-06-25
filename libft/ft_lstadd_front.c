/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:00:32 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/25 22:25:32 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ft_lstadd_front(t_cross **lst, t_cross *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->prev = (*lst)->prev; 
	(*lst)->prev = new;
	if ((*lst)->prev != NULL)
		((*lst)->prev)->next = new;
	*lst = new;
}