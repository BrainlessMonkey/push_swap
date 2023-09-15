/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

int	stack_index(t_stack *a, int nbr)
{
	int		i;

	i = 0;
	while (a->nbr != nbr && ++i)
		a = a->next;
	a->index = 0;
	return (i);
}

int	stack_rank_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < lstlast(stack_b)->nbr)
		i = 0;
	else if (nbr_push > stack_max(stack_b) || nbr_push < stack_min(stack_b))
		i = stack_index(stack_b, stack_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while ((stack_b->nbr < nbr_push || tmp->nbr > nbr_push) && ++i)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
		}
	}
	return (i);
}

int	stack_rank_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > lstlast(stack_a)->nbr)
		i = 0;
	else if (nbr_push > stack_max(stack_a) || nbr_push < stack_min(stack_a))
		i = stack_index(stack_a, stack_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while ((stack_a->nbr > nbr_push || tmp->nbr < nbr_push) && ++i)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
		}
	}
	return (i);
}

void	add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(lstlast(*stack))->next = stack_new;
}

t_stack	*stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		error();
	new->nbr = content;
	new->next = NULL;
	return (new);
}
