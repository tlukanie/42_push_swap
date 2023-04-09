/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:21:57 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/06 13:36:25 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	sort_3_nbr(t_stack_list **a)
{
	if (min_number_in_stack(*a) == (*a)->number)
	{
		rev_rot_a(a, 'p');
		swap_a(a, 'p');
	}
	else if (max_number_in_stack(*a) == (*a)->number)
	{
		rotate_a(a, 'p');
		if (!is_sorted(*a))
			swap_a(a, 'p');
	}
	else
	{
		if (search_nbr_index(*a, max_number_in_stack(*a)) == 1)
			rev_rot_a(a, 'p');
		else
			swap_a(a, 'p');
	}
}

void	sort_push_b_more_than_3(t_stack_list **a, t_stack_list **b)
{
	int				index;
	t_stack_list	*temp;

	while (list_size(*a) > 3 && !is_sorted(*a))
	{
		temp = *a;
		index = b_rotation_combination(*a, *b);
		while (index >= 0)
		{
			if (index == if_rarb_b(*a, *b, temp->number))
				index = rarb_push(a, b, temp->number, 'a');
			else if (index == if_rrarrb_b(*a, *b, temp->number))
				index = rrarrb_push(a, b, temp->number, 'a');
			else if (index == if_rarrb_b(*a, *b, temp->number))
				index = rarrb_push(a, b, temp->number, 'a');
			else if (index == if_rrarb_b(*a, *b, temp->number))
				index = rrarb_push(a, b, temp->number, 'a');
			else
				temp = temp->next;
		}
	}
}

t_stack_list	*sort_stack_b(t_stack_list **a)
{
	t_stack_list	*b;

	b = NULL;
	if (list_size(*a) > 3 && !is_sorted(*a))
		push_b(a, &b, 'p');
	if (list_size(*a) > 3 && !is_sorted(*a))
		push_b(a, &b, 'p');
	if (list_size(*a) > 3 && !is_sorted(*a))
		sort_push_b_more_than_3(a, &b);
	if (!is_sorted(*a))
		sort_3_nbr(a);
	return (b);
}

t_stack_list	**sort_stack_a(t_stack_list **a, t_stack_list **b)
{
	int				index;
	t_stack_list	*temp;

	while (*b)
	{
		temp = *b;
		index = a_rotation_combination(*a, *b);
		while (index >= 0)
		{
			if (index == if_rarb_a(*a, *b, temp->number))
				index = rarb_push(a, b, temp->number, 'b');
			else if (index == if_rarrb_a(*a, *b, temp->number))
				index = rarrb_push(a, b, temp->number, 'b');
			else if (index == if_rrarrb_a(*a, *b, temp->number))
				index = rrarrb_push(a, b, temp->number, 'b');
			else if (index == if_rrarb_a(*a, *b, temp->number))
				index = rrarb_push(a, b, temp->number, 'b');
			else
				temp = temp->next;
		}
	}
	return (a);
}

void	sort_numbers(t_stack_list **a)
{
	int				i;
	t_stack_list	*b;

	b = NULL;
	if (list_size(*a) == 2)
		swap_a(a, 'p');
	else
	{
		b = sort_stack_b(a);
		a = sort_stack_a(a, &b);
		i = search_nbr_index(*a, min_number_in_stack(*a));
		if (i < list_size(*a) - i)
		{
			while ((*a)->number != min_number_in_stack(*a))
				rotate_a(a, 'p');
		}
		else
		{
			while ((*a)->number != min_number_in_stack(*a))
				rev_rot_a(a, 'p');
		}
	}
}
