/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:56:00 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/10 23:29:59 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	count_words(char const *tmp, char c)
{
	size_t	i;
	int		flg;
	size_t	count;

	flg = 0;
	i = 0;
	count = 0;
	if (!tmp[i])
		return (0);
	while (tmp[i])
	{
		if (tmp[i] != c && flg == 0)
		{
			flg = 1;
			count++;
		}
		if (tmp[i] == c)
			flg = 0;
		i++;
	}
	return (count);
}

size_t	string_len(char const *s, char c)
{
	size_t	word_len;

	if (!ft_strchr(s, c))
		word_len = ft_strlen(s);
	else
		word_len = ft_strchr(s, c) - s;
	return (word_len);
}

static void	*free_array(char **result, int j)
{
	int	i;

	if (!result)
		return (NULL);
	i = 0;
	while (i < j)
		free(result[i++]);
	free(result);
	return (NULL);
}

static char	**create_array(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_len;
	int		i;

	result = create_array(s, c);
	if (!result)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!(*s))
			continue ;
		word_len = string_len(s, c);
		result[i] = ft_substr(s, 0, word_len);
		if (!result[i])
			return ((char **)free_array(result, i));
		s += word_len;
		i++;
	}
	result[i] = NULL;
	return (result);
}
