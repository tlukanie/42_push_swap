/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_error_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:45:58 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/05 18:50:20 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	print_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

t_stack_list	*lstlast_node(t_stack_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	list_size(t_stack_list *list)
{
	size_t	size;

	size = 0;
	while (list)
	{
		list = list->next;
		size++;
	}
	return (size);
}

int	min_number_in_stack(t_stack_list *stack)
{
	int	min_nbr;

	min_nbr = stack->number;
	while (stack)
	{
		if (min_nbr > stack->number)
			min_nbr = stack->number;
		stack = stack->next;
	}
	return (min_nbr);
}

int	max_number_in_stack(t_stack_list *stack)
{
	int	max_nbr;

	max_nbr = stack->number;
	while (stack)
	{
		if (max_nbr < stack->number)
			max_nbr = stack->number;
		stack = stack->next;
	}
	return (max_nbr);
}
