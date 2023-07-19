/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 18:55:27 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/18 19:20:03 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_listt **stack_receive, t_listt **stack_send)
{
	t_listt	*tmp;
	t_listt	*head_receive;
	t_listt	*head_send;

	if (ft_linlen(*stack_send) == 0)
		return (-1);
	head_receive = *stack_receive;
	head_send = *stack_send;
	tmp = head_send;
	head_send = head_send->next;
	*stack_send = head_send;
	if (!head_receive)
	{
	head_receive = tmp;
	head_receive->next = NULL;
	*stack_receive = head_receive;
	}
	else
	{
	tmp->next = head_receive;
	*stack_receive = tmp;
	}
	return (0);
}

int	pa(t_listt **stack_a, t_listt **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_listt **stack_a, t_listt **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	rotate(t_listt **stack)
{
	t_listt	*head;
	t_listt	*end;

	if (ft_linlen(*stack) < 2)
		return (-1);
	head = *stack;
	end = ft_last_struct(head);
	*stack = head->next;
	head->next = NULL;
	end->next = head;
	return (0);
}

int	ra(t_listt **stack_a)
{
	if (rotate(stack_a) == -1)
	{
		return (-1);
	}
	ft_putendl_fd("ra", 1);
	return (0);
}
