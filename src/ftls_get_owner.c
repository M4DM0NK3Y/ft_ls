/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftls_get_owner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:52:38 by cterblan          #+#    #+#             */
/*   Updated: 2018/09/13 15:12:33 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

void	ftls_get_owner(char *path, t_lslink *l)
{
	struct stat		st;
	struct passwd	*pw = NULL;
	char			*fre;

	if (ft_isdir(path))
	{
		stat(fre = ft_strjoin(path, l->name), &st);
		free (fre);
	}
	else if (!(ft_isdir(path)))
		stat(path, &st);
	pw = getpwuid(st.st_uid);
	l->owner = ft_strdup(pw->pw_name);
}