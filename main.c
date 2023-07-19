/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:53:27 by knabeel           #+#    #+#             */
/*   Updated: 2023/07/19 15:51:20 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	in_the_stack(t_listt **stack, char **argv)
{
	t_listt	*new;
	int		i;

	i = 0;
	while (argv[i])
	{
		new = ft_new_list(ft_atoi(argv[i]));
		ft_connect_stack(stack, new);
		i++;
	}
	index_the_index(stack);
}

static void	check_stack(t_listt **stack_a, t_listt **stack_b)
{
	if (ft_linlen(*stack_a) <= 5)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	are_all_arguments_spaces(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != ' ')
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **argv)
{
	t_listt	**stack_a;
	t_listt	**stack_b;
	char	**numbrs_array;

	if (ac < 2)
		return (ft_error("Error", NULL), -1);
	numbrs_array = ft_check_parameter(ac, argv);
	if (are_all_arguments_spaces(ac, argv))
	{
		//return (ft_error("Error", NULL), -1);
		for (int i = 0; numbrs_array[i]; i++)
			free(numbrs_array[i]);
		free(numbrs_array);
		ft_error("Error", NULL);
		return (1);
	}
	stack_a = (t_listt **)malloc(sizeof(t_listt));
	stack_b = (t_listt **)malloc(sizeof(t_listt));
	*stack_a = NULL;
	*stack_b = NULL;
	in_the_stack (stack_a, numbrs_array);
	ft_free(numbrs_array);
	if (sorted_stack(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	check_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
