/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshinoha <cshinoha@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 17:32:18 by cshinoha          #+#    #+#             */
/*   Updated: 2020/06/06 17:32:18 by cshinoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_ps_handler	g_handlers[] = {
	pb, NULL, rrb, NULL, rb, pa, sb, rra, NULL, ra, NULL, sa,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	rrr, NULL, rr, NULL, NULL, NULL, ss
};

static char	*g_cmd[] = {
	"sa\n", "sb\n", "ss\n", "pa\n", "pb\n", "ra\n",
	"rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"
};

static t_ps_handler	get_handler(char *cm)
{
	size_t			i;
	int				ind;
	size_t			len;

	i = 0;
	ind = 0;
	len = ft_strlen(cm);
	while (i < len && cm[i] != '\n')
	{
		ind += cm[i];
		ind += cm[i++] % 7;
	}
	if (ind / 300)
		return (g_handlers[ind % 328]);
	return (g_handlers[ind % 210]);
}

static void			print_res(t_cont *cont)
{
	t_opt			*opt;

	opt = cont->opt;
	if (cont->b->size || !sorted(cont->a, cont->len))
		ft_putstr_fd(KO, opt->out == -1 ? 1 : opt->out);
	else
		ft_putstr_fd(OK, opt->out == -1 ? 1 : opt->out);
}

static int			cm_exists(char *cm)
{
	int				i;

	i = -1;
	while (i++ < 10)
		if (ft_strncmp(cm, g_cmd[i], ft_strlen(g_cmd[i]) + 1) == 0)
			return (1);
	return (0);
}

static void			run_cmd(t_cont *cont)
{
	char			*cm;
	int				log;

	log = cont->opt->logfile == -1 ? 1 : cont->opt->logfile;
	cm = NULL;
	cont->opt->verbose && ft_vfprintf(log, "read commands:\n");
	while (ft_gnc(STDIN_FILENO, &cm) && cm && *cm)
	{
		cont->opt->verbose && ft_vfprintf(log, "command: %s", cm);
		if (!cm_exists(cm))
			ft_error("Error\n", -1);
		else
			get_handler(cm)(cont);
		ft_bzero(cm, ft_strlen(cm));
		free(cm);
		log_status(cont);
	}
}

int					main(int ac, char **av)
{
	t_cont			*cont;
	int				*arr;
	int				size;
	t_opt			*opt;

	if (ac == 1)
		return (0);
	av++;
	ac--;
	opt = find_opt(&ac, &av);
	size = fill_stack(ac, av, &arr);
	cont = cont_cnst(arr, size, opt);
	run_cmd(cont);
	print_res(cont);
	free(arr);
	cont_dstr(cont);
}
