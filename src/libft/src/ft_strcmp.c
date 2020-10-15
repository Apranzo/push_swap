/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 16:10:53 by cshinoha          #+#    #+#             */
/*   Updated: 2019/04/27 16:18:48 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	if (*s1 == '\0' && *s2 != '\0')
		return (-1);
	if (*s1 != '\0' && *s2 == '\0')
		return (1);
	if (*s1 != *s2)
		return (*s1 - *s2);
	return (ft_strcmp(++s1, ++s2));
}