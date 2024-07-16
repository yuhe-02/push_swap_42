/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:49:16 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/16 23:18:32 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap_bonus.h"

char	*finish_process(char **s1, char **s2, char **s3)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3)
	{
		free(*s3);
		*s3 = NULL;
	}
	return (NULL);
}

static char	*assignment(int fd, char *buf, char *dest)
{
	ssize_t	byte_num;

	byte_num = BUFFER_SIZE;
	while (byte_num > 0)
	{
		byte_num = read(fd, buf, BUFFER_SIZE);
		if (byte_num == -1)
			return (finish_process(&buf, &dest, NULL));
		buf[byte_num] = '\0';
		dest = ft_strjoin_custom(dest, buf);
		if (!dest)
			return (finish_process(&buf, NULL, NULL));
		if (!(ft_strchr(dest, '\n') == NULL))
			break ;
	}
	free(buf);
	return (dest);
}

static char	*get_line(char **temp)
{
	char	*line;
	char	*ptr;
	size_t	i;

	ptr = *temp;
	i = 0;
	while (ptr[i] && ptr[i] != '\n')
		i++;
	if (ptr[i] == '\n')
		i++;
	line = ft_strndup (*temp, i);
	if (!line)
		return (finish_process(temp, NULL, NULL));
	ptr = ft_strndup (&ptr[i], ft_strlen (&ptr[i]));
	free (*temp);
	*temp = ptr;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*hmread;
	char			*buf;
	char			*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!hmread)
		hmread = ft_strdup("");
	if (!hmread)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (finish_process(&hmread, NULL, NULL));
	hmread = assignment(fd, buf, hmread);
	if (!hmread)
		return (NULL);
	if (!*hmread)
	{
		free(hmread);
		hmread = NULL;
		return (NULL);
	}
	line = get_line(&hmread);
	return (line);
}