#include "../includes/push_swap.h"
#include "../includes/libft.h"

void put_error()
{
    write(1, "Error\n", 6);
    exit(EXIT_FAILURE);
}

int	is_all_digit(int argc, char* argv[])
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
			if (j == 0 && argv[i][j] == '-' && argv[i][j+1] != '\0')
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

int	is_all_unique(int argc, char* argv[])
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

int is_valid_array(int argc, char* argv[])
{
	if (!is_all_digit(argc, argv))
		return (0);
	if (!is_all_unique(argc, argv))
		return (0);
	return (1);
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
		{
			free(str);
			return (0);
		}
		free(str);
		i++;
	}
	return (1);
}


void check_basicerror(int argc, char* argv[])
{
	char **strs;
	int	 words_len;

	if (argc <= 0)
		put_error();
	if (argc == 1)
	{
		words_len = count_words(argv[0], ' ');
		if (words_len <= 1)
			put_error();
		strs = ft_split(argv[0], ' ');
		if (!strs)
			exit(0);
	}
	else
	{
		strs = argv;
		words_len = argc;
	}
	if (!is_valid_array(words_len, strs))
		put_error();
}