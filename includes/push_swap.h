/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:49:09 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/25 23:33:14 by yyamasak         ###   ########.fr       */
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
void check_basicerror(int argc, char* argv[]);
int	is_valid_numbers(int argc, int *array, char **strs);
void put_error();
int *get_array(int argc, char **strs);
void start_with_array(int argc, char **argv);
void start_with_split(char *nums);
void execute(int argc, char **strs);
void	create_cross(t_cross **stack, int argc, int *array, t_cross **stack_b);
void output_array(int argc, int *array);
void	output_cross(t_cross *stack);
void sort_array(int argc, int *array);
void assign_order(t_cross *stack, int argc, int *array);
#endif