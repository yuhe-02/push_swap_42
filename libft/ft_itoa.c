/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:58:42 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/24 23:37:16 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	count_digits(long n)
{
	long	div;

	div = n / 10;
	if (div == 0)
		return (1);
	return (1 + count_digits(div));
}

void	transform_integer(char *str, int len_s, long n)
{
	long	div;
	char	mod_s;

	div = n / 10;
	if (div != 0)
		transform_integer(str, len_s - 1, div);
	mod_s = (n % 10) + '0';
	str[len_s - 1] = mod_s;
	return ;
}

char	*ft_itoa(int n)
{
	int		len_s;
	int		flg;
	long	num;
	char	*number;

	num = (long)n;
	flg = 0;
	if (num < 0)
	{
		num *= -1;
		flg = 1;
	}
	len_s = count_digits(num) + flg;
	number = (char *)malloc(sizeof(char) * (len_s + 1));
	if (number == NULL)
		return (NULL);
	if (flg == 1)
		number[0] = '-';
	transform_integer((number + flg), len_s - flg, num);
	number[len_s] = '\0';
	return (number);
}