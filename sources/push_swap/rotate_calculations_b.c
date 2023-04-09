/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_calculations_b.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:37:55 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/05 19:12:19 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	b_rotation_combination(t_stack_list *a, t_stack_list *b)
{
	int				index;
	t_stack_list	*temp;

	temp = a;
	index = if_rrarrb_b(a, b, a->number);
	while (temp)
	{
		if (index > if_rarb_b(a, b, temp->number))
			index = if_rarb_b(a, b, temp->number);
		if (index > if_rrarrb_b(a, b, temp->number))
			index = if_rrarrb_b(a, b, temp->number);
		if (index > if_rarrb_b(a, b, temp->number))
			index = if_rarrb_b(a, b, temp->number);
		if (index > if_rrarb_b(a, b, temp->number))
			index = if_rrarb_b(a, b, temp->number);
		temp = temp->next;
	}
	return (index);
}

int	if_rarb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = search_index_in_b(b, pushed_nbr);
	if (index < search_nbr_index(a, pushed_nbr))
		index = search_nbr_index(a, pushed_nbr);
	return (index);
}

int	if_rrarrb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = 0;
	if (search_index_in_b(b, pushed_nbr))
		index = list_size(b) - search_index_in_b(b, pushed_nbr);
	if ((index < (list_size(a) - search_nbr_index(a, pushed_nbr)))
		&& search_nbr_index(a, pushed_nbr))
		index = list_size(a) - search_nbr_index(a, pushed_nbr);
	return (index);
}

int	if_rarrb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = 0;
	if (search_index_in_b(b, pushed_nbr))
		index = list_size(b) - search_index_in_b(b, pushed_nbr);
	index = search_nbr_index(a, pushed_nbr) + index;
	return (index);
}

int	if_rrarb_b(t_stack_list *a, t_stack_list *b, int pushed_nbr)
{
	int	index;

	index = 0;
	if (search_nbr_index(a, pushed_nbr))
		index = list_size(a) - search_nbr_index(a, pushed_nbr);
	index = search_index_in_b(b, pushed_nbr) + index;
	return (index);
}
