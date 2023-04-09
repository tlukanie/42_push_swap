/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_calculations_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:37:50 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/05 19:05:44 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	a_rotation_combination(t_stack_list *a, t_stack_list *b)
{
	int				index;
	t_stack_list	*temp;

	temp = b;
	index = if_rrarrb_a(a, b, b->number);
	while (temp)
	{
		if (index > if_rarb_a(a, b, temp->number))
			index = if_rarb_a(a, b, temp->number);
		if (index > if_rrarrb_a(a, b, temp->number))
			index = if_rrarrb_a(a, b, temp->number);
		if (index > if_rarrb_a(a, b, temp->number))
			index = if_rarrb_a(a, b, temp->number);
		if (index > if_rrarb_a(a, b, temp->number))
			index = if_rrarb_a(a, b, temp->number);
		temp = temp->next;
	}
	return (index);
}

int	if_rarb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = search_index_in_a(a, pushed_nbr);
	if (index < search_nbr_index(b, pushed_nbr))
		index = search_nbr_index(b, pushed_nbr);
	return (index);
}

int	if_rrarrb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = 0;
	if (search_index_in_a(a, pushed_nbr))
		index = list_size(a) - search_index_in_a(a, pushed_nbr);
	if ((index < (list_size(b) - search_nbr_index(b, pushed_nbr)))
		&& search_nbr_index(b, pushed_nbr))
		index = list_size(b) - search_nbr_index(b, pushed_nbr);
	return (index);
}

int	if_rarrb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = 0;
	if (search_nbr_index(b, pushed_nbr))
		index = list_size(b) - search_nbr_index(b, pushed_nbr);
	index = search_index_in_a(a, pushed_nbr) + index;
	return (index);
}

int	if_rrarb_a(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = 0;
	if (search_index_in_a(a, pushed_nbr))
		index = list_size(a) - search_index_in_a(a, pushed_nbr);
	index = search_nbr_index(b, pushed_nbr) + index;
	return (index);
}
