/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:14:16 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:53:26 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l(l_dir *list)
{
	l_dir		*tmp;
	struct stat	fstat;
	char		*bytes;
	int			size;
	int			l;

	tmp = list;
	while (tmp != NULL)
	{
		lstat((*tmp).path, &fstat);
		ft_permission(tmp, fstat);
		ft_putnbr(fstat.st_nlink);
		ft_putstr(" ");
		ft_putstr(get_user(fstat));
		l = 5;
		bytes = ft_itoa(fstat.st_size);
		size = ft_strlen(bytes);
		while (l-- > size)
			ft_putchar(' ');
		ft_putstr(ft_strjoin(bytes, "  "));
		get_time(fstat, tmp);
		tmp = (*tmp).next;
		if (tmp != NULL)
			ft_putchar('\n');
	}
}

void	ft_rev_list(l_dir **head_ref)
{
	l_dir	*prev;
	l_dir	*current;
	l_dir	*next;

	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = (*current).next;
		(*current).next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void	ft_permission(l_dir *tmp, struct stat fstat)
{
	if ((*tmp).is_dir)
		ft_putchar('d');
	else
		ft_putchar((S_ISLNK(fstat.st_mode)) ? 'l' : '-');
	ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IWGRP) ? 'x' : '-');
	ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr(" ");
}
