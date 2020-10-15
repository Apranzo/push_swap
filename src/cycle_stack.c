/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 18:34:59 by cshinoha          #+#    #+#             */
/*   Updated: 2020/06/05 18:34:59 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cycle_stack.h"

void		*pop(t_cycle *cyc)
{
	t_list	*top;

	if (!cyc->size)
		return (NULL);
	top = cyc->top;
	top->prev->next = cyc->top->next;
	cyc->top = cyc->top->next;
	cyc->top->prev = top->prev;
	top->next = NULL;
	top->prev = NULL;
	cyc->size--;
	if (!cyc->size)
		cyc->top = NULL;
	return (top);
}

t_cycle		*push(t_cycle *cyc, t_list *el)
{
	if (!cyc->size)
	{
		cyc->top = el;
		el->next = el;
		el->prev = el;
	}
	else
	{
		cyc->top->prev->next = el;
		el->prev = cyc->top->prev;
		el->next = cyc->top;
		cyc->top->prev = el;
		cyc->top = el;
	}
	cyc->size++;
	return (cyc);
}

t_cycle		*rotate(t_cycle *cyc)
{
	if (cyc->size)
		cyc->top = cyc->top->next;
	return (cyc);
}

t_cycle		*rev_rotate(t_cycle *cyc)
{
	if (cyc->size)
		cyc->top = cyc->top->prev;
	return (cyc);
}

t_cycle		*swap(t_cycle *cyc)
{
	void	*new_top;

	if (cyc->top && cyc->top->next)
	{
		new_top = cyc->top->content;
		cyc->top->content = cyc->top->next->content;
		cyc->top->next->content = new_top;
	}
	return (cyc);
}
