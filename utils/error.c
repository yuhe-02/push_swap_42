/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:40:06 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/13 21:39:41 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

int	is_all_digit(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-' && argv[i][j + 1] != '\0')
			{
				j++;
				continue ;
			}
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_all_unique(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_array(int argc, char *argv[])
{
	if (!is_all_digit(argc, argv))
		return (0);
	if (!is_all_unique(argc, argv))
		return (0);
	return (1);
}

static void	assign_value(char ***strs, int *wl, char **argv, int argc)
{
	*strs = argv;
	*wl = argc;
}

void	check_basicerror(int argc, char *argv[])
{
	char	**strs;
	int		words_len;
	int		flg;

	flg = 0;
	if (argc == 1)
	{
		words_len = count_words(argv[0], ' ');
		if (words_len == 0)
			put_error(1);
		strs = ft_split(argv[0], ' ');
		if (!strs)
			exit(0);
		flg = 1;
	}
	else
		assign_value(&strs, &words_len, argv, argc);
	if (!is_valid_array(words_len, strs))
		put_error(1);
	if (flg == 1)
		free_str_array(strs);
}
