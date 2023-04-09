/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 12:56:19 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/07 12:59:45 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	customized_add_back(t_stack_list **stack, t_stack_list *new_node)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new_node;
	else
		(lstlast_node(*stack))->next = new_node;
}

t_stack_list	*create_nbr_node(int value)
{
	t_stack_list	*new_node;

	new_node = malloc(sizeof(t_stack_list));
	if (!new_node)
		print_error();
	new_node->number = value;
	new_node->next = NULL;
	return (new_node);
}

t_stack_list	*process_string_input(char *argv[])
{
	t_stack_list	*stack_a;
	char			**temp;
	int				nbr;
	int				i;

	stack_a = NULL;
	i = 0;
	temp = ft_split(argv[1], ' ');
	while (temp[i])
	{
		nbr = atoi_with_checkers(temp[i]);
		customized_add_back(&stack_a, create_nbr_node(nbr));
		i++;
	}
	free_split_func(temp);
	return (stack_a);
}

t_stack_list	*check_and_process_args(int argc, char *argv[])
{
	t_stack_list	*stack_a;
	int				i;
	int				nbr;

	i = 1;
	stack_a = NULL;
	if (argc < 2)
		print_error();
	else if (argc == 2)
		stack_a = process_string_input(argv);
	else
	{
		while (i < argc)
		{
			nbr = atoi_with_checkers(argv[i]);
			customized_add_back(&stack_a, create_nbr_node(nbr));
			i++;
		}
	}
	return (stack_a);
}
