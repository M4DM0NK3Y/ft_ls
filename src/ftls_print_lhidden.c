/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_print_lhidden.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:03:59 by cterblan          #+#    #+#             */
/*   Updated: 2018/09/14 08:19:26 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

static void	ftls_printing(t_lsflags *f, t_lslink *tmp)
{
	ft_printf("%s ", tmp->perm);
	ft_printf("%3i ", tmp->links);
	if (f->g != 1)
		ft_printf("%s  ", tmp->owner);
	ft_printf("%s ", tmp->group);
	ft_printf("%6i", tmp->fsize);
	ft_printf("%s ", tmp->time);
	ft_printf("%s\n", tmp->name);
}

void		ftls_print_lhidden(t_lsflags *f, t_lslink *l)
{
	t_lslink	*tmp;
	int			total;

	total = 0;
	if ((f->a == 1 || f->d == 1) && (f->l == 1 || f->g == 1))
	{
		tmp = l;
		total = ftls_get_blocktotal(l, f);
		if (f->multi == 0 && f->d == 0 && f->dir == 1)
			ft_printf("total %i\n", total);
		while (tmp)
		{
			if (tmp->name)
				ftls_printing(f, tmp);
			if (f->d == 1)
				break ;
			tmp = tmp->next;
		}
	}
}
