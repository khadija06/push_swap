/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:40:02 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/20 16:37:41 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct t_list
{
	struct t_list	*next;
	int				num;
	int				index;

}t_listt;
char	**ft_check_parameter(int ac, char **argv);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_error(char *error, char **num_array);
t_listt	*ft_new_list(int num);
t_listt	*ft_last_struct(t_listt *head);
void	index_the_index(t_listt**stack);
char	**ft_split(char *str, char c);
void	ft_connect_stack(t_listt **stack, t_listt *new);
int		ft_atoi(const char *str);
void	ft_free(char **str);
int		ft_strlen(const char *str);
int		sorted_stack(t_listt **stack);
int		ft_linlen(t_listt *head);
int		swap(t_listt **stack);
int		sa(t_listt **stack_a);
int		sb(t_listt **stack_b);
int		ss(t_listt **stack_a, t_listt **stack_b);
int		push(t_listt **stack_receive, t_listt **stack_send);
int		pa(t_listt **stack_a, t_listt **stack_b);
int		pb(t_listt **stack_a, t_listt **stack_b);
int		rotate(t_listt **stack);
int		ra(t_listt **stack_a);
int		rb(t_listt **stack_b);
int		rr(t_listt **stack_a, t_listt **stack_b);
int		reverserotate(t_listt **stack);
int		rra(t_listt **stack_a);
int		rrb(t_listt **stack_b);
int		rrr(t_listt **stack_a, t_listt **stack_b);
int		get_distance(t_listt **stack, int index);
void	sort_5(t_listt **stack_a, t_listt **stack_b);
void	simple_sort(t_listt **stack_a, t_listt **stack_b);
void	radix_sort(t_listt **stack_a, t_listt **stack_b);
void	free_stack(t_listt **stack);
int		ft_isdigit(int i);
int		get_min_index(t_listt **stack, int val);
void	sort_3_breaker(t_listt **stack_a, t_listt *head, int min, int next_min);
int		invalid_argument(const char *arg);
int		is_valid_integer(const char *str);
int		are_all_arguments_spaces(int argc, char *argv[]);
void	sort_3_breaker(t_listt **stack_a, t_listt *head, int min, int next_min);
void	sort_3(t_listt **stack_a);
void	sort_4(t_listt **stack_a, t_listt **stack_b);
void	sort_5(t_listt **stack_a, t_listt **stack_b);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif