/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:54:29 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/16 22:54:45 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(char const *s, size_t len)
{
	char			*str;
	char			*ptr;
	char			*s2;

	if (!(s))
		return (NULL);
	s2 = (char *)s;
	str = (char *)malloc(len + 1);
	if (!(str))
		return (NULL);
	ptr = str;
	while (len--)
		*(ptr++) = *(s2++);
	*ptr = '\0';
	return (str);
}