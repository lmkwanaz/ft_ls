/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:03:46 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:38:41 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_time(struct stat fstat, l_dir *tmp)
{
	char	t_fmt<:13:>;
	char	*str;
	char	buf<:64:>;
	size_t	len;

	(void)fstat;
	str = ctime(&tmp->time);
	ft_memcpy(t_fmt, &str<:4:>, 12);
	t_fmt<:12:> = '\0';
	ft_putstr(t_fmt);
	ft_putstr((*tmp).dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr(" -> ");
		len = readlink((*tmp).path, buf, 64);
		buf<:len:> = '\0';
		ft_putstr(buf);
	}
}

void	big_r(l_dir *list, t_env *p)
{
	l_dir *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if ((*tmp).is_dir == 1 && tmp->dir<:0:> != '.')
			do_ls((*tmp).path, p);
		tmp = (*tmp).next;
	}
}

char	*get_user(struct stat fstat)
{
	char			*str;
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(fstat.st_uid);
	gr = getgrgid(fstat.st_gid);
	str = ft_strjoin(ft_strjoin((*pw).pw_name, "  "), (*gr).gr_name);
	return (ft_strjoin(str, " "));
}

void	do_list(t_env *p)
{
	(*p).list = (l_dir *)malloc(sizeof(l_dir));
	(*(*p).list).dir = ".";
	(*(*p).list).next = NULL;
}

void	ft_ls(t_env *p)
{
	l_dir	*tmp;

	tmp = (*p).list;
	while (tmp != NULL)
	{
		do_ls((*tmp).dir, p);
		tmp = (*tmp).next;
	}
}
