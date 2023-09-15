/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss(t_stack **a, t_stack **b, int j)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	sa(a, 1);
	sa(b, 1);
	if (j == 0)
		write(1, "ss\n", 3);
}

void	rr(t_stack **a, t_stack **b, int j)
{
	ra(a, 1);
	rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

void	rrr(t_stack **a, t_stack **b, int j)
{
	rra(a, 1);
	rrb(b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}
