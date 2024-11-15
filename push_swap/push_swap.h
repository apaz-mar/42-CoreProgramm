/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaz-mar <apaz-mar@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:04:21 by apaz-mar          #+#    #+#             */
/*   Updated: 2024/10/19 19:02:46 by apaz-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"

typedef struct t_stack
{
	int					*data;
	struct t_stack		*next;
}						t_stack;

typedef struct t_values
{
	int		max_a;
	int		min_a;
	int		max_b;
	int		min_b;
}			t_values;

typedef struct t_op_count
{
	int		cost;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_op_count;

typedef struct t_cheap
{
	int		cost;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}			t_cheap;

typedef struct t_stacks
{
	t_stack		*head_a;
	t_stack		*head_b;
	t_values	*values; 
	t_op_count	*op_count; 
	t_cheap		*cheap;
}				t_stacks;

void		print_stacks(t_stacks *stacks);
void		count_a(int i, int len, t_stacks *stacks);
void		count_a_max(int i, int len, t_stacks *stacks);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *nptr);
long int	ft_div_mod(const char *nptr, int i, long int num);
long int	ft_atol(const char *nptr);
int			ft_isdigit(int c);
void		ft_putstr_fd(char *s, int fd);

// error checks
void		input_error(int ac, char **av);
void		check_integers(int ac, char **av);
void		check_for_doubles(t_stack *head_a);

// linked lists
void		fill_stack(int ac, char **av, t_stack **stack);
void		fill_stack_aux(int **value, char **av, int i, t_stack **new_node);
t_stack		*ft_lstnew(void *data);
void		ft_clearnodes(t_stack **lst);
int			ft_listsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);

// sort four, three and two
void		sort_four(t_stacks *stacks);
void		sort_three(t_stacks *stacks, int flag);
void		sort_three_aux(t_stacks *stacks, int num1, int num2, int num3);
void		sort_two(t_stacks *stacks);

// sort
void		sorting(t_stacks *stacks);
void		move_stack_a(t_stacks *stacks);

// moves push, swap, rotate and rev rotate
void		ft_push(t_stacks *stacks, char c);
void		ft_push_a(t_stacks *stacks);
void		ft_push_b(t_stacks *stacks);
void		ft_push_empty_b(t_stacks *stacks);
void		ft_last_push_a(t_stacks *stacks);

void		ft_swap(t_stacks *stacks, char c);
void		ft_swap_a(t_stack *head_a, int print);
void		ft_swap_b(t_stack *head_b, int print);

void		ft_rotate(t_stacks *stacks, char c);
void		ft_rotate_a(t_stacks *stacks, t_stack *head_a, int print);
void		ft_rotate_b(t_stacks *stacks, t_stack *head_b, int print);

void		ft_rev_rotate(t_stacks *stacks, char c);
void		ft_rev_rotate_a(t_stacks *stacks, int print);
void		ft_rev_rotate_b(t_stacks *stacks, int print);

// move cheapest
void		move_cheapest(t_stacks *stacks);
void		check_ops(t_stacks *stacks);
void		do_cheap_ops(t_stacks *stacks);

// find cheapest
void		new_max_or_min_stack_b(t_stacks *stacks);
int			find_index_stack_b(t_stacks *stacks, int nbr);
void		get_top_stack_a(t_stacks *stacks, t_stack *head_a, int i);
void		new_num_in_stack_b(t_stacks *stacks, int num);
int			search_num_stack_b(t_stacks *stacks, int nbr);
void		check_double_moves(t_stacks *stacks);
void		check_cost(t_stacks *stacks, int i);

// move back to stack A
void		move_stack_a(t_stacks *stacks);
void		check_max_min_a(t_stacks *stacks);
void		check_max_a(t_stacks *stacks, t_stack *head_a);
void		check_min_a(t_stacks *stacks, t_stack *head_a);
int			find_index_stack_a(t_stacks *stacks, int nbr);
int			search_stack_a(t_stacks *stacks, int nbr);
void		put_in_order(t_stacks *stacks);
void		new_min_stack_a(t_stacks *stacks);
void		new_max_stack_a(t_stacks *stacks);
void		new_num_stack_a(t_stacks *stacks, t_stack *head_b);
void		do_moves_min_stack_a(t_stacks *stacks);
void		do_moves_max_stack_a(t_stacks *stacks);
void		do_moves_num_stack_a(t_stacks *stacks);
void		do_moves_order(t_stacks *stacks);

// check Max & Min in B
void		check_max_min_b(t_stacks *stacks);
void		check_max_b(t_stacks *stacks, t_stack *head_b);
void		check_min_b(t_stacks *stacks, t_stack *head_b);

// Print
void		print_error_and_exit(void) __attribute__((noreturn));

// List Checks
int			check_list_order(t_stacks *stacks);

// Free all
void		free_for_all(t_stacks *stacks);

#endif /* PUSH_SWAP_H*/
