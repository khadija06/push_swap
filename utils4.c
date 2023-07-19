/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knabeel <knabeel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:39:44 by knabeel           #+#    #+#             */
/*   Updated: 2023/06/20 16:41:11 by knabeel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	if (num[0] == '-' && ft_strlen(num) == 1)
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	invalid_argument(const char *arg)
{
	size_t	arg_length;

	arg_length = ft_strlen(arg);
	if (!is_valid_integer(arg))
		return (1);
	if (arg_length > 11)
		return (1);
	if (arg_length == 11 && arg[0] != '-')
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1)
		return (NULL);
	i = -1;
	j = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	if (s1 != NULL)
		free(s1);
	return (new);
}

char	**ft_check_parameter(int ac, char **argv)
{
	int		i;
	long	tmp;
	char	*argv2;
	char	**argv3;

	i = 0;
	argv2 = ft_strdup(argv[1]);
	while ((++i + 1) < ac && ac != 2)
	{
		argv2 = ft_strjoin(argv2, " ");
		argv2 = ft_strjoin(argv2, argv[i + 1]);
	}
	argv3 = ft_split(argv2, ' ');
	free(argv2);
	i = -1;
	while (argv3[++i])
	{	
		tmp = ft_atoi(argv3[i]);
		if (!ft_isnum(argv3[i]) || ft_contains(tmp, argv3, i)
			|| invalid_argument(argv3[i]))
			ft_error("Error", argv3);
	}
	return (argv3);
}
