/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 23:09:40 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:29:48 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

size_t	ft_lstsize(t_cross **stack)
{
	size_t	len;
	t_cross	*tmp;

	len = 0;
	if (!stack)
		return (len);
	tmp = (*stack)->next;
	while (tmp->rank != -1)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
