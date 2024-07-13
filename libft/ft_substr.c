/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 07:38:38 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:30:32 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*str2;
	size_t			last;

	if (!(s))
		return (0);
	last = 0;
	str2 = (char *)s;
	if (start < ft_strlen(str2))
		last = ft_strlen(str2) - start;
	if (last > len)
		last = len;
	str = (char *)malloc(last + 1);
	if (!(str))
		return (NULL);
	ft_strlcpy(str, str2 + start, last + 1);
	return (str);
}
