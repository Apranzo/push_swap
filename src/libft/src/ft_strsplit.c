/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:00:18 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:53:29 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

static int			ft_wordlen(char const *s, char c)
{
	int				i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char			*ft_storeword(char const *s, char c)
{
	int				i;
	char			*tmp;

	i = -1;
	if (!(tmp = ft_strnew(ft_wordlen(s, c))))
		return (NULL);
	while (s[++i] && s[i] != c)
		tmp[i] = s[i];
	return (tmp);
}

char				**ft_strsplit(char const *s, char c)
{
	int				words;
	int				nofword;
	char			**tab;

	if (!s)
		return (NULL);
	nofword = 0;
	words = ft_cntwords(s, c);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (!(tab[nofword] = ft_storeword(s, c)))
				return (NULL);
			nofword++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	tab[nofword] = 0;
	return (tab);
}
