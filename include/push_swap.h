/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 17:31:44 by cshinoha          #+#    #+#             */
/*   Updated: 2020/06/06 17:31:44 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/libft/include/libft.h"
# include "cycle_stack.h"
# define OK "OK\n"
# define KO "KO\n"

typedef struct		s_opt
{
	int				out;
	int				dsc;
	int				logfile;
	int				verbose;
}					t_opt;

typedef struct		s_container
{
	char			*cm;
	size_t			cont;
	int				len;
	t_cycle			*a;
	t_cycle			*b;
	t_opt			*opt;
}					t_cont;

typedef struct		s_entity
{
	int				val;
	size_t			ord;
}					t_ent;

typedef int			(*t_ps_handler)(t_cont *cont);

t_opt				*opt_cnst();
void				log_status(t_cont *cont);
t_opt				*find_opt(int *ac, char ***av);
int					ft_gnc(const int fd, char **line);
void				add_com(t_cont *cont, char *cm);
int					push_a(int l, int r);
int					push_b(int l, int r);
int					cmp_asc(int l, int r);
int					cmp_dsc(int l, int r);
void				sort(int *s, size_t len, t_opt *opt);
int					fill_stack(int size, char **av, int **arr);
t_cont				*cont_cnst(int *s, int len, t_opt *opt);
void				cont_dstr(t_cont *cont);
int					check_push_middle(t_cycle *cyc, size_t med);
void				ascent(t_cycle *cyc,
							t_cont *cont,
							size_t ord,
							t_ps_handler post);
int					order_push(t_cycle *cyc,
								t_cycle *ocyc,
								int len,
								t_cont *cont);
int					order_3(t_cycle *cyc, int deep, t_cont *cont);
int					is_num_valid(int value, char *str);
int					is_num_duplicate(const int *arr, size_t ind);
t_ps_handler		has_handler(char c);
t_ent				*min_orders(t_cycle *cyc, int deep);
t_ent				*max_orders(t_cycle *cyc, int deep);
t_ent				*cs(t_list *l);
size_t				reg_ord(t_cycle *cyc);
void				reg(const int *s, t_cont *cont);
size_t				sorted(t_cycle *cyc, int deep);
t_cycle				*rev_rotate(t_cycle *cyc);
int					sa(t_cont *cont);
int					sb(t_cont *cont);
int					ss(t_cont *cont);
int					pa(t_cont *cont);
int					pb(t_cont *cont);
int					ra(t_cont *cont);
int					rb(t_cont *cont);
int					rr(t_cont *cont);
int					rra(t_cont *cont);
int					rrb(t_cont *cont);
int					rrr(t_cont *cont);

#endif
