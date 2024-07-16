/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:53:20 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/16 22:53:54 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*str;
	char	*temp;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(dup))
		return (NULL);
	str = (char *)s;
	temp = dup;
	while (*str)
		*temp++ = *str++;
	*temp = '\0';
	return (dup);
}