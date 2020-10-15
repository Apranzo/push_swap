/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 17:33:02 by cshinoha          #+#    #+#             */
/*   Updated: 2020/06/06 17:33:02 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			is_num_valid(int value, char *str)
{
	char	*value_str;
	int		res;

	res = 0;
	value_str = ft_itoa(value);
	if (ft_strcmp(value_str, str + (str[0] == '+')) == 0)
		res = 1;
	if (value_str)
		free(value_str);
	return (res);
}

int			is_num_duplicate(const int *arr, size_t ind)
{
	size_t	i;

	i = 0;
	while (i < ind)
	{
		if (arr[i] == arr[ind])
			return (1);
		i++;
	}
	return (0);
}

static int	count_args(char **ar)
{
	int		ctr;

	ctr = 0;
	while (*ar++)
		ctr++;
	return (ctr);
}

static int	validation(char **av, int **arr)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		(*arr)[i] = ft_atoi(av[i]);
		if (!is_num_valid((*arr)[i], av[i]) || is_num_duplicate(*arr, i))
			ft_error("Error\n", -1);
		i++;
	}
	return (i);
}

int			fill_stack(int size, char **av, int **arr)
{
	if (size == 1)
	{
		av = ft_strsplit(*av, ' ');
		if (!(size = count_args(av)))
			ft_error("Error\n", -1);
		if (!(*arr = malloc(sizeof(int) * size)))
			ft_error("Null pointer error", -1);
		size = validation(av, arr);
		ft_freematr(av);
		return (size);
	}
	if (!(*arr = malloc(sizeof(int) * size)))
		ft_error("Null pointer error", -1);
	size = validation(av, arr);
	return (size);
}
