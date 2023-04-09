/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:42:35 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/06 13:46:37 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack_list
{
	long					number;
	struct s_stack_list		*next;
}	t_stack_list;

void			customized_add_back(t_stack_list **stack,
					t_stack_list *new_node);
t_stack_list	*create_nbr_node(int value);
t_stack_list	*process_string_input(char *argv[]);
t_stack_list	*check_and_process_args(int argc, char *argv[]);
int				check_duplicates(t_stack_list *stack_a);
int				is_sorted(t_stack_list *stack_a);
int				atoi_with_checkers(const char *string);
void			free_split_func(char **split);
void			free_list(t_stack_list **stack_a);
void			print_error(void);
t_stack_list	*lstlast_node(t_stack_list *list);
int				list_size(t_stack_list *list);
int				min_number_in_stack(t_stack_list *stack);
int				max_number_in_stack(t_stack_list *stack);
int				search_nbr_index(t_stack_list *stack, int num);
int				search_index_in_b(t_stack_list *b, int pushed_number);
int				search_index_in_a(t_stack_list *a, int pushed_number);
void			swap_a(t_stack_list **stack_a, char program);
void			swap_b(t_stack_list **stack_b, char program);
void			swap_both(t_stack_list **stack_a, t_stack_list **stack_b,
					char program);
void			rotate_a(t_stack_list **stack_a, char program);
void			rotate_b(t_stack_list **stack_b, char program);
void			rotate_both(t_stack_list **stack_a, t_stack_list **stack_b,
					char program);
void			push_a(t_stack_list **a, t_stack_list **b, char program);
void			push_b(t_stack_list **a, t_stack_list **b, char program);
void			rev_rot_a(t_stack_list **a, char program);
void			rev_rot_b(t_stack_list **b, char program);
void			rev_rot_both(t_stack_list **a, t_stack_list **b, char program);
void			sort_numbers(t_stack_list **a);
void			sort_3_nbr(t_stack_list **a);
t_stack_list	*sort_stack_b(t_stack_list **a);
void			sort_push_b_more_than_3(t_stack_list **a, t_stack_list **b);
t_stack_list	**sort_stack_a(t_stack_list **a, t_stack_list **b);
int				if_rarb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				if_rrarrb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				if_rarrb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				if_rrarb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				if_rarb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				if_rrarrb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				if_rarrb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				if_rrarb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr);
int				a_rotation_combination(t_stack_list *a, t_stack_list *b);
int				b_rotation_combination(t_stack_list *a, t_stack_list *b);
int				rarb_push(t_stack_list **a, t_stack_list **b,
					int pushed_number, char stack);
int				rrarrb_push(t_stack_list **a, t_stack_list **b,
					int pushed_number, char stack);
int				rrarb_push(t_stack_list **a, t_stack_list **b,
					int pushed_number, char stack);
int				rarrb_push(t_stack_list **a, t_stack_list **b,
					int pushed_number, char stack);
//checker
void			checker_error(void);
void			rev_rot_check(t_stack_list **a, t_stack_list **b, char *line);
char			*check_valid_command(t_stack_list **a, t_stack_list **b,
					char *line);
void			ft_checker(t_stack_list **a, t_stack_list **b, char *line);

#endif
