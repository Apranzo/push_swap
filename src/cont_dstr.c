/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cont_dstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:29:03 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:29:09 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		cont_dstr(t_cont *cont)
{
	cycle_dstr(cont->a);
	cycle_dstr(cont->b);
	free(cont->opt);
	free(cont->cm);
	free(cont);
}
