/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:59:10 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/19 20:44:54 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_listt **stack, int val)
{
	t_listt	*head;
	int		min;

	head = *stack;
	min = INT_MAX;
	while (head)
	{
		if (head->index < min && head->index != val)
		{
			min = head->index;
		}
		head = head->next;
	}
	return (min);
}

void	sort_3(t_listt **stack_a)
{
	t_listt	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = get_min_index(stack_a, -1);
	next_min = get_min_index(stack_a, min);
	sort_3_breaker(stack_a, head, min, next_min);
}

void	sort_3_breaker(t_listt **stack_a, t_listt *head, int min, int next_min)
{
	if (head->index == min && head->next->index != next_min)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort_4(t_listt **stack_a, t_listt **stack_b)
{
	int		dis;
	int		min;

	min = get_min_index(stack_a, -1);
	if (sorted_stack(stack_a))
		return ;
	dis = get_distance(stack_a, min);
	if (dis == 1)
		ra(stack_a);
	else if (dis == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dis == 3)
		rra(stack_a);
	if (sorted_stack(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_listt **stack_a, t_listt **stack_b)
{
	int	dis;

	dis = get_distance(stack_a, get_min_index(stack_a, -1));
	if (dis == 1)
		ra(stack_a);
	else if (dis == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dis == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (dis == 4)
		rra(stack_a);
	if (sorted_stack(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}
