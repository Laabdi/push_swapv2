/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 10:47:44 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/16 10:47:51 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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