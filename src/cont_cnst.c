/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont_cnst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:35:15 by cshinoha          #+#    #+#             */
/*   Updated: 2020/06/05 18:35:15 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int		fdeep_a(int deep)
{
	return (deep / 2 + deep % 2);
}

static int		fdeep_b(int deep)
{
	return (deep / 2);
}

static int		find_med(t_cycle *cyc, int deep)
{
	size_t		med;
	size_t		m_ord;

	if (!cyc->size)
		return (0);
	m_ord = min_orders(cyc, 0)->ord;
	med = m_ord + deep / 2;
	if (!check_push_middle(cyc, med))
		med++;
	return (med);
}

static int		find_med_rev(t_cycle *cyc, int deep)
{
	size_t		med;
	size_t		m_ord;

	if (!cyc->size)
		return (0);
	m_ord = min_orders(cyc, 0)->ord;
	med = m_ord - deep / 2 + !(deep % 2);
	if (med && !check_push_middle(cyc, med))
		med--;
	return (med);
}

t_cont			*cont_cnst(int *s, int len, t_opt *opt)
{
	t_cont		*cont;
	t_cbs		*cbs;

	cbs = NULL;
	if (!(cont = (t_cont *)ft_memalloc(sizeof(t_cont))) ||
		!(cbs = (t_cbs *)malloc(sizeof(t_cbs))))
		ft_error("Error\n", -1);
	cont->opt = opt;
	cont->cm = ft_strnew(0);
	cont->len = len;
	cbs->cmp = opt->dsc ? cmp_dsc : cmp_asc;
	cbs->fmed = opt->dsc ? find_med_rev : find_med;
	cbs->fdeep = opt->dsc ? fdeep_b : fdeep_a;
	cbs->fpush = opt->dsc ? push_b : push_a;
	cont->a = cycle_cnst("12457@8", cbs);
	cbs->cmp = !opt->dsc ? cmp_dsc : cmp_asc;
	cbs->fmed = !opt->dsc ? find_med_rev : find_med;
	cbs->fdeep = !opt->dsc ? fdeep_b : fdeep_a;
	cbs->fpush = !opt->dsc ? push_b : push_a;
	cont->b = cycle_cnst("21548A7", cbs);
	free(cbs);
	reg(s, cont);
	reg_ord(cont->a);
	return (cont);
}
