/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   registr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:30:41 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:30:41 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			reg(const int *s, t_cont *cont)
{
	int			start;
	t_ent		*ent;

	start = 0;
	if (!(ent = (t_ent *)ft_memalloc(sizeof(t_ent))))
		ft_error("Malloc error", -1);
	while (start < cont->len)
	{
		ent->val = s[start];
		push(cont->b, ft_lstnew(ent, sizeof(t_ent)));
		start++;
	}
	start = 0;
	while (start < cont->len)
	{
		push(cont->a, pop(cont->b));
		start++;
	}
	free(ent);
}

size_t			reg_ord(t_cycle *cyc)
{
	int			i;
	int			start;
	t_list		*ent;
	t_list		*top;

	start = 0;
	ent = cyc->top;
	while (start < cyc->size)
	{
		i = 0;
		top = cyc->top;
		cs(ent)->ord = 1;
		while (i < cyc->size)
		{
			if ((cs(top)->val < cs(ent)->val))
				cs(ent)->ord++;
			i++;
			top = top->next;
		}
		start++;
		ent = ent->next;
	}
	return (0);
}

t_ent			*min_orders(t_cycle *cyc, int deep)
{
	t_list		*top;
	t_ent		*min;

	min = cs(cyc->top);
	top = cyc->top->next;
	deep = deep ? deep - 1 : cyc->size - 1;
	while (deep--)
	{
		min = cyc->cmp(min->ord, cs(top)->ord) >= 0 ? min : cs(top);
		top = top->next;
	}
	return (min);
}

t_ent			*max_orders(t_cycle *cyc, int deep)
{
	t_list		*top;
	t_ent		*max;

	max = cs(cyc->top);
	top = cyc->top->next;
	deep = deep ? deep - 1 : cyc->size - 1;
	while (deep--)
	{
		max = cyc->cmp(cs(top)->ord, max->ord) >= 0 ? max : cs(top);
		top = top->next;
	}
	return (max);
}

size_t			sorted(t_cycle *cyc, int deep)
{
	t_list		*top;

	if (!cyc->size || !deep)
		return (1);
	top = cyc->top;
	while (--deep)
	{
		if (cyc->cmp(cs(top->next)->ord, cs(top)->ord) >= 0)
			return (0);
		top = top->next;
	}
	return (1);
}
