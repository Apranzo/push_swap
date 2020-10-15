/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:30:16 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:30:16 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			rra(t_cont *cont)
{
	if (!cont->a->size)
		return (1);
	rev_rotate(cont->a);
	add_com(cont, "rra\n");
	return (1);
}

int			ra(t_cont *cont)
{
	if (!cont->a->size)
		return (1);
	rotate(cont->a);
	add_com(cont, "ra\n");
	return (1);
}

int			pa(t_cont *cont)
{
	if (!cont->b->size)
		return (1);
	push(cont->a, pop(cont->b));
	add_com(cont, "pa\n");
	return (1);
}

int			sa(t_cont *cont)
{
	if (!cont->a->size)
		return (1);
	swap(cont->a);
	add_com(cont, "sa\n");
	return (1);
}
