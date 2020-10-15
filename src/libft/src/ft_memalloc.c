/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:34:01 by cshinoha          #+#    #+#             */
/*   Updated: 2019/04/27 16:18:48 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../include/libft.h"

void	*ft_memalloc(size_t size)
{
	void *area;

	area = malloc(size);
	if (area)
		ft_bzero(area, size);
	return (area);
}
