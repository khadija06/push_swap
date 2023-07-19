/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:08:33 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/18 19:25:35 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb(t_listt **stack_b)
{
	if (rotate(stack_b) == -1)
	{
		return (-1);
	}
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_listt **stack_a, t_listt **stack_b)
{
	if ((ft_linlen(*stack_a) < 2) || (ft_linlen(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	reverserotate(t_listt **stack)
{
	t_listt	*head;
	t_listt	*end;

	if (ft_linlen(*stack) < 2)
	{
		return (-1);
	}
	head = *stack;
	end = ft_last_struct(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
	head = head->next;
	}
	end->next = *stack;
	*stack = end;
	return (0);
}

int	rra(t_listt **stack_a)
{
	if (reverserotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_listt **stack_b)
{
	if (reverserotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}
