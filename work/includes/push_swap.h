/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:53:21 by moaregra          #+#    #+#             */
/*   Updated: 2024/05/12 17:58:30 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

// stack_helpers.
void				print_stack(t_list **stack);
char				*ft_strdup(const char *str);
char				**ft_split(char const *s, char c);
t_list				*fill_stack(char **str);
void				assign_index(t_list *stack_a, int stack_size);
int					get_stack_size(t_list *stack);
t_list				*get_stack_before_bottom(t_list *stack);
t_list				*get_stack_bottom(t_list *stack);
void				stack_add_bottom(t_list **stack, t_list *new);
t_list				*new_node(int value);
// actions
void				do_sa(t_list **stack_a);
void				do_sb(t_list **stack_b);
void				do_ss(t_list **stack_a, t_list **stack_b);
void				do_ra(t_list **stack_a);
void				do_rb(t_list **stack_b);
void				do_rr(t_list **stack_a, t_list **stack_b);
void				do_rra(t_list **stack);
void				do_rrb(t_list **stack);
void				do_rrr(t_list **stack_a, t_list **stack_b);
void				do_pa(t_list **stack_a, t_list **stack_b);
void				do_pb(t_list **stack_a, t_list **stack_b);
// sorting
int					ft_abs(int nb);
int					is_sorted(t_list *stack);
void				push_swap(t_list **stack_a, t_list **stack_b,
						int stack_size);
void				do_move(t_list **stack_a, t_list **stack_b, int cost_a,
						int cost_b);
void				sort_tiny(t_list **stack);
void				sort(t_list **stack_a, t_list **stack_b);
void				do_cheapest_move(t_list **stack_a, t_list **stack_b);
void				target_pos(t_list **stack_a, t_list **stack_b);
int					get_lowest_index_pos(t_list **stack);
void				get_cost(t_list **stack_a, t_list **stack_b);
// error handlers
void				ft_free(char **arr);
void				free_stack(t_list *stack);
void				exit_error(t_list *stack_a, t_list *stack_b);
// parse
int					check_valid(char **s);
int					ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
int					check_number(char *s1);
int					check_duplicates(char **s1);
int					ft_is_sign(char nb);
int					ft_is_digit(char nb);
int					ft_strlen(char *s);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strdup(const char *str);
int					num_cmp(char *s1, char *s2);
char				**splited(char **av);
char				*ft_strjoin(char *s1, char *s2);
// bonus
void	do_ra_bonus(t_list **stack_a);
void	do_rb_bonus(t_list **stack_b);
void	do_rr_bonus(t_list **stack_a, t_list **stack_b);
void	do_rra_bonus(t_list **stack);
void	do_rrb_bonus(t_list **stack);
void	do_rrr_bonus(t_list **stack_a, t_list **stack_b);
void	do_pa_bonus(t_list **stack_a, t_list **stack_b);
void	do_pb_bonus(t_list **stack_a, t_list **stack_b);
void	do_sa_bonus(t_list **stack_a);
void	do_sb_bonus(t_list **stack_b);
void	do_ss_bonus(t_list **stack_a, t_list **stack_b);
void    KO_handler(void);
void    OK_handler(void);
int 	ft_is_sorted(t_list **stack);
void	 ft_loop(t_list **stack_a, t_list **stack_b);
char 	*get_next_line(int fd);
size_t	ft_strlenn(const char *s);
char	*ft_strjoinn(char *stash, char *buffer);
char	*ft_strchr(char *s, int c);
size_t	ft_strlenn(const char *s);
void read_execution(t_list **stack_a,t_list **stack_b,char *str);

#endif
