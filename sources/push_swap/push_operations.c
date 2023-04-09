/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:49:22 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/06 13:25:56 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	push(t_stack_list **stack_1, t_stack_list **stack_2)
{
	t_stack_list	*temp;

	if (!stack_2)
		return ;
	temp = *stack_1;
	*stack_1 = *stack_2;
	*stack_2 = (*stack_2)->next;
	(*stack_1)->next = temp;
}

void	push_a(t_stack_list **a, t_stack_list **b, char program)
{
	push(a, b);
	if (program == 'p')
		write(1, "pa\n", 3);
}

void	push_b(t_stack_list **a, t_stack_list **b, char program)
{
	push(b, a);
	if (program == 'p')
		write(1, "pb\n", 3);
}
