/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:09:20 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/12 17:54:01 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i ;
	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return 0;
	return (s1[i] - s2[i]);
}


void read_execution(t_list **stack_a,t_list **stack_b,char *str)
{
	if(ft_strncmp(str,"pb\n",3) == 0)
		do_pb_bonus(stack_a,stack_b);
	else if(ft_strncmp(str,"pa\n",3) == 0)
		do_pa_bonus(stack_a,stack_b);
	else if(ft_strncmp(str,"rb\n",3) == 0)
		do_rb_bonus(stack_b);
	else if(ft_strncmp(str,"ra\n",3) == 0)
		do_ra_bonus(stack_a);
	else if(ft_strncmp(str,"rr\n",3) == 0)
		do_rr_bonus(stack_a,stack_b);
	else if(ft_strncmp(str,"rra\n",4) == 0)
		do_rra_bonus(stack_a);
	else if(ft_strncmp(str,"rra\n",4) == 0)
		do_rra_bonus(stack_a);
	else if(ft_strncmp(str,"rrr\n",4) == 0)
		do_rrr_bonus(stack_a, stack_b);
	else if(ft_strncmp(str,"sa\n",3) == 0)
		do_sa_bonus(stack_a);
	else if(ft_strncmp(str,"sb\n",3) == 0)
		do_sb_bonus(stack_b);
	else if(ft_strncmp(str,"sa\n",3) == 0)
		do_sa_bonus(stack_a);
}