/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:51:01 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/06 13:24:22 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	swap(t_stack_list **stack)
{
	t_stack_list	*temp;

	if (!*stack || !((*stack)->next))
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	swap_a(t_stack_list **stack_a, char program)
{
	swap(stack_a);
	if (program == 'p')
		write(1, "sa\n", 3);
}

void	swap_b(t_stack_list **stack_b, char program)
{
	swap(stack_b);
	if (program == 'p')
		write(1, "sb\n", 3);
}

void	swap_both(t_stack_list **stack_a, t_stack_list **stack_b, char program)
{
	swap(stack_a);
	swap(stack_b);
	if (program == 'p')
		write(1, "ss\n", 3);
}
