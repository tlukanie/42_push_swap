/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:05:43 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/06 13:33:16 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	rotate(t_stack_list **stack)
{
	t_stack_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = lstlast_node(*stack);
	(*stack)->next = temp;
	*stack = temp->next;
	temp->next = NULL;
}

void	rotate_a(t_stack_list **stack_a, char program)
{
	rotate(stack_a);
	if (program == 'p')
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack_list **stack_b, char program)
{
	rotate(stack_b);
	if (program == 'p')
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack_list **stack_a, t_stack_list **stack_b,
			char program)
{
	rotate(stack_a);
	rotate(stack_b);
	if (program == 'p')
		write(1, "rr\n", 3);
}
