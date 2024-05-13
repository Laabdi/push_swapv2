/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:09:18 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/12 18:04:29 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	free_str_array(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}
void	print_stack(t_list **stack)
{
	t_list *tmp = *stack;
	while(tmp)
	{
		printf("%d ,",tmp->value);
		tmp = tmp->next;
	}
}
int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**nums;

	if (ac < 2)
		return (0);
	nums = splited(av);
	if (!nums)
		return (1);
	if (!check_valid(nums))
	{
		free_str_array(nums);
		exit_error(NULL, NULL);
	}
	stack_b = NULL;
	stack_a = fill_stack(nums);
	ft_loop(&stack_a, &stack_b);
	free_stack(stack_a);
	if (stack_b != NULL)
		free(stack_b);
	free_str_array(nums);
	return (0);
}
