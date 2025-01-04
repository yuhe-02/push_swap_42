/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:44:34 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/18 22:42:54 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	put_error(int flag)
{
	if (flag == 42)
		return ;
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_valid_numbers(int argc, int *array, char **strs)
{
	int		i;
	char	*str;

	i = 0;
	while (i < argc)
	{
		str = ft_itoa(array[i]);
		if (!str)
			exit(0);
		if (ft_strcmp(str, strs[i]) != 0)
			put_error(1);
		free(str);
		i++;
	}
	return (1);
}
