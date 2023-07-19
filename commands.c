/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:00:45 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/20 16:39:12 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_listt **stack)
{
	t_listt	*head;
	t_listt	*linked;
	int		tmp_num;
	int		tmp_index;

	if (ft_linlen(*stack) < 2)
		return (-1);
	head = *stack;
	linked = head->next;
	if (!head && !linked)
		ft_error ("Error", NULL);
	tmp_num = head->num;
	tmp_index = head->index;
	head->num = linked->num;
	head->index = linked->index;
	linked->num = tmp_num;
	linked->index = tmp_index;
	return (0);
}

int	sa(t_listt **stack_a)
{
	if (swap(stack_a) == -1)
	{
		return (-1);
	}
	ft_putendl_fd ("sa", 1);
	return (0);
}

int	sb(t_listt **stack_b)
{
	if (swap(stack_b) == -1)
	{
		return (-1);
	}
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_listt **stack_a, t_listt **stack_b)
{
	if ((ft_linlen(*stack_a) < 2) || (ft_linlen(*stack_b) < 2))
	{
		return (-1);
	}
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	rrr(t_listt **stack_a, t_listt **stack_b)
{
	if ((ft_linlen(*stack_a) < 2) || (ft_linlen(*stack_b) < 2))
		return (-1);
	reverserotate(stack_a);
	reverserotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
