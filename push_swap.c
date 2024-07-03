/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:49:04 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/01 22:58:31 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/libft.h"

void start_with_array(int argc, char **argv)
{
    execute(argc, argv);
}

void start_with_split(char *nums)
{
    char    **strs;
    int     words_len;

    strs = ft_split(nums, ' ');
    words_len = count_words(nums, ' ');
    if (!strs)
        exit(0);
    execute(words_len, strs);
}

void    execute_adjusting_size(t_cross **stack_a, t_cross **stack_b, int argc)
{
    if (is_already_sorted(stack_a))
        return ;
    if (argc == 3)
        pattern_three(stack_a, 0);
    if (argc == 4)
        pattern_four(stack_a, stack_b, 0);
    if (argc == 5)
        pattern_five(stack_a, stack_b, 0);
    else
        precure_sort(stack_a, stack_b, argc);
}

void execute(int argc, char **strs)
{
    int *array;
    t_cross *stack_a;
    t_cross *stack_b;

    array = get_array(argc, strs);
    if (!is_valid_numbers(argc, array, strs))
        put_error();
    create_cross(&stack_a, argc, array, &stack_b);
    sort_array(argc, array);
    assign_order(stack_a, argc, array);
    // output_visible(stack_a, stack_b);
    execute_adjusting_size(&stack_a, &stack_b, argc);
    // output_visible(stack_a, stack_b);
}

// __attribute__((destructor))
// static void destructor() {
//     char command[256];
//     snprintf(command, sizeof(command), "leaks %d", getpid());
//     system(command);
// }

int main(int argc, char *argv[])
{
    int *stack;

    if (argc <= 1)
        return (0);
    check_basicerror(argc - 1, argv + 1);
    if (argc == 2)
        start_with_split(argv[1]);
    else
        start_with_array(argc - 1, argv + 1);
    exit (0);
}
