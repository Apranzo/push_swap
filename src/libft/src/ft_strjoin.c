/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:24:28 by cshinoha          #+#    #+#             */
/*   Updated: 2019/05/25 18:59:49 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*new;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	new = ft_strnew(size1 + size2);
	ft_strcpy(new, s1);
	ft_strncat(new, s2, size2);
	return (new);
}
