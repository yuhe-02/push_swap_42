/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simpleatoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:22:34 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:29:33 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_simpleatoi(const char *str)
{
	int	num;
	int	i;
	int	minusflg;

	i = 0;
	minusflg = 1;
	num = 0;
	if (str[i] == '-')
	{
		minusflg = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0') * minusflg;
		i++;
	}
	return (num);
}
