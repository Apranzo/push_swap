/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_cnst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:29:26 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:29:48 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cycle_stack.h"

t_cycle		*cycle_cnst(char *cms, t_cbs *cbs)
{
	t_cycle *cyc;

	if (!(cyc = (t_cycle *)ft_memalloc(sizeof(t_cycle))))
		ft_error("Malloc error", -1);
	cyc->s = *cms++;
	cyc->so = *cms++;
	cyc->p = *cms++;
	cyc->po = *cms++;
	cyc->r = *cms++;
	cyc->rr = *cms++;
	cyc->ro = *cms;
	cyc->cmp = cbs->cmp;
	cyc->fmed = cbs->fmed;
	cyc->fdeep = cbs->fdeep;
	cyc->fpush = cbs->fpush;
	return (cyc);
}

void		cycle_dstr(t_cycle *cyc)
{
	ft_lstfree(cyc->top, cyc->size);
	free(cyc);
}
