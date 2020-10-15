/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:31:16 by cshinoha          #+#    #+#             */
/*   Updated: 2020/02/27 14:31:24 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLE_STACK_H
# define CYCLE_STACK_H

# include "../src/libft/include/libft.h"

typedef int				(*t_comparator)(int, int);
typedef struct s_cycle	t_p_cycle;
typedef int				(*t_find_med)(struct s_cycle *, int);
typedef int				(*t_deep)(int);
typedef int				(*t_pushit)(int, int);

typedef struct			s_cb
{
	t_comparator		cmp;
	t_find_med			fmed;
	t_deep				fdeep;
	t_pushit			fpush;
}						t_cbs;

typedef struct			s_cycle
{
	t_list				*top;
	int					size;
	char				s;
	char				so;
	char				p;
	char				po;
	char				r;
	char				ro;
	char				rr;
	t_comparator		cmp;
	t_find_med			fmed;
	t_deep				fdeep;
	t_pushit			fpush;
}						t_cycle;

void					cycle_dstr(t_cycle *cyc);
t_cycle					*cycle_cnst(char *cms, t_cbs *cbs);
void					*pop(t_cycle *cyc);
t_cycle					*push(t_cycle *cyc, t_list *el);
t_cycle					*rotate(t_cycle *cyc);
t_cycle					*swap(t_cycle *cyc);

#endif
