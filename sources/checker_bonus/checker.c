/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukanie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:53:11 by tlukanie          #+#    #+#             */
/*   Updated: 2023/04/09 17:06:45 by tlukanie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	checker_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	rev_rot_check(t_stack_list **a, t_stack_list **b, char *line)
{
	if (line[2] == 'a')
		rev_rot_a(a, 'c');
	else if (line[2] == 'b')
		rev_rot_b(b, 'c');
	else if (line[2] == 'r')
		rev_rot_both(a, b, 'c');
}

char	*check_valid_command(t_stack_list **a, t_stack_list **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_a(a, 'c');
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_b(b, 'c');
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_a(a, b, 'c');
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_b(a, b, 'c');
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_a(a, 'c');
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_b(b, 'c');
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		rev_rot_check(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rotate_both(a, b, 'c');
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		swap_both(a, b, 'c');
	else
		checker_error();
	return (get_next_line(0));
}

void	ft_checker(t_stack_list **a, t_stack_list **b, char *line)
{
	char	*temp;

	while (line && *line != '\n')
	{
		temp = line;
		line = check_valid_command(a, b, line);
		free(temp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	main(int argc, char *argv[])
{	
	char			*line;
	t_stack_list	*stack_a;
	t_stack_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = check_and_process_args(argc, argv);
	if (!stack_a || check_duplicates(stack_a))
	{
		free_list(&stack_a);
		checker_error();
	}
	line = get_next_line(0);
	if (!line && !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		ft_checker(&stack_a, &stack_b, line);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
