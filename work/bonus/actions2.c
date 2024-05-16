/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:44:23 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/16 10:44:41 by moaregra         ###   ########.fr       */
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