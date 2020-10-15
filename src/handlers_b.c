/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:29:51 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:29:51 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			rrb(t_cont *cont)
{
	if (!cont->b->size)
		return (1);
	rev_rotate(cont->b);
	add_com(cont, "rrb\n");
	return (1);
}

int			rb(t_cont *cont)
{
	if (!cont->b->size)
		return (1);
	rotate(cont->b);
	add_com(cont, "rb\n");
	return (1);
}

int			pb(t_cont *cont)
{
	if (!cont->a->size)
		return (1);
	push(cont->b, pop(cont->a));
	add_com(cont, "pb\n");
	return (1);
}

int			sb(t_cont *cont)
{
	if (!cont->b->size)
		return (1);
	swap(cont->b);
	add_com(cont, "sb\n");
	return (1);
}
