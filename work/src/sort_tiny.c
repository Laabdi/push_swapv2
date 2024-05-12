/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:52:54 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/05 18:23:33 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_highest_index(t_list *stack)
{
	int		index;
	t_list	*tmp;

	index = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (index < tmp->index)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

void	sort_tiny(t_list **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
