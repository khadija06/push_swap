/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:57:22 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/19 20:08:58 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_listt **stack)
{
	t_listt	*head;
	int		max_index;
	int		max_bits;

	head = *stack;
	max_index = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max_index)
		{
			max_index = head->index;
		}
		head = head->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_listt **stack_a, t_listt **stack_b)
{
	t_listt	*head_sa;
	int		i;
	int		j;
	int		len;
	int		max_bits;

	head_sa = *stack_a;
	i = 0;
	len = ft_linlen(head_sa);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < len)
		{
			head_sa = *stack_a;
			if (((head_sa->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_linlen(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	simple_sort(t_listt **stack_a, t_listt **stack_b)
{
	int	len;

	if (sorted_stack(stack_a) || ft_linlen(*stack_a) == 0
		|| ft_linlen(*stack_a) == 1)
		return ;
	len = ft_linlen(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_3(stack_a);
	else if (len == 4)
		sort_4(stack_a, stack_b);
	else if (len == 5)
		sort_5(stack_a, stack_b);
}
