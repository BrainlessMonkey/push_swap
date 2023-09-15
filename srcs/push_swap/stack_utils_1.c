/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

int	lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst && ++i)
		lst = lst->next;
	return (i);
}

int	stack_min(t_stack *a)
{
	int		stack_min;

	stack_min = a->nbr;
	while (a)
	{
		if (stack_min > a->nbr)
			stack_min = a->nbr;
		a = a->next;
	}
	return (stack_min);
}

int	stack_max(t_stack *a)
{
	int		stack_max;

	stack_max = a->nbr;
	while (a)
	{
		if (stack_max < a->nbr)
			stack_max = a->nbr;
		a = a->next;
	}
	return (stack_max);
}