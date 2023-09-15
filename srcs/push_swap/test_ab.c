/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// This function calculates how many times 
// we should rotate the stacks together.
// Because after a certain amoun of rotate, we will
// proceed only with one stack rotation.
int	move_b1(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = stack_rank_b(b, c);
	if (i < stack_index(a, c))
		i = stack_index(a, c);
	return (i);
}

// This function calculates how many times we should rotate the stacks together.
// Because after a certain amoun of rotate, we will proceed only with one stack
// rotation. Since here we have reverse rotate,rather than index number,
// we check reverse index number which is 
// calculated by list_size - index_number.
int	move_b2(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (stack_rank_b(b, c))
		i = lstsize(b) - stack_rank_b(b, c);
	if ((i < (lstsize(a) - stack_index(a, c))) && stack_index(a, c))
		i = lstsize(a) - stack_index(a, c);
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
int	move_b3(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (stack_index(a, c))
		i = lstsize(a) - stack_index(a, c);
	i = stack_rank_b(b, c) + i;
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
int	move_b4(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (stack_rank_b(b, c))
		i = lstsize(b) - stack_rank_b(b, c);
	i = stack_index(a, c) + i;
	return (i);
}

int	rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = move_b2(a, b, a->nbr);
	while (tmp)
	{
		if (i > move_b1(a, b, tmp->nbr))
			i = move_b1(a, b, tmp->nbr);
		if (i > move_b2(a, b, tmp->nbr))
			i = move_b2(a, b, tmp->nbr);
		if (i > move_b4(a, b, tmp->nbr))
			i = move_b4(a, b, tmp->nbr);
		if (i > move_b3(a, b, tmp->nbr))
			i = move_b3(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
