/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_number_in_stack.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:41:09 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/05 18:36:57 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	search_nbr_index(t_stack_list *stack, int num)
{
	int	index;

	index = 0;
	while (stack->number != num)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

int	search_index_in_b(t_stack_list *b, int pushed_number)
{
	int				index;
	t_stack_list	*temp;

	index = 1;
	if (b->number < pushed_number && lstlast_node(b)->number > pushed_number)
		index = 0;
	else if (max_number_in_stack(b) < pushed_number
		|| min_number_in_stack(b) > pushed_number)
		index = search_nbr_index(b, max_number_in_stack(b));
	else
	{
		temp = b->next;
		while (b->number < pushed_number || temp->number > pushed_number)
		{
			b = b->next;
			temp = b->next;
			index++;
		}
	}
	return (index);
}

int	search_index_in_a(t_stack_list *a, int pushed_number)
{
	int				index;
	t_stack_list	*temp;

	index = 1;
	if (a->number > pushed_number && lstlast_node(a)->number < pushed_number)
		index = 0;
	else if (max_number_in_stack(a) < pushed_number
		|| min_number_in_stack(a) > pushed_number)
		index = search_nbr_index(a, min_number_in_stack(a));
	else
	{
		temp = a->next;
		while (a->number > pushed_number || temp->number < pushed_number)
		{
			a = a->next;
			temp = a->next;
			index++;
		}
	}
	return (index);
}
