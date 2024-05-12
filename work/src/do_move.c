/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:52:36 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/05 18:23:09 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_rev_rotate_both(t_list **stack_a, t_list **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_rrr(stack_a, stack_b);
	}
}

static void	do_rotate_both(t_list **stack_a, t_list **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rr(stack_a, stack_b);
	}
}

static void	do_rotate_a(t_list **stack_a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_ra(stack_a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rra(stack_a);
			(*cost)++;
		}
	}
}

static void	do_rotate_b(t_list **stack_b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rb(stack_b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_rrb(stack_b);
			(*cost)++;
		}
	}
}

void	do_move(t_list **stack_a, t_list **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rev_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_a(stack_a, &cost_a);
	do_rotate_b(stack_b, &cost_b);
	do_pa(stack_a, stack_b);
}
