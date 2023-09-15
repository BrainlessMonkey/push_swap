/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	list_args(char **argv, t_stack **stack_a)
{
	while (*argv)
		add_back(stack_a, stack_new(ft_atoi(*argv++)));
}

t_stack	*line_parsing(char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	list_args(ft_split(argv[1], ' '), &stack_a);
	return (stack_a);
}

t_stack	*parsing(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		error();
	else if (argc == 2)
		stack_a = line_parsing(argv);
	else
		list_args(argv, &stack_a);
	return (stack_a);
}
