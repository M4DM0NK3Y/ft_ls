/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:39:12 by cterblan          #+#    #+#             */
/*   Updated: 2018/09/07 13:57:35 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		main(int ac, char **av)
{
	int 		i;
	t_lslink	*l = NULL;
	t_lsflags	f;

	i = 1;
	l = (t_lslink *)ft_memalloc(sizeof(t_lslink));
	if (ac == 1)
		ftls_flag_none(".", l);
	else while (i < ac)
	{
		if (av[i] && av[i][0] == '-')
			ftls_flag_set(av[i], &f);
		else if (av[i] && ft_isdir(av[i]))
			ft_quit("ERROR: File not found!"); //ftls_read_dir();
		else
			ft_quit("ERROR: File not found!");
		i++;
	}
}