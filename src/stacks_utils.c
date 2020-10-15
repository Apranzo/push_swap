/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:30:52 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:30:52 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	push_a(int l, int r)
{
	return (r > l);
}

int	push_b(int l, int r)
{
	return (r <= l);
}

int	cmp_asc(int l, int r)
{
	return (r - l);
}

int	cmp_dsc(int l, int r)
{
	return (l - r);
}
