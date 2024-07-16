/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:13:10 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:28:52 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_cross	*ft_lstnew(int value, int rank)
{
	t_cross	*str_t;

	str_t = (t_cross *)malloc(sizeof(t_cross));
	if (!(str_t))
		return (NULL);
	str_t->value = value;
	str_t->rank = rank;
	str_t->next = NULL;
	str_t->prev = NULL;
	return (str_t);
}
