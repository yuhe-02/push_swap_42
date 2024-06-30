/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpoplast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:19:54 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/29 00:08:19 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_cross	*ft_lstpoplast(t_cross **lst)
{
	t_cross	*tmp;

	if (!lst)
		return (NULL);
	tmp = (*lst)->prev;
	(tmp->prev)->next = tmp->next;
	(tmp->next)->prev = tmp->prev;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}