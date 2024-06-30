/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:51:29 by yyamasak          #+#    #+#             */
/*   Updated: 2024/06/29 00:08:34 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "push_swap.h"

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dest, char const *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	count_words(char const *tmp, char c);
int ft_isdigit(char c);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_simpleatoi(const char *str);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_cross **lst, t_cross *new);
void	ft_lstadd_front(t_cross **lst, t_cross *new);
t_cross	*ft_lstnew(int value, int rank);
t_cross	*ft_lstpop(t_cross **lst);
size_t	ft_lstsize(t_cross **stack);
t_cross	*ft_lstpoplast(t_cross **lst);
// char	*ft_strrchr(const char *s, int c);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// char	*ft_strjoin3(char *s1, char *s2, char *s3);
// char	*ft_strcpy(char *dest, const char *src);
// char	*ft_strcat(char *dest, const char *src);
// char	*ft_strdup(const char *s);
// char	*ft_head(char *str, char c);
// void	ft_putstr(char const *s);
// void	ft_putchar(char c);
#endif