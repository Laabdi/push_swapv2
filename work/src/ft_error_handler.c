/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:52:37 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/07 17:33:30 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
}

void	exit_error(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a)
		free_stack(stack_a);
	if (!stack_b)
		free_stack(stack_b);
	write(1, "Error\n", 6);
	exit(1);
}
