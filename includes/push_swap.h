/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adedieu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:01:25 by adedieu           #+#    #+#             */
/*   Updated: 2023/09/15 21:06:33 by adedieu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void		ra(t_stack **stack_a, int j);
void		rb(t_stack **stack_b, int j);
void		sa(t_stack **stack_a, int j);
void		sb(t_stack **stack_b, int j);
void		pa(t_stack **stack_a, t_stack **stack_b, int j);
void		pb(t_stack **stack_a, t_stack **stack_b, int j);
void		rra(t_stack **stack_a, int j);
void		ss(t_stack **stack_a, t_stack **stack_b, int j);
void		rr(t_stack **stack_a, t_stack **stack_b, int j);
void		rrr_sub(t_stack **stack_b, int j);
void		rrr(t_stack **stack_a, t_stack **stack_b, int j);
int			move_a1(t_stack *stack_a, t_stack *stack_b, int c);
int			move_a2(t_stack *stack_a, t_stack *stack_b, int c);
int			move_a3(t_stack *stack_a, t_stack *stack_b, int c);
int			move_a4(t_stack *stack_a, t_stack *stack_b, int c);
int			move_b1(t_stack *stack_a, t_stack *stack_b, int c);
int			move_b2(t_stack *stack_a, t_stack *stack_b, int c);
int			move_b3(t_stack *stack_a, t_stack *stack_b, int c);
int			move_b4(t_stack *stack_a, t_stack *stack_b, int c);
int			rarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int			rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int			rrarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int			rarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);
void		rrb(t_stack **stack_b, int j);
int			rotate_type_ab(t_stack *stack_a, t_stack *stack_b);
int			rotate_type_ba(t_stack *stack_a, t_stack *stack_b);
int			stack_min(t_stack *stack_a);
int			stack_max(t_stack *stack_a);
int			stack_index(t_stack *stack_a, int nbr);
int			stack_rank_b(t_stack *stack_b, int nbr_push);
int			stack_rank_a(t_stack *stack_a, int nbr);
void		sort(t_stack **stack_a);
int			sorted(t_stack *stack_a);
void		sort_big(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
void		list_args(char **argv, t_stack **stack_a);
void		add_back(t_stack **stack, t_stack *stack_new);
t_stack		*stack_new(int content);
int			check_args(char **argv);
void		alpha_check(char **argv);
int			check_error(char **argv, int i, int j);
int			checkdup(t_stack *stack_a);
int			ft_isalpha(int c);
int			sign(int c);
int			digit(int c);
int			space(int c);
void		error(void);
void		ft_free(t_stack **stack);
t_stack		*lstlast(t_stack *stack);
t_stack		*lstlast(t_stack *lst);
int			lstsize(t_stack *lst);
t_stack		*parsing(int argc, char **argv);
t_stack		*line_parsing(char **argv);
void		freestr(char **lst);
char		*check(t_stack **stack_a, t_stack **stack_b, char *line);
t_stack		*process(int argc, char **argv);
void		sort_b_till_3(t_stack **stack_a, t_stack **stack_b);
void		error_ch(void);

#endif
