/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:55:09 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/16 22:55:41 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap_bonus.h"

char	*ft_strjoin_custom(char *s1, char const *s2)
{
	char	*str;
	char	*ptr;
	char	*ptr1;
	char	*ptr2;

	str = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (str == NULL)
		return (finish_process(&s1, NULL, NULL));
	ptr = str;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (*ptr1)
		*(ptr++) = *(ptr1++);
	while (*ptr2)
		*(ptr++) = *(ptr2++);
	*ptr = '\0';
	free(s1);
	return (str);
}