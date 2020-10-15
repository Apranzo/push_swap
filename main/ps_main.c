/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:34:35 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:34:46 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			main(int ac, char **av)
{
	int		*arr;
	int		size;
	t_opt	*opt;

	av++;
	ac--;
	opt = find_opt(&ac, &av);
	arr = NULL;
	size = fill_stack(ac, av, &arr);
	sort(arr, size, opt);
}
