/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:00:11 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/19 19:20:30 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listt	*ft_new_list(int num)
{
	t_listt	*new;

	new = malloc(sizeof(t_listt));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_listt	*ft_last_struct(t_listt *head)
{
	t_listt	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_connect_stack(t_listt **stack, t_listt *new)
{
	t_listt	*tmp;

	if (*stack)
	{
		tmp = ft_last_struct(*stack);
		tmp->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	ft_linlen(t_listt *head)
{
	size_t	i;
	t_listt	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
