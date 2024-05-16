/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:09:23 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/16 10:45:37 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ko_handler(void)
{
	write(1, "KO", 2);
	exit(1);
}

void	ok_handler(void)
{
	write(1, "OK", 2);
	exit(1);
}

int	ft_is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_loop(t_list **stack_a, t_list **stack_b)
{
	char	*s;

	while (1)
	{
		s = get_next_line(0);
		if (s == NULL)
			break ;
		read_execution(stack_a, stack_b, s);
	}
	if (*stack_b != NULL)
		ko_handler();
	if (ft_is_sorted(stack_a) == 0)
		ko_handler();
	else
		ok_handler();
}
