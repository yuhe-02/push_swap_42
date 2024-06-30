/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 22:10:02 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/27 22:10:03 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_cross	*ft_lstpop(t_cross **lst)
{
	t_cross *tmp;

	if (!lst || ((*lst)->next)->rank == -1)
		return NULL;
	tmp = (*lst)->next;
	(tmp->next)->prev = tmp->prev;
	(tmp->prev)->next = tmp->next;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}