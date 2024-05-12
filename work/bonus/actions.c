/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:09:10 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/09 16:52:36 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = get_stack_bottom(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

void	do_ra_bonus(t_list **stack_a)
{
	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	do_rotate(stack_a);
}

void	do_rb_bonus(t_list **stack_b)
{
	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	do_rotate(stack_b);
}

void	do_rr_bonus(t_list **stack_a, t_list **stack_b)
{
	if ((!(*stack_a) || !((*stack_a)->next)) && (!(*stack_b)
			|| !((*stack_b)->next)))
		return ;
	do_rotate(stack_a);
	do_rotate(stack_b);
}
static void	do_rev_rotate(t_list **stack)
{
	t_list	*tail;
	t_list	*before_tail;
	t_list	*tmp;

	tail = get_stack_bottom(*stack);
	before_tail = get_stack_before_bottom(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	do_rra_bonus(t_list **stack)
{
	do_rev_rotate(stack);
}

void	do_rrb_bonus(t_list **stack)
{
	do_rev_rotate(stack);
}

void	do_rrr_bonus(t_list **stack_a, t_list **stack_b)
{
	do_rev_rotate(stack_a);
	do_rev_rotate(stack_b);
}
static void	do_push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa_bonus(t_list **stack_a, t_list **stack_b)
{
	do_push(stack_b, stack_a);
}

void	do_pb_bonus(t_list **stack_a, t_list **stack_b)
{
	do_push(stack_a, stack_b);
}
static void	swap_bonus(t_list *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	do_sa_bonus(t_list **stack_a)
{
	swap_bonus(*stack_a);
}

void	do_sb_bonus(t_list **stack_b)
{
	swap_bonus(*stack_b);
}

void	do_ss_bonus(t_list **stack_a, t_list **stack_b)
{
	swap_bonus(*stack_a);
	swap_bonus(*stack_b);
}