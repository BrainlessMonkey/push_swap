/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	move_a1(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = stack_rank_a(a, c);
	if (i < stack_index(b, c))
		i = stack_index(b, c);
	return (i);
}

int	move_a2(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (stack_rank_a(a, c))
		i = lstsize(a) - stack_rank_a(a, c);
	if ((i < (lstsize(b) - stack_index(b, c))) && stack_index(b, c))
		i = lstsize(b) - stack_index(b, c);
	return (i);
}

int	move_a3(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (stack_index(b, c))
		i = lstsize(b) - stack_index(b, c);
	i = stack_rank_a(a, c) + i;
	return (i);
}

int	move_a4(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (stack_rank_a(a, c))
		i = lstsize(a) - stack_rank_a(a, c);
	i = stack_index(b, c) + i;
	return (i);
}

int	rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = move_a2(a, b, b->nbr);
	while (tmp)
	{
		if (i > move_a1(a, b, tmp->nbr))
			i = move_a1(a, b, tmp->nbr);
		if (i > move_a2(a, b, tmp->nbr))
			i = move_a2(a, b, tmp->nbr);
		if (i > move_a3(a, b, tmp->nbr))
			i = move_a3(a, b, tmp->nbr);
		if (i > move_a4(a, b, tmp->nbr))
			i = move_a4(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
