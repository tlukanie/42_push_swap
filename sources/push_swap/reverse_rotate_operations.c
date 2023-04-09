/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:16:51 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/06 13:31:45 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	reverse_rotate(t_stack_list **stack)
{
	t_stack_list	*temp;
	int				i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	temp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = temp;
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
}

void	rev_rot_a(t_stack_list **a, char program)
{
	reverse_rotate(a);
	if (program == 'p')
		write(1, "rra\n", 4);
}

void	rev_rot_b(t_stack_list **b, char program)
{
	reverse_rotate(b);
	if (program == 'p')
		write(1, "rrb\n", 4);
}

void	rev_rot_both(t_stack_list **a, t_stack_list **b, char program)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (program == 'p')
		write(1, "rrr\n", 4);
}
