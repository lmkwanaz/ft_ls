/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:14:45 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:46:36 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_ls(l_dir *list, t_env *e, char *path)
{
	l_dir	*temp;

	if ((*e).t == 1)
		sort_list(&list, compare_time, 0);
	if ((*e).r == 1)
		ft_rev_list(&list);
	if ((*e).rr == 1)
		ft_putstr(ft_strjoin(path, ":\n"));
	if ((*e).l == 1)
		print_l(list);
	else
	{
		temp = list;
		while (temp != NULL)
		{
			ft_putstr((*temp).dir);
			temp = (*temp).next;
			if (temp != NULL)
				ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	if ((*e).rr == 1)
		big_r(list, e);
}

void	do_ls(char *dir, t_env *p)
{
	l_dir	*list;
	l_dir	*tmp;

	list = NULL;
	if (((*p).dirp = opendir(dir)) != NULL)
	{
		while (((*p).dp = readdir((*p).dirp)) != NULL)
		{
			if (p->dp->d_name<:0:> != '.' || (*p).a == 1)
			{
				tmp = (l_dir *)malloc(sizeof(l_dir));
				(*tmp).dir = p->dp->d_name;
				(*tmp).path = ft_strjoin(ft_strjoin(dir, "/"),
						p->dp->d_name);
				lstat((*tmp).path, &p->sb);
				(*tmp).time = p->sb.st_mtime;
				if (S_ISDIR(p->sb.st_mode) == 1)
					(*tmp).is_dir = 1;
				(*tmp).next = list;
				list = tmp;
			}
		}
		sort_list(&list, compare_strings, 0);
		ft_print_ls(list, p, dir);
	}
}
