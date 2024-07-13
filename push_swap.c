/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:49:04 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/13 21:33:31 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

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

void	execute_adjusting_size(t_cross **stack_a, t_cross **stack_b, int argc)
{
	if (is_already_sorted(stack_a))
		return ;
	else if (argc == 2)
		ft_swap(stack_a, 0);
	else if (argc == 3)
		pattern_three(stack_a, 0);
	else if (argc == 4)
		pattern_four(stack_a, stack_b, 0);
	else if (argc == 5)
		pattern_five(stack_a, stack_b, 0);
	else
		precure_sort(stack_a, stack_b, argc);
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
	execute_adjusting_size(&stack_a, &stack_b, argc);
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
