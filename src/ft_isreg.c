/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isreg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:57:44 by cterblan          #+#    #+#             */
/*   Updated: 2018/09/14 07:14:08 by cterblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

int		ft_isreg(const char *path)
{
	struct stat	st;

	stat(path, &st);
	return (S_ISREG(st.st_mode));
}
