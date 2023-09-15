/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	if ((*stack_a)->nbr < (*stack_a)->next->nbr
		&& (*stack_a)->nbr < (*stack_a)->next->next->nbr)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr
		&& (*stack_a)->nbr > (*stack_a)->next->next->nbr)
	{
		ra(stack_a, 0);
		if (!sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (stack_index(*stack_a, stack_max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}

void	sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (lstsize(*stack_a) > 3 && !sorted(*stack_a))
	{
		tmp = *stack_a;
		i = rotate_type_ab(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == move_b1(*stack_a, *stack_b, tmp->nbr))
				i = rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == move_b2(*stack_a, *stack_b, tmp->nbr))
				i = rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == move_b4(*stack_a, *stack_b, tmp->nbr))
				i = rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == move_b3(*stack_a, *stack_b, tmp->nbr))
				i = rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (lstsize(*stack_a) > 3 && !sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (lstsize(*stack_a) > 3 && !sorted(*stack_a))
		pb(stack_a, &stack_b, 0);
	if (lstsize(*stack_a) > 3 && !sorted(*stack_a))
		sort_b_till_3(stack_a, &stack_b);
	if (!sorted(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == move_a1(*stack_a, *stack_b, tmp->nbr))
				i = rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == move_a3(*stack_a, *stack_b, tmp->nbr))
				i = rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == move_a2(*stack_a, *stack_b, tmp->nbr))
				i = rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == move_a4(*stack_a, *stack_b, tmp->nbr))
				i = rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = stack_index(*stack_a, stack_min(*stack_a));
		if (i < lstsize(*stack_a) - i)
		{
			while ((*stack_a)->nbr != stack_min(*stack_a))
				ra(stack_a, 0);
		}
		else
			while ((*stack_a)->nbr != stack_min(*stack_a))
				rra(stack_a, 0);
	}
}
