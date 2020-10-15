/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:30:32 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 15:20:17 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int				check_push_middle(t_cycle *cyc, size_t med)
{
	t_list		*node;

	if (!cyc->size)
		return (0);
	if (cyc->fpush(cs(cyc->top)->ord, med))
		return (1);
	node = cyc->top->next;
	while (node != cyc->top)
	{
		if (cyc->fpush(cs(node)->ord, med))
			return (1);
		node = node->next;
	}
	return (0);
}

static int		resolve(t_cycle *cyc, t_cont *cont, int med)
{
	t_ent		*top;
	t_ent		*bot;

	if (!cyc->size)
		return (0);
	top = cs(cyc->top);
	bot = cs(cyc->top->prev);
	if (cyc->fpush(bot->ord, med) &&
		cyc->cmp(cyc->cmp(top->ord, med), cyc->cmp(bot->ord, med)) > 0)
		has_handler(cyc->rr)(cont) && has_handler(cyc->po)(cont);
	else if (cyc->fpush(top->ord, med))
		has_handler(cyc->po)(cont);
	else
	{
		has_handler(cyc->r)(cont);
		return (1);
	}
	return (0);
}

t_ent			*last_ordered(t_cycle *cyc)
{
	t_list		*tmp;

	if (cs(cyc->top->prev) != max_orders(cyc, 0))
		return (cs(cyc->top->prev));
	tmp = cyc->top->prev;
	while (tmp != cyc->top)
		if (cyc->cmp(cs(tmp)->ord, cs(tmp->prev)->ord) != -1)
			return (cs(tmp));
		else
			tmp = tmp->prev;
	return (cs(cyc->top));
}

static int		quick_sort(t_cycle *cyc, int deep, t_cont *cont)
{
	int			gr_med;
	int			push;

	if (cyc == cont->a && sorted(cyc, deep))
		return (1);
	if (cyc->size && cyc == cont->b && sorted(cyc, deep))
		while (deep--)
			has_handler(cont->a->p)(cont);
	if (deep <= 3 && cyc == cont->a)
		return (order_3(cyc, deep, cont));
	if (deep <= 3 && cyc->size && cyc == cont->b)
		return (order_push(cyc, cont->a, deep, cont));
	if (!(gr_med = cyc->fmed(cyc, deep)))
		return (0);
	push = 0;
	while (check_push_middle(cyc, gr_med))
		push += resolve(cyc, cont, gr_med);
	while (cyc->size != cyc->fdeep(deep) && push--)
		has_handler(cyc->rr)(cont);
	log_status(cont);
	return (quick_sort(cont->a, cont->a->fdeep(deep), cont) &&
			quick_sort(cont->b, cont->b->fdeep(deep), cont));
}

void			sort(int *s, size_t len, t_opt *opt)
{
	t_cont		*cont;
	t_list		*node;
	int			deep;

	cont = cont_cnst(s, len, opt);
	deep = 1;
	node = cont->a->top;
	while (cont->a->size &&
		last_ordered(cont->a)->ord != cs(node)->ord && ++deep)
		node = node->next;
	quick_sort(cont->a, deep, cont);
	write(cont->opt->out == -1 ? 1 : cont->opt->out, cont->cm,
			ft_strlen(cont->cm));
	if (cont->opt->out != -1)
		close(cont->opt->out);
	free(s);
	cont_dstr(cont);
}
