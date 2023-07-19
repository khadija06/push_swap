/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:58:19 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/20 14:49:22 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_listt	*get_next_min(t_listt**stack)
{
	t_listt	*head;
	t_listt	*min_num;
	int		found_min;

	min_num = NULL;
	found_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!found_min || head->num < min_num->num))
			{
				min_num = head;
				found_min = 1;
			}
			head = head->next;
		}
	}
	return (min_num);
}

void	index_the_index(t_listt**stack)
{
	t_listt	*head;
	int		sum_index;

	sum_index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = sum_index++;
		head = get_next_min(stack);
	}
}

int	sorted_stack(t_listt **stack)
{
	t_listt	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->num > head->next->num)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_listt **stack, int index)
{
	t_listt	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
