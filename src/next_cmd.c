/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:33:09 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:59:14 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"

static	t_stmt			*stmnew(int fd)
{
	t_stmt				*statement;

	if (!(statement = (t_stmt *)malloc(sizeof(t_stmt))))
		return (NULL);
	if (!(statement->res = ft_strnew(0)))
		return (NULL);
	statement->fd = fd;
	return (statement);
}

static int				get_line(char **line, t_stmt *s, int ret)
{
	char				*tmp;
	int					len;

	if (!(len = 0) && ret < 0 && !*s->res)
		return (-1);
	else if (ret == 0 && !*s->res)
		return (0);
	while (s->res[len] != '\n' && s->res[len] != '\0')
		len++;
	if (s->res[len] == '\n')
	{
		*line = ft_strsub(s->res, 0, len + 1);
		tmp = s->res;
		s->res = ft_strdup(s->res + len + 1);
		free(tmp);
	}
	else if (s->res[len] == '\0')
	{
		*line = ft_strdup(s->res);
		tmp = s->res;
		s->res = ft_strdup(s->res + len);
		free(tmp);
		return (0);
	}
	return (1);
}

static void				freest(t_stmt *s)
{
	ft_bzero(s->res, ft_strlen(s->res));
	free(s->res);
	ft_bzero(s, sizeof(t_stmt));
	free(s);
}

int						ft_gnc(const int fd, char **line)
{
	static t_stmt		*s;
	int					ret;
	char				buff[100];
	char				*tmp;

	if ((!s && !(s = stmnew(fd))) || fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	while (!ft_strchr(s->res, '\n') && (ret = read(fd, buff, 100)) > 0)
	{
		buff[ret] = '\0';
		tmp = s->res;
		s->res = ft_strjoin(s->res, buff);
		free(tmp);
	}
	get_line(line, s, ret);
	if (!s->res || !ft_strlen(s->res))
	{
		freest(s);
		s = NULL;
	}
	return (*line != NULL);
}
