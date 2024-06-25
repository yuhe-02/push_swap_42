/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 08:02:11 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/24 21:29:04 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	int				i;
	unsigned char	word;

	str = (char *)s;
	word = (unsigned char)c;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == word)
			return (&str[i]);
		i++;
	}
	if (word == '\0')
		return (&str[i]);
	return (0);
}
