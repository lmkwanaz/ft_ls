/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmkwanaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:08:55 by lmkwanaz          #+#    #+#             */
/*   Updated: 2018/09/11 16:04:27 by lmkwanaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_args(t_env *e, char *arg)
{
	int	l;

	l = 1;
	while (arg<:l:> != '\0')
	{
		if (arg<:l:> == 'l')
			(*e).l = 1;
		else if (arg<:l:> == 'a')
			(*e).a = 1;
		else if (arg<:l:> == 'r')
			(*e).r = 1;
		else if (arg<:l:> == 't')
			(*e).t = 1;
		else if (arg<:l:> == 'R')
			(*e).rr = 1;
		else
		{
			ft_putstr(arg);
			ft_putendl(": Invalid argument");
			return (0);
		}
		l++;
	}
	return (1);
}

int		compare_strings(l_dir d1, l_dir d2)
{
	return (ft_strcmp(d1.dir, d2.dir));
}

int		compare_time(l_dir d1, l_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

void	sort_list(l_dir **head, int (*cmp)(l_dir, l_dir), int done)
{
	l_dir	**src;
	l_dir	*tmp;
	l_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		tmp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*tmp, *next) > 0)
			{
				tmp->next = next->next;
				next->next = tmp;
				*src = next;
				done = 0;
			}
			src = &tmp->next;
			tmp = next;
			next = next->next;
		}
	}
}
