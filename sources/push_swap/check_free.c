/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:00:01 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/05 18:25:17 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

int	check_duplicates(t_stack_list *stack_a)
{
	t_stack_list	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		while (temp)
		{
			if (stack_a->number == temp->number)
				return (1);
			temp = temp->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	is_sorted(t_stack_list *stack_a)
{
	int	current_num;

	current_num = stack_a->number;
	while (stack_a)
	{
		if (current_num > stack_a->number)
			return (0);
		current_num = stack_a->number;
		stack_a = stack_a->next;
	}
	return (1);
}

int	atoi_with_checkers(const char *string)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	while (*string == ' ' || *string == '\t' || *string == '\n'
		|| *string == '\f' || *string == '\v' || *string == '\r')
		string++;
	if (*string == '-')
	{
		sign = -1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (*string)
	{
		if (!ft_isdigit(*string))
			print_error();
		result = result * 10 + (*string - 48);
		string++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		print_error();
	return (result * sign);
}

void	free_split_func(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	free_list(t_stack_list **stack_a)
{
	t_stack_list	*temp;

	if (!stack_a)
		return ;
	while (*stack_a)
	{
		temp = (*stack_a)->next;
		(*stack_a)->number = 0;
		free(*stack_a);
		*stack_a = temp;
	}
}
