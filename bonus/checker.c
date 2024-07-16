/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:32:49 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/16 23:44:53 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include "../includes/push_swap.h"
#include "../includes/libft.h"

void	start_with_array(int argc, char **argv)
{
	execute(argc, argv, 0);
}

void	start_with_split(char *nums)
{
	char	**strs;
	int		words_len;

	strs = ft_split(nums, ' ');
	words_len = count_words(nums, ' ');
	if (!strs)
		exit(0);
	execute(words_len, strs, 1);
}

void	check_request(t_cross **stack_a, t_cross **stack_b, int argc)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(line, "sa"))
			ft_swap(stack_a, 2);
		else if (ft_strcmp(line, "sb"))
			ft_swap(stack_b, 2);
		else if (ft_strcmp(line, "ss"))
			ft_swap_sametime(stack_a,stack_b, 2);
		else if (ft_strcmp(line, "pa"))
			ft_push(stack_a, stack_b, 2);
		else if (ft_strcmp(line, "pb"))
			ft_push(stack_b, stack_a, 2);
		else if (ft_strcmp(line, "ra"))
			ft_rotate(stack_a, 2);
		else if (ft_strcmp(line, "rb"))
			ft_rotate(stack_b, 2);
		else if (ft_strcmp(line, "rr"))
			ft_rotate_sametime(stack_a, stack_b, 2);
		else if (ft_strcmp(line, "rra"))
			ft_reverse_rotate(stack_a, 2);
		else if (ft_strcmp(line, "rrb"))
			ft_reverse_rotate(stack_b, 2);
		else if (ft_strcmp(line, "rrr"))
			ft_reverse_rotate_sametime(stack_a, stack_b, 2);
		else
			break ;
		free(line);
		line = get_next_line(0);
	}
	if (!line)
		return ;
	free(line);
}

void	execute(int argc, char **strs, int flg)
{
	int		*array;
	t_cross	*stack_a;
	t_cross	*stack_b;

	array = get_array(argc, strs);
	if (!is_valid_numbers(argc, array, strs))
		put_error(1);
	create_cross(&stack_a, argc, array, &stack_b);
	sort_array(argc, array);
	assign_order(stack_a, argc, array);
	free(array);
	if (flg == 1)
		free_str_array(strs);
	check_request(&stack_a, &stack_b, argc);
	if (!(is_already_sorted(&stack_a) && ft_lstsize(&stack_b) == 0))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_nodes(&stack_a, &stack_b);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

int	main(int argc, char *argv[])
{
	int	*stack;

	if (argc <= 1)
		return (0);
	check_basicerror(argc - 1, argv + 1);
	if (argc == 2)
		start_with_split(argv[1]);
	else
		start_with_array(argc - 1, argv + 1);
	exit (0);
}