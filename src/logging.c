/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:30:09 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:54:36 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void		pr_cyc(t_cycle *cyc, int fd)
{
	int			i;
	t_list		*tmp;

	i = 0;
	tmp = cyc->top;
	while (i++ < cyc->size)
	{
		ft_vfprintf(fd, "val:\t%d\t\tord:\t%zu\n",
					((t_ent *)tmp->content)->val,
					((t_ent *)tmp->content)->ord);
		tmp = tmp->next;
	}
}

void			log_status(t_cont *cont)
{
	int			fd;

	if (cont->opt->verbose)
	{
		fd = cont->opt->logfile == -1 ? 1 : cont->opt->logfile;
		ft_vfprintf(fd, "stack A: size:%d\n",
					cont->a->size);
		if (cont->a->size)
			pr_cyc(cont->a, fd);
		ft_vfprintf(fd, "stack B: size:%d\n",
					cont->a->size);
		if (cont->b->size)
			pr_cyc(cont->b, fd);
	}
}
