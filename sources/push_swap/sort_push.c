/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:35:34 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/05 19:54:25 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	rarb_push(t_stack_list **a, t_stack_list **b, int pushed_number, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->number != pushed_number
			&& search_index_in_b(*b, pushed_number) > 0)
			rotate_both(a, b, 'p');
		while ((*a)->number != pushed_number)
			rotate_a(a, 'p');
		while (search_index_in_b(*b, pushed_number) > 0)
			rotate_b(b, 'p');
		push_b(a, b, 'p');
	}
	else
	{
		while ((*b)->number != pushed_number
			&& search_index_in_a(*a, pushed_number) > 0)
			rotate_both(a, b, 'p');
		while ((*b)->number != pushed_number)
			rotate_b(b, 'p');
		while (search_index_in_a(*a, pushed_number) > 0)
			rotate_a(a, 'p');
		push_a(a, b, 'p');
	}
	return (-1);
}

int	rrarrb_push(t_stack_list **a, t_stack_list **b,
				int pushed_number, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->number != pushed_number
			&& search_index_in_b(*b, pushed_number) > 0)
			rev_rot_both(a, b, 'p');
		while ((*a)->number != pushed_number)
			rev_rot_a(a, 'p');
		while (search_index_in_b(*b, pushed_number) > 0)
			rev_rot_b(b, 'p');
		push_b(a, b, 'p');
	}
	else
	{
		while ((*b)->number != pushed_number
			&& search_index_in_a(*a, pushed_number) > 0)
			rev_rot_both(a, b, 'p');
		while ((*b)->number != pushed_number)
			rev_rot_b(b, 'p');
		while (search_index_in_a(*a, pushed_number) > 0)
			rev_rot_a(a, 'p');
		push_a(a, b, 'p');
	}
	return (-1);
}

int	rrarb_push(t_stack_list **a, t_stack_list **b,
			int pushed_number, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->number != pushed_number)
			rev_rot_a(a, 'p');
		while (search_index_in_b(*b, pushed_number) > 0)
			rotate_b(b, 'p');
		push_b(a, b, 'p');
	}
	else
	{
		while (search_index_in_a(*a, pushed_number) > 0)
			rev_rot_a(a, 'p');
		while ((*b)->number != pushed_number)
			rotate_b(b, 'p');
		push_a(a, b, 'p');
	}
	return (-1);
}

int	rarrb_push(t_stack_list **a, t_stack_list **b,
			int pushed_number, char stack)
{
	if (stack == 'a')
	{
		while ((*a)->number != pushed_number)
			rotate_a(a, 'p');
		while (search_index_in_b(*b, pushed_number) > 0)
			rev_rot_b(b, 'p');
		push_b(a, b, 'p');
	}
	else
	{
		while (search_index_in_a(*a, pushed_number) > 0)
			rotate_a(a, 'p');
		while ((*b)->number != pushed_number)
			rev_rot_b(b, 'p');
		push_a(a, b, 'p');
	}
	return (-1);
}
