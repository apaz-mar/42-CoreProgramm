/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:04:21 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/06/09 16:12:02 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include <string.h>
# include <strings.h>
# include <limits.h>
# include <ctype.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>

typedef struct s_list
{
    int             *data;
    struct s_list   *next;
}                   t_list;
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))



int is_sorted_asc(t_list *stack);
int is_sorted_desc(t_list *stack);
//int		ft_atoi(const char *nptr);
//char	*ft_itoa(int n);
//char	*ft_itoa_base(unsigned long long n, int size_base, 
//			const char *base, const char *p);
int		ft_pr_char(va_list args);
//int		ft_pr_hexa(va_list args, const char *p);
//int		ft_pr_number(va_list args, const char *p);
//int		ft_pr_pointer(va_list args, const char *p);
//int		ft_pr_string(va_list args);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);

void fill_stack(int ac, char **av, t_list **stack);
void print_stack(t_list *stack);
void    minimum_up(t_list **stack_a, int pos_min, int len_a, int *op_count);
int find_maximum(t_list **stack_a);
int find_minimum(t_list **stack_a);
int	ft_lstsize(t_list *lst);
void ft_push(t_list **src, t_list **dest);
void ft_rev_rotate(t_list **stack);
void swap(t_list **stack);
void ft_rotate(t_list **stack);
int    fill_chunk(t_list **stack_a, t_list **stack_b, int chunk_start, int chunk_end, int *op_count);



#endif /* PUSH_SWAP_H*/
