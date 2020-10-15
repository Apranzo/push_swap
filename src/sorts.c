/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:30:46 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:31:05 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void			ascent(t_cycle *cyc, t_cont *cont, size_t ord,
						t_ps_handler post)
{
	t_list		*front;
	t_list		*back;

	front = cyc->top;
	back = cyc->top;
	while (cs(front)->ord != ord && cs(back)->ord != ord)
	{
		front = front->next;
		back = back->prev;
	}
	if (cs(front)->ord == ord)
		while (cs(cyc->top)->ord != ord)
			has_handler(cyc->r)(cont);
	else
		while (cs(cyc->top)->ord != ord)
			has_handler(cyc->rr)(cont);
	post && post(cont);
}

int				order_push(t_cycle *cyc, t_cycle *ocyc, int len, t_cont *cont)
{
	size_t		max;

	if (len == 2)
	{
		if (ocyc->cmp(cs(cyc->top->next)->ord, cs(cyc->top)->ord) < 0)
			has_handler(cyc->s)(cont);
		while (len--)
			has_handler(cyc->po)(cont);
	}
	else if (len == 3)
	{
		max = cyc->size ? max_orders(cyc, 3)->ord : 0;
		while (len)
			if (len == 1 &&
				ocyc->cmp(cs(ocyc->top)->ord, cs(ocyc->top->next)->ord) < 0)
				has_handler(ocyc->s)(cont);
			else if (len != 1 && cs(cyc->top)->ord != max)
				len-- && has_handler(cyc->po)(cont);
			else if (len != 1 &&
				cyc->cmp(cs(cyc->top)->ord, cs(cyc->top->next)->ord) < 0)
				has_handler(cyc->s)(cont);
			else
				len-- && has_handler(cyc->po)(cont);
	}
	return (1);
}

int				order_sm(t_cycle *cyc, t_cont *cont)
{
	size_t		min;

	min = cyc->size ? min_orders(cyc, 0)->ord : 0;
	if (cyc->size == 2 &&
		cyc->cmp(cs(cyc->top->next)->ord, cs(cyc->top)->ord) > 0)
		has_handler(cyc->r)(cont);
	else if (cyc->size == 3)
		while (!sorted(cyc, 3))
		{
			if (cs(cyc->top->next)->ord == min &&
					cyc->cmp(cs(cyc->top)->ord, cs(cyc->top->prev)->ord) < 0)
				has_handler(cyc->r)(cont);
			else if (cyc->cmp(cs(cyc->top)->ord, cs(cyc->top->next)->ord) < 0)
				has_handler(cyc->s)(cont);
			else if (cs(cyc->top->prev)->ord == min)
				has_handler(cyc->rr)(cont);
			else if (cyc->cmp(cs(cyc->top->next)->ord,
						cs(cyc->top->prev)->ord) < 0)
				has_handler(cyc->rr)(cont);
			else
				has_handler(cyc->r)(cont);
		}
	ascent(cyc, cont, min, NULL);
	return (1);
}

int				order_3(t_cycle *cyc, int deep, t_cont *cont)
{
	if (deep <= 3 && cyc->size <= 3)
		return (order_sm(cyc, cont));
	else if (deep == 2)
	{
		if (cyc->cmp(cs(cyc->top)->ord, cs(cyc->top->next)->ord) < 0)
			has_handler(cyc->s)(cont);
		return (1);
	}
	while (cyc->size != 3 && (deep != 3 || !sorted(cyc, deep)))
		if (deep >= 2 &&
				cyc->cmp(cs(cyc->top)->ord, cs(cyc->top->next)->ord) < 0)
			has_handler(cyc->s)(cont);
		else if (deep == 3 && ((
				cyc->cmp(cs(cyc->top->next)->ord, cs(cyc->top)->ord) < 0) &&
				cyc->cmp(
					cs(cyc->top->next)->ord,
					cs(cyc->top->next->next)->ord) < 0))
			deep-- && has_handler(cyc->r)(cont);
		else if (deep++)
			has_handler(cyc->rr)(cont);
	return (1);
}
