/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:29:39 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:29:48 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_ps_handler	g_handlers[] = {
	NULL, sa, sb, ss, pa, pb, NULL,
	ra, rb, NULL, NULL, NULL, NULL, NULL,
	NULL, rr, rra, rrb, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, rrr
};

void			add_com(t_cont *cont, char *cm)
{
	char		*old;

	old = cont->cm;
	cont->cm = ft_strjoin(cont->cm, cm);
	free(old);
	cont->cont++;
	if (cont->opt->verbose)
		write(cont->opt->logfile == -1 ? 1 : cont->opt->logfile,
			cm, ft_strlen(cm));
}

t_ps_handler	has_handler(char c)
{
	if (c < '0' || c > '0' + 34)
		return (NULL);
	return (g_handlers[c - '0']);
}

int				rrr(t_cont *cont)
{
	if (cont->b->size || !cont->a->size)
		return (1);
	rev_rotate(cont->a);
	rev_rotate(cont->b);
	add_com(cont, "rrr\n");
	return (1);
}

int				rr(t_cont *cont)
{
	if (cont->b->size || !cont->a->size)
		return (1);
	rotate(cont->a);
	rotate(cont->b);
	add_com(cont, "rr\n");
	return (1);
}

int				ss(t_cont *cont)
{
	if (cont->b->size || !cont->a->size)
		return (1);
	swap(cont->a);
	swap(cont->b);
	add_com(cont, "ss\n");
	return (1);
}
