/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:49:04 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/25 23:33:20 by yyamasak         ###   ########.fr       */
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
    output_array(argc, array);
    output_cross(stack_a);
    assign_order(stack_a, argc, array);
    output_cross(stack_a);
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
