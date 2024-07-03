/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:49:09 by yyamasak          #+#    #+#             */
/*   Updated: 2024/07/03 23:35:59 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_cross
{
	struct s_cross	*next;
	struct s_cross	*prev;
	int				rank;
	int				value;
}					t_cross;

// void start_with_split(char **argv);
// void start_with_array(int argc, char **argv, int *stack);
// t_cross	*ft_lstnew(int order, int rank, int value);
// size_t ft_strlen(const char *s);
void	check_basicerror(int argc, char* argv[]);
int		is_valid_numbers(int argc, int *array, char **strs);
void	put_error();
int		*get_array(int argc, char **strs);
void	start_with_array(int argc, char **argv);
void	start_with_split(char *nums);
void	execute(int argc, char **strs);
void	create_cross(t_cross **stack, int argc, int *array, t_cross **stack_b);
void	output_array(int argc, int *array);
void	output_cross(t_cross *stack);
void	sort_array(int argc, int *array);
void	assign_order(t_cross *stack, int argc, int *array);
void	ft_push(t_cross **target, t_cross **src, int flag);
void	ft_swap(t_cross **target, int flag);
void	ft_rotate(t_cross **stack, int flag);
void	ft_reverse_rotate(t_cross **stack, int flag);
void	pattern_three(t_cross **stack, int flag);
void	output_visible(t_cross *stack1, t_cross *stack2);
int		is_already_sorted(t_cross **stack);
void	ft_rotate_sametime(t_cross **stack_a, t_cross **stack_b);
void	ft_reverse_rotate_sametime(t_cross **stack_a, t_cross **stack_b);
void	ft_swap_sametime(t_cross **stack_a, t_cross **stack_b);
int		look_for_minpos(t_cross **stack1);
void	pattern_four(t_cross **stack1, t_cross **stack2, int flag);
void	pattern_five(t_cross **stack1, t_cross **stack2, int flag);
int	search_under_limit(t_cross **stack1, int limit);
int	rv_search_under_limit(t_cross **stack1, int limit);
void	precure_sort(t_cross **stack_a, t_cross **stack_b, int argc);
int search_value(t_cross **stack, int value);

int	search_under_limit2(t_cross **stack1, int limit, int *value);
int	rv_search_under_limit2(t_cross **stack1, int limit, int *value);
int get_max(t_cross **stack);
#endif