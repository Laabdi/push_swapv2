/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:09:10 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/16 10:47:43 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


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

