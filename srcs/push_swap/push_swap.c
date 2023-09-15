/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	ft_atoi2(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			error();
		i = i * 10 + (*str - '0');
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		error();
	return (mod * i);
}

t_stack	*process(int argc, char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;

	i = 1;
	a = NULL;
	if (argc < 2)
		error();
	if (argc == 2 && !(--i))
	{
		tmp = ft_split(argv[1], ' ');
		while (tmp[i])
			add_back(&a, stack_new(ft_atoi2(tmp[i++])));
		freestr(tmp);
		free(tmp);
	}
	else
		while (i < argc)
			add_back(&a, stack_new(ft_atoi2(argv[i++])));
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = process(argc, argv);
	if (!stack_a || checkdup(stack_a))
	{
		ft_free(&stack_a);
		error();
	}
	if (!sorted(stack_a))
		sort(&stack_a);
	ft_free(&stack_a);
}
